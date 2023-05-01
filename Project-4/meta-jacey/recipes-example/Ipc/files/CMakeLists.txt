cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++0x")
include_directories(
    /home/seame-two/yocto/poky/meta-jacey/recipes-example/Ipc/files/src-gen
    /home/seame-two/yocto/poky/build/tmp/work/cortexa72-poky-linux/common-api-c++/3.2.0-r0/git/include
    /home/seame-two/yocto/poky/build/tmp/work/cortexa72-poky-linux/common-api-c++-dbus/3.2.0-r0/git/include
    /home/seame-two/yocto/poky/build/tmp/work/cortexa72-poky-linux/dbus/1.14.0-r0/dbus-1.14.0

)
link_directories(
    /home/seame-two/yocto/poky/build/tmp/work/cortexa72-poky-linux/common-api-c++/3.2.0-r0/build
    /home/seame-two/yocto/poky/build/tmp/work/cortexa72-poky-linux/common-api-c++-dbus/3.2.0-r0/build
    /home/seame-two/yocto/poky/build/tmp/work/cortexa72-poky-linux/dbus/1.14.0-r0/build/dbus/.libs
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

