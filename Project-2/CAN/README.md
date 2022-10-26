# CAN


- ## Reference site

[CAN bus on raspberry pi with MCP2515](https://forums.raspberrypi.com/viewtopic.php?t=141052)

[CAN communication between Raspberry Pi and Arduino](https://forums.raspberrypi.com/viewtopic.php?t=296117)

[2 Channel CAN BUS FD Shield for Raspberry Pi](https://wiki.seeedstudio.com/2-Channel-CAN-BUS-FD-Shield-for-Raspberry-Pi/)
- - - 

- ## Contents

[1. Connect CAN BUS(FD) Hat](#1-connect-can-busfd-hat)   
[2. Edit config.txt file](#2-edit-configtxt-file-and-add-following)    
[3. Reboot](#3-reboot)    
[4. Initialized](#4-initialized)   
[5. Check ifconfig list](#5-check-ifconfig-list)   
[6. Install CAN tools](#6-install-can-tools)    
[7. Send & Recv test with 2-channel CAN FD](#7-send--recv-test-with-2-channel-can-fd)     
[8. Raspberry pi to Arduino CAN - CAN communication](#8-raspberry-pi-to-arduino-can---can-communication)

- - -


## CAN BUS (FD) Hat


### 1. Connect CAN BUS(FD) Hat

### 2. Edit config.txt file and Add following

```jsx
sudo vim /boot/config.txt
dtoverlay=seeed-can-fd-hat-v2
```

### 3. Reboot

### 4. Initialized

```jsx
dmesg | grep spi
```

OUTPUT:

```jsx
[    5.848080] spi_master spi0: will run message pump with realtime priority
[    5.861055] mcp251xfd spi0.1 can0: MCP2518FD rev0.0 (-RX_INT -MAB_NO_WARN +CRC_REG +CRC_RX +CRC_TX +ECC -HD c:40.00MHz m:20.00MHz r:17.00MHz e:16.66MHz) successfully initialized.
[    5.873396] mcp251xfd spi0.0 can1: MCP2518FD rev0.0 (-RX_INT -MAB_NO_WARN +CRC_REG +CRC_RX +CRC_TX +ECC -HD c:40.00MHz m:20.00MHz r:17.00MHz e:16.66MHz) successfully initialized.
```

### 5. Check ifconfig list

```jsx
ifconfig -a
```

OUTPUT:

<img src="https://user-images.githubusercontent.com/81483791/194759745-bf0ca7c9-9d24-4511-8da6-451ba709fe5a.png"  width="800" height="200"/> 

### 6. Install CAN tools

```jsx
sudo apt-get install can-utils
pip3 install python-can
```

### 7.  Send & Recv test with 2-channel CAN FD

<img src="https://user-images.githubusercontent.com/81483791/194759823-9e4338e2-88be-46db-ab9a-f528e08d2e51.png"  width="300" height="200"/> 

### 7.1.  Connect the channels

0_L <===> 1_L

0_H <===> 1_H

### 7.2. Set the CAN protocol

```jsx
sudo ip link set can0 up type can bitrate 1000000   dbitrate 8000000 restart-ms 1000 berr-reporting on fd on
sudo ip link set can1 up type can bitrate 1000000   dbitrate 8000000 restart-ms 1000 berr-reporting on fd on
 
sudo ifconfig can0 txqueuelen 65536
sudo ifconfig can1 txqueuelen 65536
```

### 7.3. Open two windows

```jsx
#send data
cangen can0 -mv
```

```jsx
#dump data
candump can1
```

OUTPUT :     

<img src="https://user-images.githubusercontent.com/81483791/194759914-d895bb27-c0ae-4d30-a76a-3fab5080f9e7.png"  width="800" height="240"/> 
<img src="https://user-images.githubusercontent.com/81483791/194759918-3a2c27f1-2d26-4191-8dcb-6948b2f82208.png"  width="800" height="260"/> 

### 8. Raspberry pi to Arduino CAN - CAN communication

If you follow step 7, you need to reboot.

<img src="https://user-images.githubusercontent.com/81483791/194759992-e170a065-c913-438f-87dd-3d99718f69fa.png"  width="300" height="400"/> 

### 8.1. Set CAN protocol

I connectecd like this picture,

Arduino CAN_L <===> Raspberry pi 0_L

Arduino CAN_H <===> Raspberry pi 0_H

```jsx
sudo ip link set can1 up type can bitrate 500000
```

### 8.2. Check details

```jsx
ip -details link show can0
```
- ### Arduino Code (Send data)
[CAN_send_data.ino](src/CAN_send_data.ino)

- ### Raspberry pi Code (Recv data)

1. Open terminal and following:

```jsx
candump can0
```

or 

2. Make a python file

 [CAN_recv_data.py](src/CAN_recv_data.py)

OUTPUT:

unsigned char stmp[8] = {1, 2, 3, 4, 5, 6, 7, 8};

<img src="https://user-images.githubusercontent.com/81483791/194760379-161afcd7-03d7-413a-b53c-8eae269a6b6b.png"  width="800" height="250"/> 