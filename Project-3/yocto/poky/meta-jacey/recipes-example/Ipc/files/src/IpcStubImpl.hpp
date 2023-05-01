// IpcStubImpl.hpp
#ifndef IpcSTUBIMPL_H_
#define IpcSTUBIMPL_H_
#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/IpcStubDefault.hpp>

class IpcStubImpl: public v1::commonapi::IpcStubDefault {
public:
    IpcStubImpl();
    virtual ~IpcStubImpl();
    virtual void structInMethod(const std::shared_ptr<CommonAPI::ClientId> _client, v1::commonapi::Ipc::IpcStruct _structParameter, structInMethodReply_t _reply);
};
#endif /* IpcSTUBIMPL_H_ */

