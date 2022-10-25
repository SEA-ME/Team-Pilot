// CANStubImpl.cpp
#include "CANStubImpl.hpp"

CANStubImpl::CANStubImpl() { }
CANStubImpl::~CANStubImpl() { }

void CANStubImpl::GetHUM(const std::shared_ptr<CommonAPI::ClientId> _client, v1::commonapi::CAN::HUM _hum, v1::commonapi::CANStub::GetHUMReply_t _reply){
    std::cout << "HUM: " << unsigned(_hum) << " ";
    v1::commonapi::CAN::HUM returnData = _hum;
    _reply(returnData);   
};
void CANStubImpl::GetTMP(const std::shared_ptr<CommonAPI::ClientId> _client, v1::commonapi::CAN::TMP _tmp, v1::commonapi::CANStub::GetTMPReply_t _reply){
    std::cout << "TMP: " << signed(_tmp) << " ";
    v1::commonapi::CAN::TMP returnData = _tmp;
    _reply(returnData);   
};
void CANStubImpl::GetRPM(const std::shared_ptr<CommonAPI::ClientId> _client, v1::commonapi::CAN::RPM _rpm, v1::commonapi::CANStub::GetRPMReply_t _reply){
    std::cout << "RPM: " << _rpm << " ";
    v1::commonapi::CAN::RPM returnData = _rpm;
    _reply(returnData);   
};
void CANStubImpl::GetSPD(const std::shared_ptr<CommonAPI::ClientId> _client, v1::commonapi::CAN::SPD _spd, v1::commonapi::CANStub::GetSPDReply_t _reply){
    std::cout << "SPD: " << unsigned(_spd) << " ";
    v1::commonapi::CAN::SPD returnData = _spd;
    _reply(returnData);   
};
void CANStubImpl::GetBAT(const std::shared_ptr<CommonAPI::ClientId> _client, v1::commonapi::CAN::BAT _bat, v1::commonapi::CANStub::GetBATReply_t _reply){
    std::cout << "BAT: " << _bat << " " << std::endl;
    v1::commonapi::CAN::BAT returnData = _bat;
    _reply(returnData);   
};
