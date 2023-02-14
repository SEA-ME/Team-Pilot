#include "canclient.h"

CANClient::CANClient(QObject *parent)
    : QObject(parent),
    _humValue(0), _tmpValue(0), _rpmValue(0),
    _spdValue(0), _batValue(0), _disValue(0)
{
    std::cout << "can client initialize" << std::endl;
}

CANClient::~CANClient() {
    std::cout << "can client end" << std::endl;
}

void CANClient::initVsomeipClient() {
    _runtime = CommonAPI::Runtime::get();

    std::string domain = "local";
    std::string instance = "seame";

    _moonProxy = _runtime->buildProxy<SEAMEProxy>(domain, instance);
    std::cout << "Checking availability!" << std::endl;
    while (!_moonProxy->isAvailable()) {
        std::cout << "moonProxy is not available" << std::endl;
        std::this_thread::sleep_for(std::chrono::microseconds(10));
    }
}

void CANClient::initGetValue() {
    std::cout << "start initialize values" << std::endl;
    getHumidity();
    getTemperature();
    getRPM();
    getSpeed();
    getBattery();
    getDistance();
}

void CANClient::subscribeValue() {
    // subscribe service
    std::cout << "subscirbe hum value" << std::endl;
    _moonProxy->getHumAttribute().getChangedEvent().subscribe([&](const int32_t& val) {
        std::cout << "Received change hum message: " << val << std::endl;
        _humValue = val;
    });

    std::cout << "subscirbe tmp value" << std::endl;
    _moonProxy->getTmpAttribute().getChangedEvent().subscribe([&](const int32_t& val) {
        std::cout << "Received change tmp message: " << val << std::endl;
        _tmpValue = val;
    });

    std::cout << "subscirbe rpm value" << std::endl;
    _moonProxy->getRpmAttribute().getChangedEvent().subscribe([&](const int32_t& val) {
        std::cout << "Received change rpm message: " << val << std::endl;
        _rpmValue = val;
    });

    std::cout << "subscirbe spd value" << std::endl;
    _moonProxy->getSpdAttribute().getChangedEvent().subscribe([&](const int32_t& val) {
        std::cout << "Received change spd message: " << val << std::endl;
        _spdValue = val;
    });

    std::cout << "subscirbe bat value" << std::endl;
    _moonProxy->getBatAttribute().getChangedEvent().subscribe([&](const int32_t& val) {
        std::cout << "Received change bat message: " << val << std::endl;
        _batValue = val;
    });

    std::cout << "subscirbe ultrasonic value" << std::endl;
    _moonProxy->getDisAttribute().getChangedEvent().subscribe([&](const int32_t& val) {
        std::cout << "Received change ultrasonic message: " << val << std::endl;
        _disValue= val;
    });
}

void CANClient::startCommunication() {
    initGetValue();
    subscribeValue();
}

void CANClient::getHumidity() {
    // get value from service in _humValue
    _moonProxy->getHumAttribute().getValue(_callStatus, _humValue);

    if (_callStatus != CommonAPI::CallStatus::SUCCESS) {
        std::cerr << "Remote call A failed!" << std::endl;
    } else {
        std::cout << "get humidity value from service: " << _humValue << std::endl;
    }
}

void CANClient::getTemperature() {
    // get value from service in _humValue
    _moonProxy->getTmpAttribute().getValue(_callStatus, _tmpValue);

    if (_callStatus != CommonAPI::CallStatus::SUCCESS) {
        std::cerr << "Remote call A failed!" << std::endl;
    } else {
        std::cout << "get temperature value from service: " << _tmpValue << std::endl;
    }
}

void CANClient::getRPM() {
    // get value from service in _humValue
    _moonProxy->getRpmAttribute().getValue(_callStatus, _rpmValue);

    if (_callStatus != CommonAPI::CallStatus::SUCCESS) {
        std::cerr << "Remote call A failed!" << std::endl;
    } else {
        std::cout << "get RPM value from service: " << _rpmValue << std::endl;
    }
}

void CANClient::getSpeed() {
  _moonProxy->getSpdAttribute().getValue(_callStatus, _spdValue);
  if (_callStatus != CommonAPI::CallStatus::SUCCESS) {
      std::cerr << "Remote call A failed!" << std::endl;
  } else {
    std::cout << "get speed value from service: " << _spdValue << std::endl;
  }
}

void CANClient::getBattery() {
  _moonProxy->getBatAttribute().getValue(_callStatus, _batValue);
  if (_callStatus != CommonAPI::CallStatus::SUCCESS) {
    std::cerr << "Remote call A failed!" << std::endl;
  } else {
    std::cout << "get battery value from service: " << _batValue << std::endl;
  }
}

void CANClient::getDistance() {
  _moonProxy->getDisAttribute().getValue(_callStatus, _disValue);
  if (_callStatus != CommonAPI::CallStatus::SUCCESS) {
    std::cerr << "Remote call A failed!" << std::endl;
  } else {
    std::cout << "get ultrasonic value from service: " << _disValue << std::endl;
  }
}


