/*
 * This file was generated by the CommonAPI Generators.
 * Used org.genivi.commonapi.someip 3.2.0.v202012010944.
 * Used org.franca.core 0.13.1.201807231814.
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
#define HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

#include <CommonAPI/SomeIP/AddressTranslator.hpp>
#include <CommonAPI/SomeIP/StubAdapterHelper.hpp>
#include <CommonAPI/SomeIP/StubAdapter.hpp>
#include <CommonAPI/SomeIP/Factory.hpp>
#include <CommonAPI/SomeIP/Types.hpp>
#include <CommonAPI/SomeIP/Constants.hpp>

#if defined (HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE)
#undef COMMONAPI_INTERNAL_COMPILATION
#undef HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

namespace v1 {
namespace commonapi {

template <typename _Stub = ::v1::commonapi::CANStub, typename... _Stubs>
class CANSomeIPStubAdapterInternal
    : public virtual CANStubAdapter,
      public CommonAPI::SomeIP::StubAdapterHelper< _Stub, _Stubs...>,
      public std::enable_shared_from_this< CANSomeIPStubAdapterInternal<_Stub, _Stubs...>>
{
public:
    typedef CommonAPI::SomeIP::StubAdapterHelper< _Stub, _Stubs...> CANSomeIPStubAdapterHelper;

    ~CANSomeIPStubAdapterInternal() {
        deactivateManagedInstances();
        CANSomeIPStubAdapterHelper::deinit();
    }

    void deactivateManagedInstances() {}
    
    CommonAPI::SomeIP::GetAttributeStubDispatcher<
        ::v1::commonapi::CANStub,
        CommonAPI::Version
    > getCANInterfaceVersionStubDispatcher;

    CommonAPI::SomeIP::MethodWithReplyStubDispatcher<
        ::v1::commonapi::CANStub,
        std::tuple< CAN::HUM>,
        std::tuple< uint8_t>,
        std::tuple< CommonAPI::SomeIP::IntegerDeployment<uint8_t>>,
        std::tuple< CommonAPI::SomeIP::IntegerDeployment<uint8_t>>
    > getHUMStubDispatcher;
    
    CommonAPI::SomeIP::MethodWithReplyStubDispatcher<
        ::v1::commonapi::CANStub,
        std::tuple< CAN::TMP>,
        std::tuple< int8_t>,
        std::tuple< CommonAPI::SomeIP::IntegerDeployment<int8_t>>,
        std::tuple< CommonAPI::SomeIP::IntegerDeployment<int8_t>>
    > getTMPStubDispatcher;
    
    CommonAPI::SomeIP::MethodWithReplyStubDispatcher<
        ::v1::commonapi::CANStub,
        std::tuple< CAN::RPM>,
        std::tuple< uint16_t>,
        std::tuple< CommonAPI::SomeIP::IntegerDeployment<uint16_t>>,
        std::tuple< CommonAPI::SomeIP::IntegerDeployment<uint16_t>>
    > getRPMStubDispatcher;
    
    CommonAPI::SomeIP::MethodWithReplyStubDispatcher<
        ::v1::commonapi::CANStub,
        std::tuple< CAN::SPD>,
        std::tuple< uint8_t>,
        std::tuple< CommonAPI::SomeIP::IntegerDeployment<uint8_t>>,
        std::tuple< CommonAPI::SomeIP::IntegerDeployment<uint8_t>>
    > getSPDStubDispatcher;
    
    CommonAPI::SomeIP::MethodWithReplyStubDispatcher<
        ::v1::commonapi::CANStub,
        std::tuple< CAN::BAT>,
        std::tuple< uint8_t>,
        std::tuple< CommonAPI::SomeIP::IntegerDeployment<uint8_t>>,
        std::tuple< CommonAPI::SomeIP::IntegerDeployment<uint8_t>>
    > getBATStubDispatcher;
    
    CANSomeIPStubAdapterInternal(
        const CommonAPI::SomeIP::Address &_address,
        const std::shared_ptr<CommonAPI::SomeIP::ProxyConnection> &_connection,
        const std::shared_ptr<CommonAPI::StubBase> &_stub):
        CommonAPI::SomeIP::StubAdapter(_address, _connection),
        CANSomeIPStubAdapterHelper(
            _address,
            _connection,
            std::dynamic_pointer_cast< CANStub>(_stub)),
        getCANInterfaceVersionStubDispatcher(&CANStub::lockInterfaceVersionAttribute, &CANStub::getInterfaceVersion, false, true),
        getHUMStubDispatcher(
            &CANStub::GetHUM,
            false,
            _stub->hasElement(0),
            std::make_tuple(static_cast< CommonAPI::SomeIP::IntegerDeployment<uint8_t>* >(nullptr)),
            std::make_tuple(static_cast< CommonAPI::SomeIP::IntegerDeployment<uint8_t>* >(nullptr)))
        
        ,
        getTMPStubDispatcher(
            &CANStub::GetTMP,
            false,
            _stub->hasElement(1),
            std::make_tuple(static_cast< CommonAPI::SomeIP::IntegerDeployment<int8_t>* >(nullptr)),
            std::make_tuple(static_cast< CommonAPI::SomeIP::IntegerDeployment<int8_t>* >(nullptr)))
        
        ,
        getRPMStubDispatcher(
            &CANStub::GetRPM,
            false,
            _stub->hasElement(2),
            std::make_tuple(static_cast< CommonAPI::SomeIP::IntegerDeployment<uint16_t>* >(nullptr)),
            std::make_tuple(static_cast< CommonAPI::SomeIP::IntegerDeployment<uint16_t>* >(nullptr)))
        
        ,
        getSPDStubDispatcher(
            &CANStub::GetSPD,
            false,
            _stub->hasElement(3),
            std::make_tuple(static_cast< CommonAPI::SomeIP::IntegerDeployment<uint8_t>* >(nullptr)),
            std::make_tuple(static_cast< CommonAPI::SomeIP::IntegerDeployment<uint8_t>* >(nullptr)))
        
        ,
        getBATStubDispatcher(
            &CANStub::GetBAT,
            false,
            _stub->hasElement(4),
            std::make_tuple(static_cast< CommonAPI::SomeIP::IntegerDeployment<uint8_t>* >(nullptr)),
            std::make_tuple(static_cast< CommonAPI::SomeIP::IntegerDeployment<uint8_t>* >(nullptr)))
        
    {
        CANSomeIPStubAdapterHelper::addStubDispatcher( { CommonAPI::SomeIP::method_id_t(0x7b) }, &getHUMStubDispatcher );
        CANSomeIPStubAdapterHelper::addStubDispatcher( { CommonAPI::SomeIP::method_id_t(0x7c) }, &getTMPStubDispatcher );
        CANSomeIPStubAdapterHelper::addStubDispatcher( { CommonAPI::SomeIP::method_id_t(0x7d) }, &getRPMStubDispatcher );
        CANSomeIPStubAdapterHelper::addStubDispatcher( { CommonAPI::SomeIP::method_id_t(0x7e) }, &getSPDStubDispatcher );
        CANSomeIPStubAdapterHelper::addStubDispatcher( { CommonAPI::SomeIP::method_id_t(0x7f) }, &getBATStubDispatcher );
        // Provided events/fields
    }

    // Register/Unregister event handlers for selective broadcasts
    void registerSelectiveEventHandlers();
    void unregisterSelectiveEventHandlers();

};


template <typename _Stub, typename... _Stubs>
void CANSomeIPStubAdapterInternal<_Stub, _Stubs...>::registerSelectiveEventHandlers() {
}

template <typename _Stub, typename... _Stubs>
void CANSomeIPStubAdapterInternal<_Stub, _Stubs...>::unregisterSelectiveEventHandlers() {
}

template <typename _Stub = ::v1::commonapi::CANStub, typename... _Stubs>
class CANSomeIPStubAdapter
    : public CANSomeIPStubAdapterInternal<_Stub, _Stubs...> {
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
