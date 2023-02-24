// SEAMEStubImpl.hpp
#ifndef SEAMESTUBIMPL_H_
#define SEAMESTUBIMPL_H_
#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/SEAMEStubDefault.hpp>

class SEAMEStubImpl: public v1::commonapi::SEAMEStubDefault {
public:
  SEAMEStubImpl();
  virtual ~SEAMEStubImpl();
  virtual void humPublisher(const uint8_t  canHum);
  virtual void tmpPublisher(const int8_t   canTmp);
  virtual void rpmPublisher(const uint16_t canRpm);
  virtual void spdPublisher(const uint8_t  canSpd);
  virtual void batPublisher(const uint8_t  canBat);
  virtual void disPublisher(const uint8_t  canDis);

private:
  uint8_t  m_hum;
  int8_t   m_tmp;
  uint16_t m_rpm;
  uint8_t  m_spd;
  uint8_t  m_bat;
  uint8_t  m_dis;
};
#endif /* SEAMESTUBIMPL_H_ */
