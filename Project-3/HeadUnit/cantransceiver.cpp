#include "cantransceiver.h"

CanTransceiver::CanTransceiver()
{

}

CanTransceiver::initSocket(const char *ifname) {
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

CanTransceiver::readSocket() {
    rd_byte = read(can_fd, &frame, sizeof(frame));
    if (rd_byte < 0)
        printf("Failed to recieve CAN frame\n", rd_byte);
    else if (rd_byte < (int)sizeof(struct can_frame))
        printf("Incomplete CAN frame is received\n", rd_byte, rd_byte);
    else if (frame.can_dlc > CAN_MAX_DLEN)
        printf("Invalid dlc\n", -1, frame.can_dlc);

    printf("0x%03X [%d] ", frame.can_id, frame.can_dlc);

    // unsigned char -> uint16_t
    rpm_combine = frame.data[2] | uint16_t(frame.data[3]) << 8;
}

CanTransceiver::initBattery() {
    ina219 = ina219_create (I2C_DEV, I2C_ADDR, SHUNT_MILLIOHMS,
                         BATTERY_VOLTAGE_0_PERCENT, BATTERY_VOLTAGE_100_PERCENT,
                         BATTERY_CAPACITY, MIN_CHARGING_CURRENT);

    char *error = NULL;
    ina_status = false;
    if (ina219_init (ina219, &error))
        ina_status = true;
}

CanTransceiver::readBattery() {
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
            frame.data[5] = percent_charged;
        }
    }
}

CanTransceiver::initVsomeipClient() {
    runtime = CommonAPI::Runtime::get();
    moonProxy = runtime->buildProxy<HeadUnitProxy>("local", "headunit");
    std::cout << "Checking availability!" << std::endl;
    while (!moonProxy->isAvailable())
        usleep(10);
    std::cout << "Available..." << std::endl;
    usleep(1000);
}

CanTransceiver::sendToVsomeipService() {
    moonProxy->GetHUM(frame.data[0], callStatus, hum);
    moonProxy->GetTMP(frame.data[1], callStatus, tmp);
    moonProxy->GetRPM(rpm_combine, callStatus, rpm);
    moonProxy->GetSPD(frame.data[4], callStatus, spd);
    moonProxy->GetBAT(frame.data[5], callStatus, bat);
    moonProxy->GetPRND(1, callStatus, prnd);
}

CanTransceiver::startCommunicate() {
    initBattery();

}
