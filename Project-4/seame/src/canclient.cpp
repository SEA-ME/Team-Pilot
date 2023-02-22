#include "canclient.h"

CANClient::CANClient(QObject *parent)
    : QObject(parent),
    m_humValue(0), m_tmpValue(0), m_rpmValue(0),
    m_spdValue(0), m_batValue(0), m_disValue(0)
{
    std::cout << "can client initialize" << std::endl;
    qRegisterMetaType<uint8_t>("uint8_t");
    qRegisterMetaType<int8_t>("int8_t");
    qRegisterMetaType<uint16_t>("uint16_t");
}

CANClient::~CANClient()
{
    std::cout << "can client end" << std::endl;
}

void CANClient::initVsomeipClient()
{
    m_runtime = CommonAPI::Runtime::get();

    std::string domain = "local";
    std::string instance = "seame";

    m_moonProxy = m_runtime->buildProxy<SEAMEProxy>(domain, instance);
    std::cout << "Checking availability!" << std::endl;
    while (!m_moonProxy->isAvailable()) {
        std::cout << "moonProxy is not available" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
}

void CANClient::initGetValue()
{
    std::cout << "start initialize values" << std::endl;
    if (m_callStatus != CommonAPI::CallStatus::SUCCESS) {
        std::cerr << "Remote call A failed!" << std::endl;
    } else {
        getHumidity();
        getTemperature();
        getRPM();
        getSpeed();
        getBattery();
        getDistance();
    }
}

void CANClient::subscribeValue()
{
    // subscribe service
    std::cout << "subscirbe hum value" << std::endl;
    m_moonProxy->getHumAttribute().getChangedEvent().subscribe([&](const uint8_t& humVal) {
//        std::cout << "Received change hum message: " << int(humVal) << std::endl;
        m_humValue = humVal;
        emit humidityChanged();
    });

    std::cout << "subscirbe tmp value" << std::endl;
    m_moonProxy->getTmpAttribute().getChangedEvent().subscribe([&](const uint8_t& tmpVal) {
//        std::cout << "Received change tmp message: " << int(tmpVal) << std::endl;
        m_tmpValue = tmpVal;
        emit temperatureChanged();
    });

    std::cout << "subscirbe rpm value" << std::endl;
    m_moonProxy->getRpmAttribute().getChangedEvent().subscribe([&](const uint8_t& rpmVal) {
//        std::cout << "Received change rpm message: " << int(rpmVal) << std::endl;
        m_rpmValue = rpmVal;
        emit rpmChanged();
    });

    std::cout << "subscirbe spd value" << std::endl;
    m_moonProxy->getSpdAttribute().getChangedEvent().subscribe([&](const uint8_t& spdVal) {
//        std::cout << "Received change spd message: " << int(spdVal) << std::endl;
        m_spdValue = spdVal;
        emit speedChanged();
    });

    std::cout << "subscirbe bat value" << std::endl;
    m_moonProxy->getBatAttribute().getChangedEvent().subscribe([&](const uint8_t& batVal) {
        std::cout << "Received change bat message: " << int(batVal) << std::endl;
        m_batValue = batVal;
        emit batteryChanged();
    });

    std::cout << "subscirbe ultrasonic value" << std::endl;
    m_moonProxy->getDisAttribute().getChangedEvent().subscribe([&](const uint& disVal) {
//        std::cout << "Received change ultrasonic message: " << int(disVal) << std::endl;
        m_disValue = disVal;
        emit distanceChanged();
    });
}

void CANClient::startCommunication()
{
    initGetValue();
    subscribeValue();
}

void CANClient::getHumidity()
{
    // get value from service in _humValue
    m_moonProxy->getHumAttribute().getValue(m_callStatus, m_humValue);
    std::cout << "get humidity value from service: " << int(m_humValue) << std::endl;
}

void CANClient::getTemperature()
{
    m_moonProxy->getTmpAttribute().getValue(m_callStatus, m_tmpValue);
    std::cout << "get temperature value from service: " << int(m_tmpValue) << std::endl;

}

void CANClient::getRPM()
{
    m_moonProxy->getRpmAttribute().getValue(m_callStatus, m_rpmValue);
    std::cout << "get RPM value from service: " << int(m_rpmValue) << std::endl;
}

void CANClient::getSpeed()
{
    m_moonProxy->getSpdAttribute().getValue(m_callStatus, m_spdValue);
    std::cout << "get speed value from service: " << int(m_spdValue) << std::endl;

}

void CANClient::getBattery()
{
    m_moonProxy->getBatAttribute().getValue(m_callStatus, m_batValue);
    std::cout << "get battery value from service: " << int(m_batValue) << std::endl;
}

void CANClient::getDistance()
{
    m_moonProxy->getDisAttribute().getValue(m_callStatus, m_disValue);
    std::cout << "get ultrasonic value from service: " << int(m_disValue) << std::endl;
}

uint8_t CANClient::humidity() const
{
    return m_humValue;
}

int8_t CANClient::temperature() const
{
    return m_tmpValue;
}

uint16_t CANClient::rpm() const
{
    return m_rpmValue;
}

uint8_t CANClient::speed() const
{
    return m_spdValue;
}

uint8_t CANClient::battery() const
{
    return m_batValue;
}

uint8_t CANClient::distance() const
{
    return m_disValue;
}

