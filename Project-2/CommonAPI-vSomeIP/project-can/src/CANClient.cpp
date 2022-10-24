// CANClient.cpp
#include <iostream>
#include <string>
#include <unistd.h>
#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/CANProxy.hpp>
#include <linux/can.h>
#include <linux/can/raw.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <errno.h>
#include <string.h>
#include <stdint.h>
#include <stdio.h>

#include <stdlib.h>
#include <time.h>
#include <sys/time.h>


#include "defs.h" 
#include "ina219.h" 


// Ina219 definition
#define I2C_ADDR 0x42
#define I2C_DEV "/dev/i2c-1"
#define BATTERY_VOLTAGE_100_PERCENT 8260
#define BATTERY_VOLTAGE_0_PERCENT 6000 
#define BATTERY_CAPACITY 2400
#define MIN_CHARGING_CURRENT 10
#define SHUNT_MILLIOHMS 100

// CAN definition
# define CAN_FRAME_MAX_LEN 8

// CommonAPI definition
using namespace v1::commonapi;

int InitSocket(const char *ifname){
	int sock_fd = socket(PF_CAN, SOCK_RAW, CAN_RAW);
	if (sock_fd < 0)
		printf("Failed to socket create\n", sock_fd);
	printf("Success to socket create\n");

	struct ifreq ifr;
	strcpy(ifr.ifr_name, ifname);
	int ret = ioctl(sock_fd, SIOCGIFINDEX, &ifr);
	if (ret < 0)
		printf("Failed to get CAN interface index\n", ret);
	printf("%sSuccess to get CAN interface index : %d%s\n", ret);

	struct sockaddr_can addr;
	addr.can_family = AF_CAN;
	addr.can_ifindex = ifr.ifr_ifindex;
	ret = bind(sock_fd, (struct sockaddr *)&addr, sizeof(addr));
	if (ret < 0)
		printf("Failed to socket bind\n", ret);
	printf("Success to socket bind\n");
	
	return sock_fd;
}

int getBattery(){
	INA219 *ina219 = ina219_create (I2C_DEV, I2C_ADDR, SHUNT_MILLIOHMS,
                     BATTERY_VOLTAGE_0_PERCENT, BATTERY_VOLTAGE_100_PERCENT,
                     BATTERY_CAPACITY, MIN_CHARGING_CURRENT);
	
	char *error = NULL;
	if (ina219_init (ina219, &error)){
		INA219ChargeStatus charge_status;
		int mV;
		int percent_charged;
		int battery_current_mA;
		int minutes;
		if (ina219_get_status (ina219, &charge_status, &mV, &percent_charged, &battery_current_mA, &minutes, &error)){
			switch (charge_status){
				case INA219_FULLY_CHARGED:
					printf("Fully charged\n");
					break;
				case INA219_CHARGING:
					printf("Charging, %d minutes until fully charged\n", minutes);
					break;
				case INA219_DISCHARGING:
					printf("Discharging, %d minutes left\n", minutes);
					break;
			}
			printf ("Battery voltage: %.2f V\n", mV / 1000.0); // Convert to V
      		printf ("Battery current: %d mA\n", battery_current_mA); 
      		printf ("Battery charge: %.d %%\n", percent_charged); 
			return percent_charged;
		}
	}
	return 0;
}

int main(){

	// CommonAPI vSomeIP
	std::shared_ptr < CommonAPI::Runtime > runtime = CommonAPI::Runtime::get();
    std::shared_ptr<CANProxy<>> myProxy =
    runtime->buildProxy<CANProxy>("local", "can");

    std::cout << "Checking availability!" << std::endl;
    while (!myProxy->isAvailable())
        usleep(10);
    std::cout << "Available..." << std::endl;
	usleep(1000);

    CommonAPI::CallStatus callStatus;
    std::int32_t outputData;
	CAN::canStruct canStruct;

	// CAN
    int can_fd = InitSocket("can1");
	if (can_fd < 0)
		return can_fd;
	
	struct can_frame frame;

	while (1)
	{
		// CAN
		int rd_byte = read(can_fd, &frame, sizeof(frame));
		if (rd_byte < 0)
			printf("Failed to recieve CAN frame\n", rd_byte);
		else if (rd_byte < (int)sizeof(struct can_frame))
			printf("Incomplete CAN frame is received\n", rd_byte, rd_byte);
		else if (frame.can_dlc > CAN_MAX_DLEN)
			printf("Invalid dlc\n", -1, frame.can_dlc);

		printf("0x%03X [%d] ",frame.can_id, frame.can_dlc);

		for (int i = 0; i < frame.can_dlc; i++)
			printf("%02X ",frame.data[i]);
		printf("\n");

		int battery_level = getBattery();
		std::cout << battery_level << "%" << std::endl;
		
    	canStruct.setId1("HUM");
    	canStruct.setCode1(frame.data[0]);
		canStruct.setId2("TMP");
    	canStruct.setCode2(frame.data[1]);
		canStruct.setId3("RPM");
    	canStruct.setCode3(frame.data[2]);
		canStruct.setId4("SPD");
    	canStruct.setCode4(frame.data[3]);
		canStruct.setId5("BAT");
    	canStruct.setCode5(battery_level);

    	myProxy->structInMethod(canStruct,callStatus,outputData);
    	std::cout << "Client Log!!  outputData:" << outputData << std::endl;
    	usleep(1000);
	}

    return 0;
}