// CANStubImpl.cpp
#include "CANStubImpl.hpp"

CANStubImpl::CANStubImpl() { 
  _hum = 0;
  _tmp = 0;
  _rpm = 0;
  _spd = 0;
  _bat = 0;
}

CANStubImpl::~CANStubImpl() {}

void CANStubImpl::humPublisher(uint8_t  canHum) {
  if (_hum != canHum) {
    _hum = canHum;
    setHumAttribute(_hum);
    std::cout <<  "New CAN Humadity Data = " << _hum << "!" << std::endl;
  }
}

void CANStubImpl::tmpPublisher(int8_t   canTmp) {
  if (_tmp != canTmp) {
    _tmp = canTmp;
    setTmpAttribute(_tmp);
    std::cout <<  "New CAN Temperature Data = " << _tmp << "!" << std::endl;
  }
}

void CANStubImpl::rpmPublisher(uint16_t canRpm) {
  if (_rpm != canRpm) {
    _rpm = canRpm;
    setRpmAttribute(_rpm);
    std::cout <<  "New CAN RPM Data = " << _rpm << "!" << std::endl;
  }
}

void CANStubImpl::spdPublisher(uint8_t  canSpd) {
  if (_spd != canSpd) {
    _spd = canSpd;
    setSpdAttribute(_spd);
    std::cout <<  "New CAN Speed Data = " << _spd << "!" << std::endl;
  }
}

void CANStubImpl::batPublisher(uint8_t  canBat) {
  // if (_bat != canBat) {
  //   _bat = canBat;
  //   setBatAttribute(_bat);
  //   std::cout <<  "New CAN Battery Data  = " << _bat << "!" << std::endl;
  // }
  _bat = canBat;
  setBatAttribute(canBat);
}
