// CANStubImpl.cpp
#include "CANStubImpl.hpp"

CANStubImpl::CANStubImpl() { }
CANStubImpl::~CANStubImpl() { }
 
void CANStubImpl::structInMethod(const std::shared_ptr<CommonAPI::ClientId> _client, 
v1::commonapi::CAN::canStruct _structParameter, v1::commonapi::CANStub::structInMethodReply_t _reply)
{
    std::cout << _structParameter.getId1() << ": " << _structParameter.getCode1() << " "
              << _structParameter.getId2() << ": " << _structParameter.getCode2() << " "
              << _structParameter.getId3() << ": " << _structParameter.getCode3() << " "
              << _structParameter.getId4() << ": " << _structParameter.getCode4() << " "
              << _structParameter.getId5() << ": " << _structParameter.getCode5() << " " << std::endl;

    std::int32_t returnData = 1;
    _reply(returnData);
};