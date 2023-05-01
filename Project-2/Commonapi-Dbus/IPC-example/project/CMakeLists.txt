cmake_minimum_required(VERSION 2.8)
project(ProjectName)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++0x")
set(CMAKE_CXX_LINK_FLAGS "${CMAKE_CXX_LINK_FLAGS} -latomic")
include_directories(
    src-gen
    ~/commonapi/capicxx-core-runtime/include
    ~/commonapi/capicxx-dbus-runtime/include
    ~/commonapi/dbus-1.10.10
)
link_directories(
    ~/commonapi/capicxx-core-runtime/build
    ~/commonapi/capicxx-dbus-runtime/build
    ~/commonapi/dbus-1.10.10/dbus/.libs
)
add_executable(IpcClient
	src/IpcClient.cpp
	src/ina219.c
	src-gen/v1/commonapi/IpcDBusProxy.cpp
	src-gen/v1/commonapi/IpcDBusDeployment
)
target_link_libraries(IpcClient CommonAPI CommonAPI-DBus dbus-1)
add_executable(IpcService
	src/IpcService.cpp
	src/IpcStubImpl.cpp
	src-gen/v1/commonapi/IpcDBusStubAdapter.cpp
	src-gen/v1/commonapi/IpcStubDefault
	src-gen/v1/commonapi/IpcDBusDeployment
)
target_link_libraries(IpcService CommonAPI CommonAPI-DBus dbus-1)

