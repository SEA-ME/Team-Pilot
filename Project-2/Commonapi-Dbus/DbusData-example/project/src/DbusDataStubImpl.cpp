// DbusDataStubImpl.cpp
#include "DbusDataStubImpl.hpp"

DbusDataStubImpl::DbusDataStubImpl() { }
DbusDataStubImpl::~DbusDataStubImpl() { }


void DbusDataStubImpl::structInMethod(const std::shared_ptr<CommonAPI::ClientId> _client, 
v1::commonapi::DbusData::dataStruct _structParameter, v1::commonapi::DbusDataStub::structInMethodReply_t _reply)
{
    std::cout << "TMP : "<<_structParameter.getTMP()<<" "<< "HUM : "<<_structParameter.getHUM()<<" "<< "RPM : "<<_structParameter.getRPM()
    << "SPD : "<<" : "<<_structParameter.getSPD()<< "BAT : "<<_structParameter.getBAT()<<std::endl;

    std::int32_t returnData = 1;
    _reply(returnData);
};
