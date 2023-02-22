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
    Q_PROPERTY(uint8_t humidity READ humidity NOTIFY humidityChanged)
    Q_PROPERTY(int8_t temperature READ temperature NOTIFY temperatureChanged)
    Q_PROPERTY(uint16_t rpm READ rpm NOTIFY rpmChanged)
    Q_PROPERTY(uint8_t speed READ speed NOTIFY speedChanged)
    Q_PROPERTY(uint8_t battery READ battery NOTIFY batteryChanged)
    Q_PROPERTY(uint8_t distance READ distance NOTIFY distanceChanged)
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

    uint8_t humidity() const;
    int8_t temperature() const;
    uint16_t rpm() const;
    uint8_t speed() const;
    uint8_t battery() const;
    uint8_t distance() const;

signals:
    void humidityChanged();
    void temperatureChanged();
    void rpmChanged();
    void speedChanged();
    void batteryChanged();
    void distanceChanged();

private:
    std::shared_ptr<CommonAPI::Runtime> m_runtime;
    std::shared_ptr<SEAMEProxy<>> m_moonProxy;
    CommonAPI::CallStatus m_callStatus;

    uint8_t  m_humValue;
    int8_t   m_tmpValue;
    uint16_t m_rpmValue;
    uint8_t  m_spdValue;
    uint8_t  m_batValue;
    uint8_t  m_disValue;
};

#endif // CANCLIENT_H
