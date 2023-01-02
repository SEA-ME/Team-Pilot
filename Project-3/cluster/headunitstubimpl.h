//HeadUnitStubImpl.hpp
#ifndef HEADUNITSTUBIMPL_H_
#define HEADUNITSTUBIMPL_H_
#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/HeadUnitStubDefault.hpp>

class HeadUnitStubImpl: public v1::commonapi::HeadUnitStubDefault {
public:
    HeadUnitStubImpl();
    virtual ~HeadUnitStubImpl();
    virtual void GetHUM(const std::shared_ptr<CommonAPI::ClientId> _client, v1::commonapi::HeadUnit::HUM _hum, GetHUMReply_t _reply);
    virtual void GetTMP(const std::shared_ptr<CommonAPI::ClientId> _client, v1::commonapi::HeadUnit::TMP _tmp, GetTMPReply_t _reply);
    virtual void GetRPM(const std::shared_ptr<CommonAPI::ClientId> _client, v1::commonapi::HeadUnit::RPM _rpm, GetRPMReply_t _reply);
    virtual void GetSPD(const std::shared_ptr<CommonAPI::ClientId> _client, v1::commonapi::HeadUnit::SPD _spd, GetSPDReply_t _reply);
    virtual void GetBAT(const std::shared_ptr<CommonAPI::ClientId> _client, v1::commonapi::HeadUnit::BAT _bat, GetBATReply_t _reply);
    virtual void GetPRND(const std::shared_ptr<CommonAPI::ClientId> _client, v1::commonapi::HeadUnit::PRND _prnd, GetPRNDReply_t _reply);
    std::uint8_t qt_HUM();
    std::int8_t qt_TMP();
    std::uint16_t qt_RPM();
    std::uint8_t qt_SPD();
    std::uint8_t qt_BAT();
    std::uint8_t qt_PRND();
private:
    v1::commonapi::HeadUnit::HUM HeadUnitHum;
    v1::commonapi::HeadUnit::TMP HeadUnitTmp;
    v1::commonapi::HeadUnit::RPM HeadUnitRpm;
    v1::commonapi::HeadUnit::SPD HeadUnitSpd;
    v1::commonapi::HeadUnit::BAT HeadUnitBat;
    v1::commonapi::HeadUnit::PRND HeadUnitPrnd;
};

#endif /* HEADUNITSTUBIMPL_H_ */
