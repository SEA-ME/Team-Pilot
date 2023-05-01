cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++0x")
include_directories(
    /home/seame-two/yocto/poky/meta-jacey/recipes-example/Hello/files/src-gen
    /home/seame-two/yocto/poky/build/tmp/work/cortexa72-poky-linux/common-api-c++/3.2.0-r0/git/include
    /home/seame-two/yocto/poky/build/tmp/work/cortexa72-poky-linux/common-api-c++-dbus/3.2.0-r0/git/include
    /home/seame-two/yocto/poky/build/tmp/work/cortexa72-poky-linux/dbus/1.14.0-r0/dbus-1.14.0

)
link_directories(
    /home/seame-two/yocto/poky/build/tmp/work/cortexa72-poky-linux/common-api-c++/3.2.0-r0/build
    /home/seame-two/yocto/poky/build/tmp/work/cortexa72-poky-linux/common-api-c++-dbus/3.2.0-r0/build
    /home/seame-two/yocto/poky/build/tmp/work/cortexa72-poky-linux/dbus/1.14.0-r0/build/dbus/.libs
)
add_executable(HelloWorldClient
	src/HelloWorldClient.cpp
	src-gen/v1/commonapi/HelloWorldDBusProxy.cpp
	src-gen/v1/commonapi/HelloWorldDBusDeployment
)
target_link_libraries(HelloWorldClient CommonAPI CommonAPI-DBus dbus-1)
add_executable(HelloWorldService
	src/HelloWorldService.cpp
	src/HelloWorldStubImpl.cpp
	src-gen/v1/commonapi/HelloWorldDBusStubAdapter.cpp
	src-gen/v1/commonapi/HelloWorldStubDefault
	src-gen/v1/commonapi/HelloWorldDBusDeployment
)
target_link_libraries(HelloWorldService CommonAPI CommonAPI-DBus dbus-1)
