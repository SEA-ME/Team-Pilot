#ifndef CANCLIENT_H
#define CANCLIENT_H

#include <QObject>
#include <iostream>
#include <string>
#include <thread>
#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/CANProxy.hpp>
#include <v1/commonapi/CANProxyBase.hpp>

using namespace v1::commonapi;

class CANClient : public QObject
{
    Q_OBJECT
    Q_PROPERTY(uint8_t humidity READ humidity NOTIFY humidityChanged)
    Q_PROPERTY(int8_t temperature READ temperature NOTIFY temperatureChanged)
    Q_PROPERTY(uint16_t rpm READ rpm NOTIFY rpmChanged)
    Q_PROPERTY(uint8_t speed READ speed NOTIFY speedChanged)
    Q_PROPERTY(uint8_t battery READ battery NOTIFY batteryChanged)
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

    uint8_t humidity() const;
    int8_t temperature() const;
    uint16_t rpm() const;
    uint8_t speed() const;
    uint8_t battery() const;

signals:
    void humidityChanged();
    void temperatureChanged();
    void rpmChanged();
    void speedChanged();
    void batteryChanged();

private:
    std::shared_ptr<CommonAPI::Runtime> m_runtime;
    std::shared_ptr<CANProxy<>> m_moonProxy;
    CommonAPI::CallStatus m_callStatus;

    uint8_t  m_humValue;
    int8_t   m_tmpValue;
    uint16_t m_rpmValue;
    uint8_t  m_spdValue;
    uint8_t  m_batValue;
};

#endif // CANCLIENT_H
