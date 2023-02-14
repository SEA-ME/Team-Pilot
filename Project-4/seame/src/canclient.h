#ifndef CANCLIENT_H
#define CANCLIENT_H

#include <QObject>
#include <iostream>
#include <string>
#include <thread>
#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/SEAMEProxy.hpp>
#include <v1/commonapi/SEAMEProxyBase.hpp>

using namespace v1::commonapi;

class CANClient : public QObject
{
    Q_OBJECT
public:
    explicit CANClient(QObject *parent = nullptr);
    ~CANClient();

    void initVsomeipClient();
    void initGetValue();
    void subscribeValue();
    void startCommunication();

    void getHumidity();
    void getTemperature();
    void getRPM();
    void getSpeed();
    void getBattery();
    void getDistance();

    void setHumidity();
    void setTemperature();
    void setRPM();
    void setSpeed();
    void setBattery();
    void setDistance();

private:
    std::shared_ptr<CommonAPI::Runtime> _runtime;
    std::shared_ptr<SEAMEProxy<>> _moonProxy;
    CommonAPI::CallStatus _callStatus;

    uint8_t  _humValue;
    int8_t   _tmpValue;
    uint16_t _rpmValue;
    uint8_t  _spdValue;
    uint8_t  _batValue;
    uint8_t  _disValue;
};

#endif // CANCLIENT_H
