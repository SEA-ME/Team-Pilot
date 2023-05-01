// IpcStubImpl.cpp
#include "IpcStubImpl.hpp"

IpcStubImpl::IpcStubImpl() { }
IpcStubImpl::~IpcStubImpl() { }


void IpcStubImpl::structInMethod(const std::shared_ptr<CommonAPI::ClientId> _client, 
v1::commonapi::Ipc::IpcStruct _structParameter, v1::commonapi::IpcStub::structInMethodReply_t _reply)
{
    std::cout << "TMP : "<<_structParameter.getTMP()<<" "<< "HUM : "<<_structParameter.getHUM()<<" "<< "RPM : "<<_structParameter.getRPM()<<" "<<
     "SPD : "<<_structParameter.getSPD()<<" "<< "BAT : "<<_structParameter.getBAT()<<std::endl;

    std::int32_t returnData = 1;
    _reply(returnData);
};

