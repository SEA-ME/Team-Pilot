#include "ipcstubimpl.h"


#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/IpcStubDefault.hpp>
IpcStubImpl::IpcStubImpl() { }
IpcStubImpl::~IpcStubImpl() { }


void IpcStubImpl::structInMethod(const std::shared_ptr<CommonAPI::ClientId> _client,
v1::commonapi::Ipc::IpcStruct _structParameter, v1::commonapi::IpcStub::structInMethodReply_t _reply)
{
    this->TMP = _structParameter.getTMP();
    this->HUM = _structParameter.getHUM();
    this->RPM = _structParameter.getRPM();
    this->SPD = _structParameter.getSPD();
    this->BAT = _structParameter.getBAT();
    std::cout << "TMP : "<<_structParameter.getTMP()<<" "<< "HUM : "<<_structParameter.getHUM()<<" "<< "RPM : "<<_structParameter.getRPM()<<" "<<
     "SPD : "<<_structParameter.getSPD()<<" "<< "BAT : "<<_structParameter.getBAT()<<std::endl;

    std::int32_t returnData = 1;
    _reply(returnData);
};

std::int32_t IpcStubImpl::getTMP(){
    return TMP;
}
std::int32_t IpcStubImpl::getHUM(){
    return HUM;
}
std::int32_t IpcStubImpl::getRPM(){
    return RPM;
}
std::int32_t IpcStubImpl::getSPD(){
    return SPD;
}
std::int32_t IpcStubImpl::getBAT(){
    return BAT;
}
