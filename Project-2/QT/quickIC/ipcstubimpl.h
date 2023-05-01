#ifndef IPCSTUBLMPL_H
#define IPCSTUBLMPL_H

#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/IpcStubDefault.hpp>

class IpcStubImpl: public v1::commonapi::IpcStubDefault {
public:
    IpcStubImpl();
    virtual ~IpcStubImpl();
    virtual void structInMethod(const std::shared_ptr<CommonAPI::ClientId> _client, v1::commonapi::Ipc::IpcStruct _structParameter, structInMethodReply_t _reply);

public:
    std::int32_t getTMP();
    std::int32_t getHUM();
    std::int32_t getRPM();
    std::int32_t getSPD();
    std::int32_t getBAT();


private:
    std::int32_t TMP;
    std::int32_t HUM;
    std::int32_t RPM;
    std::int32_t SPD;
    std::int32_t BAT;


};

#endif // IPCSTUBLMPL_H
