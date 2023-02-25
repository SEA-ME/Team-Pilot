cmake_minimum_required(VERSION 2.8)

project(CAN)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++0x")

include_directories(
    ../src-gen-seame
    ~/build-commonapi/capicxx-core-runtime/include
    ~/build-commonapi/capicxx-someip-runtime/include
    ~/build-commonapi/vsomeip/interface
)
link_directories(
    ~/build-commonapi/capicxx-core-runtime/build
    ~/build-commonapi/capicxx-someip-runtime/build
    ~/build-commonapi/vsomeip/build
)
add_executable(CANService
	src/CANService.cpp
	src/SEAMEStubImpl.cpp
	src/ina219.c
	../src-gen-seame/v1/commonapi/SEAMESomeIPStubAdapter.cpp
	../src-gen-seame/v1/commonapi/SEAMESomeIPDeployment.cpp
)
target_link_libraries(CANService CommonAPI CommonAPI-SomeIP vsomeip3)
