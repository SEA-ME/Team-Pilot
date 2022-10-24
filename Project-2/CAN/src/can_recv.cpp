// CANClient.cpp
#include <iostream>
#include <string>
#include <unistd.h>
#include <linux/can.h>
#include <linux/can/raw.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <errno.h>
#include <string.h>
#include <stdint.h>
#include <stdio.h>

// CAN definition
# define CAN_FRAME_MAX_LEN 8

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

int main(){

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
	}

    return 0;
}