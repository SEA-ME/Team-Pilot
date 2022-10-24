// CANStubImpl.hpp
#ifndef CANSTUBIMPL_H_
#define CANSTUBIMPL_H_
#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/CANStubDefault.hpp>

class CANStubImpl: public v1::commonapi::CANStubDefault {
public:
    CANStubImpl();
    virtual ~CANStubImpl();
    virtual void structInMethod(const std::shared_ptr<CommonAPI::ClientId> _client, v1::commonapi::CAN::canStruct _structParameter, structInMethodReply_t _reply);
};
#endif /* CANSTUBIMPL_H_ */