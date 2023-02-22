// CANService.cpp
#include "CANService.hpp"

CANService::CANService()
//  : ina219(NULL)
{
  startCommunicate();
}

CANService::~CANService() {
  close(can_fd);
}

void CANService::initSocket(const char *ifname) {
  can_fd = socket(PF_CAN, SOCK_RAW, CAN_RAW);
  if (can_fd < 0)
    std::cout << "Failed to socket create" << std::endl;
  std::cout << "Success to socket create" << std::endl;

  struct ifreq ifr;
  strcpy(ifr.ifr_name, ifname);
  int ret = ioctl(can_fd, SIOCGIFINDEX, &ifr);
  if (ret < 0)
    printf("Failed to get CAN interface index\n", ret);
  printf("%sSuccess to get CAN interface index : %d%s\n", ret);

  struct sockaddr_can addr;
  addr.can_family = AF_CAN;
  addr.can_ifindex = ifr.ifr_ifindex;
  ret = bind(can_fd, (struct sockaddr *)&addr, sizeof(addr));
  if (ret < 0)
    printf("Failed to socket bind\n", ret);
  printf("Success to socket bind\n");
}

void CANService::readSocket() {
  rd_byte = read(can_fd, &frame, sizeof(frame));
  if (rd_byte < 0)
    printf("Failed to recieve CAN frame\n", rd_byte);
  else if (rd_byte < (int)sizeof(struct can_frame))
    printf("Incomplete CAN frame is received\n", rd_byte, rd_byte);
  else if (frame.can_dlc > CAN_MAX_DLEN)
    printf("Invalid dlc\n", -1, frame.can_dlc);

  // unsigned char -> uint16_t
  rpm_combine = frame.data[2] | uint16_t(frame.data[3]) << 8;

  moonService->humPublisher(frame.data[0]);
  moonService->tmpPublisher(frame.data[1]);
  moonService->rpmPublisher(rpm_combine);
  moonService->spdPublisher(frame.data[4]);
}

// void CANService::initBattery() {
//   ina219 = ina219_create (I2C_DEV, I2C_ADDR, SHUNT_MILLIOHMS, 
//                           BATTERY_VOLTAGE_0_PERCENT, BATTERY_VOLTAGE_100_PERCENT, 
//                           BATTERY_CAPACITY, MIN_CHARGING_CURRENT);

//   char *error = NULL;
//   ina_status = false;
//   if (ina219_init (ina219, &error))
//     ina_status = true;
// }

// void CANService::readBattery() {
//   INA219ChargeStatus charge_status;
//   char *error = NULL;
//   if (ina_status){
//     if (ina219_get_status (ina219, &charge_status, &mV, 
//                           &percent_charged, &battery_current_mA, 
//                           &minutes, &error)) {

//       moonService->batPublisher(percent_charged);
//     }
//   }
// }

void CANService::initVsomeipService() {
  runtime = CommonAPI::Runtime::get();
  moonService = std::make_shared<CANStubImpl>();
  runtime->registerService("local", "can", moonService);
  std::cout << "Successfully Registered Service!" << std::endl;

  std::cout << "Waiting for calls... (Abort with CTRL+C)" << std::endl;
  std::this_thread::sleep_for(std::chrono::seconds(30));
  
}

void CANService::startCommunicate() {
  initVsomeipService();
  initSocket("can0");
  // initBattery();

  while (true) {
    readSocket();
    // readBattery();
    std::this_thread::sleep_for(std::chrono::seconds(10));
  }
}


int main() {
  CANService canService;
  canService.startCommunicate();
  return 0;
}
