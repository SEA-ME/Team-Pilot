// CANService.cpp
#include <iostream>
#include <thread>
#include <CommonAPI/CommonAPI.hpp>
#include "CANStubImpl.hpp"

using namespace std;

int main() {
    std::shared_ptr<CommonAPI::Runtime> runtime = CommonAPI::Runtime::get();
    std::shared_ptr<CANStubImpl> moonService =
    	std::make_shared<CANStubImpl>();
    runtime->registerService("local", "can", moonService);
    std::cout << "Successfully Registered Service!" << std::endl;

    while (true) {
        std::cout << "Waiting for calls... (Abort with CTRL+C)" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(30));
    }
    return 0;
 }