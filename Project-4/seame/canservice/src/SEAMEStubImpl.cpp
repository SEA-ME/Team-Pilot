// SEAMEStubImpl.cpp
#include "SEAMEStubImpl.hpp"

SEAMEStubImpl::SEAMEStubImpl() { 
  m_hum = 0;
  m_tmp = 0;
  m_rpm = 0;
  m_spd = 0;
  m_bat = 0;
  m_dis = 0;
}

SEAMEStubImpl::~SEAMEStubImpl() {}

void SEAMEStubImpl::humPublisher(const uint8_t  canHum) {
  if (m_hum != canHum) {
    m_hum = canHum;
    setHumAttribute(m_hum);
    std::cout <<  "New CAN Humadity Data = " << int(m_hum) << "!" << std::endl;
  }
}

void SEAMEStubImpl::tmpPublisher(const int8_t   canTmp) {
  if (m_tmp != canTmp) {
    m_tmp = canTmp;
    setTmpAttribute(m_tmp);
    std::cout <<  "New CAN Temperature Data = " << int(m_tmp) << "!" << std::endl;
  }
}

void SEAMEStubImpl::rpmPublisher(const uint16_t canRpm) {
  if (m_rpm != canRpm) {
    m_rpm = canRpm;
    setRpmAttribute(m_rpm);
    std::cout <<  "New CAN RPM Data = " << int(m_rpm) << "!" << std::endl;
  }
}

void SEAMEStubImpl::spdPublisher(const uint8_t  canSpd) {
  if (m_spd != canSpd) {
    m_spd = canSpd;
    setSpdAttribute(m_spd);
    std::cout <<  "New CAN Speed Data = " << int(m_spd) << "!" << std::endl;
  }
}

void SEAMEStubImpl::batPublisher(const uint8_t  canBat) {
  if ((m_bat <= canBat + 1) && (m_bat >= canBat -1)) {
    //std::cout << "error range" << std::endl;
  } else {
    m_bat = canBat;
    setBatAttribute(m_bat);
    std::cout <<  "New CAN Battery Data  = " << int(m_bat) << "!" << std::endl;
  }
}

void SEAMEStubImpl::disPublisher(const uint8_t  canDis) {
  if (m_dis != canDis) {
    m_dis = canDis;
    setDisAttribute(m_dis);
    std::cout << "New CAN Distane Data = " << int(m_dis) << "!" << std::endl;
  }
}
