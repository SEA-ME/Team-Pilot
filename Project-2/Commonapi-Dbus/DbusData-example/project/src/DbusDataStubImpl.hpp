// DbusDataStubImpl.hpp
#ifndef DbusDataSTUBIMPL_H_
#define DbusDataSTUBIMPL_H_
#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/DbusDataStubDefault.hpp>

class DbusDataStubImpl: public v1::commonapi::DbusDataStubDefault {
public:
    DbusDataStubImpl();
    virtual ~DbusDataStubImpl();
    virtual void structInMethod(const std::shared_ptr<CommonAPI::ClientId> _client, v1::commonapi::DbusData::dataStruct _structParameter, structInMethodReply_t _reply);
};
#endif /* DbusDataSTUBIMPL_H_ */
