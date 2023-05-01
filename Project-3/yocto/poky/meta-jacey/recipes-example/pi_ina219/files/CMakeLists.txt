cmake_minimum_required(VERSION 2.8)

project(piracerbattery)
include_directories(
    /home/seame-two/yocto/poky/meta-jacey/recipes-example/pi_ina219/files/src

)
add_executable(piina
	src/ina219.c
	src/main.c
)

