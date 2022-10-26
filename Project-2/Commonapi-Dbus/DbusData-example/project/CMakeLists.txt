cmake_minimum_required(VERSION 2.8)
project(ProjectName)

set(CMAKE_CXX_LINK_FLAGS "${CMAKE_CXX_LINK_FLAGS} -latomic")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++0x")

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
add_executable(DbusDataClient
	src/DbusDataClient.cpp
	src/ina219.c
	src-gen/v1/commonapi/DbusDataDBusProxy.cpp
	src-gen/v1/commonapi/DbusDataDBusDeployment
)
target_link_libraries(DbusDataClient CommonAPI CommonAPI-DBus dbus-1)
add_executable(DbusDataService
	src/DbusDataService.cpp
	src/DbusDataStubImpl.cpp
	src-gen/v1/commonapi/DbusDataDBusStubAdapter.cpp
	src-gen/v1/commonapi/DbusDataStubDefault
	src-gen/v1/commonapi/DbusDataDBusDeployment
)
target_link_libraries(DbusDataService CommonAPI CommonAPI-DBus dbus-1)
