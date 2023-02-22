/*
* This file was generated by the CommonAPI Generators.
* Used org.genivi.commonapi.someip 3.1.12.v201907221223.
* Used org.franca.core 0.9.1.201412191134.
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at
* http://mozilla.org/MPL/2.0/.
*/
#ifndef V1_COMMONAPI_CAN_SOMEIP_STUB_ADAPTER_HPP_
#define V1_COMMONAPI_CAN_SOMEIP_STUB_ADAPTER_HPP_

#include <v1/commonapi/CANStub.hpp>
#include <v1/commonapi/CANSomeIPDeployment.hpp>

#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#define COMMONAPI_INTERNAL_COMPILATION
#endif

#include <CommonAPI/SomeIP/AddressTranslator.hpp>
#include <CommonAPI/SomeIP/StubAdapterHelper.hpp>
#include <CommonAPI/SomeIP/StubAdapter.hpp>
#include <CommonAPI/SomeIP/Factory.hpp>
#include <CommonAPI/SomeIP/Types.hpp>
#include <CommonAPI/SomeIP/Constants.hpp>

#undef COMMONAPI_INTERNAL_COMPILATION

namespace v1 {
namespace commonapi {

template <typename _Stub = ::v1::commonapi::CANStub, typename... _Stubs>
class CANSomeIPStubAdapterInternal
    : public virtual CANStubAdapter,
      public CommonAPI::SomeIP::StubAdapterHelper< _Stub, _Stubs...>
{
public:
    typedef CommonAPI::SomeIP::StubAdapterHelper< _Stub, _Stubs...> CANSomeIPStubAdapterHelper;

    ~CANSomeIPStubAdapterInternal() {
        deactivateManagedInstances();
        CANSomeIPStubAdapterHelper::deinit();
    }

    void deactivateManagedInstances() {
    }

    static CommonAPI::SomeIP::GetAttributeStubDispatcher<
        ::v1::commonapi::CANStub,
        CommonAPI::Version
    > getCANInterfaceVersionStubDispatcher;


    
    static CommonAPI::SomeIP::MethodWithReplyStubDispatcher<
        ::v1::commonapi::CANStub,
        std::tuple< CAN::canStruct>,
        std::tuple< int32_t>,
        std::tuple< ::v1::commonapi::CAN_::canStructDeployment_t>,
        std::tuple< CommonAPI::SomeIP::IntegerDeployment<int32_t>>
    > structInMethodStubDispatcher;

    CANSomeIPStubAdapterInternal(
        const CommonAPI::SomeIP::Address &_address,
        const std::shared_ptr<CommonAPI::SomeIP::ProxyConnection> &_connection,
        const std::shared_ptr<CommonAPI::StubBase> &_stub):
        CommonAPI::SomeIP::StubAdapter(_address, _connection),
        CANSomeIPStubAdapterHelper(
            _address,
            _connection,
            std::dynamic_pointer_cast< CANStub>(_stub))
    {

        
                CANSomeIPStubAdapterHelper::addStubDispatcher( { CommonAPI::SomeIP::method_id_t(0x7b) }, &structInMethodStubDispatcher );
        // Provided events/fields
    }

private:
};

template <typename _Stub, typename... _Stubs>
CommonAPI::SomeIP::GetAttributeStubDispatcher<
    ::v1::commonapi::CANStub,
    CommonAPI::Version
    > CANSomeIPStubAdapterInternal<_Stub, _Stubs...>::getCANInterfaceVersionStubDispatcher(&CANStub::lockInterfaceVersionAttribute, &CANStub::getInterfaceVersion, false);

template <typename _Stub, typename... _Stubs>
CommonAPI::SomeIP::MethodWithReplyStubDispatcher<
    ::v1::commonapi::CANStub,
    std::tuple< CAN::canStruct>,
    std::tuple< int32_t>,
    std::tuple< ::v1::commonapi::CAN_::canStructDeployment_t>,
    std::tuple< CommonAPI::SomeIP::IntegerDeployment<int32_t>>
> CANSomeIPStubAdapterInternal<_Stub, _Stubs...>::structInMethodStubDispatcher(
    &CANStub::structInMethod,
    false,
    std::make_tuple(static_cast< ::v1::commonapi::CAN_::canStructDeployment_t* >(nullptr)),
    std::make_tuple(static_cast< CommonAPI::SomeIP::IntegerDeployment<int32_t>* >(nullptr)));

template <typename _Stub = ::v1::commonapi::CANStub, typename... _Stubs>
class CANSomeIPStubAdapter
    : public CANSomeIPStubAdapterInternal<_Stub, _Stubs...>,
      public std::enable_shared_from_this< CANSomeIPStubAdapter<_Stub, _Stubs...>> {
public:
    CANSomeIPStubAdapter(const CommonAPI::SomeIP::Address &_address,
                                            const std::shared_ptr<CommonAPI::SomeIP::ProxyConnection> &_connection,
                                            const std::shared_ptr<CommonAPI::StubBase> &_stub)
        : CommonAPI::SomeIP::StubAdapter(_address, _connection),
          CANSomeIPStubAdapterInternal<_Stub, _Stubs...>(_address, _connection, _stub) {
    }
};

} // namespace commonapi
} // namespace v1

#endif // V1_COMMONAPI_CAN_SOMEIP_STUB_ADAPTER_HPP_
