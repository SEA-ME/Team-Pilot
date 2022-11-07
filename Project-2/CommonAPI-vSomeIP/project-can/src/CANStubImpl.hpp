// CANStubImpl.hpp
#ifndef CANSTUBIMPL_H_
#define CANSTUBIMPL_H_
#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/CANStubDefault.hpp>

class CANStubImpl: public v1::commonapi::CANStubDefault {
public:
    CANStubImpl();
    virtual ~CANStubImpl();
    virtual void GetHUM(const std::shared_ptr<CommonAPI::ClientId> _client, v1::commonapi::CAN::HUM _hum, GetHUMReply_t _reply);
    virtual void GetTMP(const std::shared_ptr<CommonAPI::ClientId> _client, v1::commonapi::CAN::TMP _tmp, GetTMPReply_t _reply);
    virtual void GetRPM(const std::shared_ptr<CommonAPI::ClientId> _client, v1::commonapi::CAN::RPM _rpm, GetRPMReply_t _reply);
    virtual void GetSPD(const std::shared_ptr<CommonAPI::ClientId> _client, v1::commonapi::CAN::SPD _spd, GetSPDReply_t _reply);
    virtual void GetBAT(const std::shared_ptr<CommonAPI::ClientId> _client, v1::commonapi::CAN::BAT _bat, GetBATReply_t _reply);
};
#endif /* CANSTUBIMPL_H_ */
