// CANStubImpl.hpp
#ifndef CANSTUBIMPL_H_
#define CANSTUBIMPL_H_
#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/CANStubDefault.hpp>

class CANStubImpl: public v1::commonapi::CANStubDefault {
public:
  CANStubImpl();
   ~CANStubImpl();
  void humPublisher(uint8_t  canHum);
  void tmpPublisher(int8_t   canTmp);
  void rpmPublisher(uint16_t canRpm);
  void spdPublisher(uint8_t  canSpd);
  void batPublisher(uint8_t  canBat);

private:
  uint8_t  _hum;
  int8_t   _tmp;
  uint16_t _rpm;
  uint8_t  _spd;
  uint8_t  _bat;
};
#endif /* CANSTUBIMPL_H_ */
