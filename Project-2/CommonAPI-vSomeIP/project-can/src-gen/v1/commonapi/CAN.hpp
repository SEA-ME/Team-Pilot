/*
* This file was generated by the CommonAPI Generators.
* Used org.genivi.commonapi.core 3.1.12.v201907221047.
* Used org.franca.core 0.9.1.201412191134.
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at
* http://mozilla.org/MPL/2.0/.
*/
#ifndef V1_COMMONAPI_CAN_HPP_
#define V1_COMMONAPI_CAN_HPP_




#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#define COMMONAPI_INTERNAL_COMPILATION
#endif

#include <CommonAPI/Deployment.hpp>
#include <CommonAPI/InputStream.hpp>
#include <CommonAPI/OutputStream.hpp>
#include <CommonAPI/Struct.hpp>
#include <CommonAPI/Types.hpp>
#include <cstdint>
#include <string>

#undef COMMONAPI_INTERNAL_COMPILATION

namespace v1 {
namespace commonapi {

class CAN {
public:
    virtual ~CAN() { }

    static inline const char* getInterface();
    static inline CommonAPI::Version getInterfaceVersion();
    struct canStruct : CommonAPI::Struct< int32_t, std::string, int32_t, std::string, int32_t, std::string, int32_t, std::string, int32_t, std::string> {
    
        canStruct()
        {
            std::get< 0>(values_) = 0;
            std::get< 1>(values_) = "";
            std::get< 2>(values_) = 0;
            std::get< 3>(values_) = "";
            std::get< 4>(values_) = 0;
            std::get< 5>(values_) = "";
            std::get< 6>(values_) = 0;
            std::get< 7>(values_) = "";
            std::get< 8>(values_) = 0;
            std::get< 9>(values_) = "";
        }
        canStruct(const int32_t &_code1, const std::string &_id1, const int32_t &_code2, const std::string &_id2, const int32_t &_code3, const std::string &_id3, const int32_t &_code4, const std::string &_id4, const int32_t &_code5, const std::string &_id5)
        {
            std::get< 0>(values_) = _code1;
            std::get< 1>(values_) = _id1;
            std::get< 2>(values_) = _code2;
            std::get< 3>(values_) = _id2;
            std::get< 4>(values_) = _code3;
            std::get< 5>(values_) = _id3;
            std::get< 6>(values_) = _code4;
            std::get< 7>(values_) = _id4;
            std::get< 8>(values_) = _code5;
            std::get< 9>(values_) = _id5;
        }
        inline const int32_t &getCode1() const { return std::get< 0>(values_); }
        inline void setCode1(const int32_t &_value) { std::get< 0>(values_) = _value; }
        inline const std::string &getId1() const { return std::get< 1>(values_); }
        inline void setId1(const std::string &_value) { std::get< 1>(values_) = _value; }
        inline const int32_t &getCode2() const { return std::get< 2>(values_); }
        inline void setCode2(const int32_t &_value) { std::get< 2>(values_) = _value; }
        inline const std::string &getId2() const { return std::get< 3>(values_); }
        inline void setId2(const std::string &_value) { std::get< 3>(values_) = _value; }
        inline const int32_t &getCode3() const { return std::get< 4>(values_); }
        inline void setCode3(const int32_t &_value) { std::get< 4>(values_) = _value; }
        inline const std::string &getId3() const { return std::get< 5>(values_); }
        inline void setId3(const std::string &_value) { std::get< 5>(values_) = _value; }
        inline const int32_t &getCode4() const { return std::get< 6>(values_); }
        inline void setCode4(const int32_t &_value) { std::get< 6>(values_) = _value; }
        inline const std::string &getId4() const { return std::get< 7>(values_); }
        inline void setId4(const std::string &_value) { std::get< 7>(values_) = _value; }
        inline const int32_t &getCode5() const { return std::get< 8>(values_); }
        inline void setCode5(const int32_t &_value) { std::get< 8>(values_) = _value; }
        inline const std::string &getId5() const { return std::get< 9>(values_); }
        inline void setId5(const std::string &_value) { std::get< 9>(values_) = _value; }
        inline bool operator==(const canStruct& _other) const {
        return (getCode1() == _other.getCode1() && getId1() == _other.getId1() && getCode2() == _other.getCode2() && getId2() == _other.getId2() && getCode3() == _other.getCode3() && getId3() == _other.getId3() && getCode4() == _other.getCode4() && getId4() == _other.getId4() && getCode5() == _other.getCode5() && getId5() == _other.getId5());
        }
        inline bool operator!=(const canStruct &_other) const {
            return !((*this) == _other);
        }
    
    };
};

const char* CAN::getInterface() {
    return ("commonapi.CAN:v1_0");
}

CommonAPI::Version CAN::getInterfaceVersion() {
    return CommonAPI::Version(1, 0);
}


} // namespace commonapi
} // namespace v1

namespace CommonAPI {
}


// Compatibility
namespace v1_0 = v1;

#endif // V1_COMMONAPI_CAN_HPP_
