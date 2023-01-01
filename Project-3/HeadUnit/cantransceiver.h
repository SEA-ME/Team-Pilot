#ifndef CANTRANSCEIVER_H
#define CANTRANSCEIVER_H

#include <QObject>
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
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include "defs.h"
#include "ina219.h"
#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/HeadUnitProxy.hpp>
#include <v1/commonapi/HeadUnitProxyBase.hpp>

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

class CanTransceiver : public QObject
{
    Q_OBJECT
public:
    explicit CanTransceiver(QObject *parent = 0);
    CanTransceiver();

    // CAN func()
    int initSocket(const char *ifname);
    void readSocket();

    // Battery func()
    void initBattery();
    void readBattery();

    // CommonAPI vSomeIP func()
    void initVsomeipClient();
    void sendToVsomeipService();
    void startCommunicate();

private:
    // CAN var
    int can_fd;
    struct can_frame frame;
    int rd_byte;

    // Battery var
    bool ina_status;
    INA219 *ina219;
    INA219ChargeStatus charge_status;
    int mV;
    int percent_charged;
    int battery_current_mA;
    int minutes;

    // RPM
    uint16_t rpm_combine;

    // CommonAPI vSomeIP var
    std::shared_ptr < CommonAPI::Runtime > runtime;
    std::shared_ptr<HeadUnitProxy<>> moonProxy;
    CommonAPI::CallStatus callStatus;
    HeadUnit::HUM hum;
    HeadUnit::TMP tmp;
    HeadUnit::RPM rpm;
    HeadUnit::SPD spd;
    HeadUnit::BAT bat;
    HeadUnit::PRND prnd;
};

#endif // CANTRANSCEIVER_H
