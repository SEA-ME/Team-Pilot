#include "cantransceiver.h"
#include <QTimer>
#include <iostream>
#include <string>
#include <unistd.h>

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

struct Data {
    int hum;
    int tmp;
    int rpm;
    int spd;
    int bat;
    int prnd;
};

CanTransceiver::CanTransceiver(QObject *parent)
    : QObject(parent), ina219(NULL), ipcData(new struct Data),
      canTimer(std::make_shared<QTimer>()),
      batteryTimer(std::make_shared<QTimer>()) {
    connect(canTimer.get(), SIGNAL(timeout()), this, SLOT(readSocket()));
    connect(batteryTimer.get(), SIGNAL(timeout()), this, SLOT(readBattery()));
}

void CanTransceiver::initSocket(const char *ifname) {
    can_fd = socket(PF_CAN, SOCK_RAW, CAN_RAW);
    if (can_fd < 0)
        printf("Failed to socket create\n", can_fd);
    printf("Success to socket create\n");

    struct ifreq ifr;
    strcpy(ifr.ifr_name, ifname);
    int ret = ioctl(can_fd, SIOCGIFINDEX, &ifr);
    if (ret < 0)
        printf("Failed to get CAN interface index\n", ret);
    printf("%sSuccess to get CAN interface index : %d%s\n", ret);

    struct sockaddr_can addr;
    addr.can_family = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;
    ret = bind(can_fd, (struct sockaddr *)&addr, sizeof(addr));
    if (ret < 0)
        printf("Failed to socket bind\n", ret);
    printf("Success to socket bind\n");
}

void CanTransceiver::readSocket() {
    rd_byte = read(can_fd, &frame, sizeof(frame));
    if (rd_byte < 0)
        printf("Failed to recieve CAN frame\n", rd_byte);
    else if (rd_byte < (int)sizeof(struct can_frame))
        printf("Incomplete CAN frame is received\n", rd_byte, rd_byte);
    else if (frame.can_dlc > CAN_MAX_DLEN)
        printf("Invalid dlc\n", -1, frame.can_dlc);

    // unsigned char -> uint16_t
    rpm_combine = frame.data[2] | uint16_t(frame.data[3]) << 8;

    if (ipcData->hum != frame.data[0] || ipcData->tmp != frame.data[1]) {
        ipcData->hum = frame.data[0];
        ipcData->tmp = frame.data[1];
        moonProxy->GetHUM(frame.data[0], callStatus, hum);
        moonProxy->GetTMP(frame.data[1], callStatus, tmp);
    }

    if (ipcData->rpm != rpm_combine || ipcData->spd != frame.data[4]) {
        ipcData->rpm = rpm_combine;
        ipcData->spd = frame.data[4];
        moonProxy->GetRPM(rpm_combine, callStatus, rpm);
        moonProxy->GetSPD(frame.data[4], callStatus, spd);
    }
}

void CanTransceiver::initBattery() {
    ina219 = ina219_create (I2C_DEV, I2C_ADDR, SHUNT_MILLIOHMS,
                         BATTERY_VOLTAGE_0_PERCENT, BATTERY_VOLTAGE_100_PERCENT,
                         BATTERY_CAPACITY, MIN_CHARGING_CURRENT);

    char *error = NULL;
    ina_status = false;
    if (ina219_init (ina219, &error))
        ina_status = true;
}

void CanTransceiver::readBattery() {
    INA219ChargeStatus charge_status;
    char *error = NULL;
    if (ina_status){
        if (ina219_get_status (ina219, &charge_status, &mV, &percent_charged, &battery_current_mA, &minutes, &error)){
            /*
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
            */
            if (ipcData->bat != percent_charged) {
                ipcData->bat = percent_charged;
                moonProxy->GetBAT(ipcData->bat, callStatus, bat);
            }
        }
    }
}

void CanTransceiver::initVsomeipClient() {
    runtime = CommonAPI::Runtime::get();
    moonProxy = runtime->buildProxy<HeadUnitProxy>("local", "headunit");
    std::cout << "Checking availability!" << std::endl;
    while (!moonProxy->isAvailable())
        usleep(10);
    std::cout << "Available..." << std::endl;
    usleep(1000);
}

void CanTransceiver::startCommunicate() {
    initBattery();
    canTimer->start(1);
    batteryTimer->start(50);
}

void CanTransceiver::canSlot(const int &msg) {
    if (ipcData->prnd != msg){
        ipcData->prnd = msg;
        moonProxy->GetPRND(msg, callStatus, prnd);
    }
}

CanTransceiver::~CanTransceiver() {
    close(can_fd);
}
