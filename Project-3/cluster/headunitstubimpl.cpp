// HeadUnitStubImpl.cpp
#include "headunitstubimpl.h"

HeadUnitStubImpl::HeadUnitStubImpl() {}
HeadUnitStubImpl::~HeadUnitStubImpl() {}

void HeadUnitStubImpl::GetHUM(const std::shared_ptr<CommonAPI::ClientId> _client, v1::commonapi::HeadUnit::HUM _hum, v1::commonapi::HeadUnitStub::GetHUMReply_t _reply)
{
    this->HeadUnitHum = _hum;
    std::cout << "HUM " << unsigned(_hum) << " ";
    v1::commonapi::HeadUnit::HUM returnData = _hum;
    _reply(returnData);
};
void HeadUnitStubImpl::GetTMP(const std::shared_ptr<CommonAPI::ClientId> _client, v1::commonapi::HeadUnit::TMP _tmp, v1::commonapi::HeadUnitStub::GetTMPReply_t _reply){
    this->HeadUnitTmp = _tmp;
    std::cout << "TMP: " << signed(_tmp) << " " << std::endl;
    v1::commonapi::HeadUnit::TMP returnData = _tmp;
    _reply(returnData);
};
void HeadUnitStubImpl::GetRPM(const std::shared_ptr<CommonAPI::ClientId> _client, v1::commonapi::HeadUnit::RPM _rpm, v1::commonapi::HeadUnitStub::GetRPMReply_t _reply){
    this->HeadUnitRpm = _rpm;
    std::cout << "RPM: " << _rpm << " ";
    v1::commonapi::HeadUnit::RPM returnData = _rpm;
    _reply(returnData);
};
void HeadUnitStubImpl::GetSPD(const std::shared_ptr<CommonAPI::ClientId> _client, v1::commonapi::HeadUnit::SPD _spd, v1::commonapi::HeadUnitStub::GetSPDReply_t _reply){
    this->HeadUnitSpd = _spd;
    std::cout << "SPD: " << unsigned(_spd) << " " << std::endl;
    v1::commonapi::HeadUnit::SPD returnData = _spd;
    _reply(returnData);
};
void HeadUnitStubImpl::GetBAT(const std::shared_ptr<CommonAPI::ClientId> _client, v1::commonapi::HeadUnit::BAT _bat, v1::commonapi::HeadUnitStub::GetBATReply_t _reply){
    this->HeadUnitBat = _bat;
    std::cout << "BAT: " << int(_bat) << " " << std::endl;
    v1::commonapi::HeadUnit::BAT returnData = _bat;
    _reply(returnData);
};
void HeadUnitStubImpl::GetPRND(const std::shared_ptr<CommonAPI::ClientId> _client, v1::commonapi::HeadUnit::PRND _prnd, GetPRNDReply_t _reply){
    this->HeadUnitPrnd = _prnd;
    std::cout << "PRND: " << int(_prnd) << std::endl;
    v1::commonapi::HeadUnit::PRND returnData = _prnd;
    _reply(returnData);
};
std::uint8_t HeadUnitStubImpl::qt_HUM(){
    return HeadUnitHum;
}
std::int8_t HeadUnitStubImpl::qt_TMP(){
    return HeadUnitTmp;
}
std::uint16_t HeadUnitStubImpl::qt_RPM(){
    return HeadUnitRpm;
}
std::uint8_t HeadUnitStubImpl::qt_SPD(){
    return HeadUnitSpd;
}
std::uint8_t HeadUnitStubImpl::qt_BAT(){
    return HeadUnitBat;
}
std::uint8_t HeadUnitStubImpl::qt_PRND(){
    return HeadUnitPrnd;
}
