# CAN


### **Table of Contents**
Solution 1. [Raspberry pi with mcp2515](#1-solution-can---raspberry-pi-with-mcp2515)   
Solution 2. [CAN BUS (FD) Hat](#can-bus-fd-hat)   
[Raspberry Pi to Arduino CAN communication](#solution-2-can-bus-fd-hat)
### **Reference**
- [CAN bus on raspberry pi with MCP2515](https://forums.raspberrypi.com/viewtopic.php?t=141052)
- [CAN communication between Raspberry Pi and Arduino](https://forums.raspberrypi.com/viewtopic.php?t=296117)
- [2 Channel CAN BUS FD Shield for Raspberry Pi](https://wiki.seeedstudio.com/2-Channel-CAN-BUS-FD-Shield-for-Raspberry-Pi/)


## Solution 1. CAN - Raspberry pi with mcp2515

| Raspberry Pi | MCP2515 |
| --- | --- |
| <img src="https://user-images.githubusercontent.com/81483791/224431790-6cea7443-c7b6-4be9-80f2-38a10a43c23e.png"  width="344" height="350"/> |  <img src="https://user-images.githubusercontent.com/81483791/224431793-a5eaa658-5cc5-4429-9aea-854ce911e34e.png"  width="253" height="200"/> |

- How to connect?    

    | Raspberry pi  | mcp2515 |
    | --- | --- |
    | 22 | INT |
    | 23 | SCK |
    | 19 | SI |
    | 21 | SO |
    | 24 | CS |
    | 20 | GND |
    | 5V | VCC1 |
    | 3V3 | VCC |

1. Update & Upgrade

    ```jsx
    sudo apt-get update
    sudo apt-get upgrade
    ```

2. Modify your /boot/config.txt file 

    Add following line

    ```jsx
    sudo vim /boot/config.txt
    dtoverlay=mcp2515-can0,oscillator=16000000,interrupt=25
    dtoverlay=spi-bcm2835-overlay
    ```
    interrupt=25 ( INT - GPIO25 )

3. Install CAN tools

    ```jsx
    sudo apt-get install can-utils
    pip3 install python-can
    ```

4. Reboot

5. Setup CAN interface

    ```jsx
    sudo ip link set can0 up type can bitrate 500000
    ```

6. ifconfig

    ```jsx
    sudo ifconfig
    ```

    OUTPUT :

    ```jsx
    can0: flags=193<UP,RUNNING,NOARP>  mtu 16
            unspec 00-00-00-00-00-00-00-00-00-00-00-00-00-00-00-00  txqueuelen 10  (UNSPEC)
            RX packets 0  bytes 0 (0.0 B)
            RX errors 0  dropped 0  overruns 0  frame 0
            TX packets 0  bytes 0 (0.0 B)
            TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0
    ```

- Trouble shooting
    
    
    If the expansion board is connected to a raspberry pi, There will be no 5V pin left.
    
    <img width="" height="" src="https://user-images.githubusercontent.com/81483791/224431806-ff4851e5-8bfe-4216-938f-99f6daa243e4.png">

    In this case, the problem may be solved using 5V in the lower right corner of the expansion board.
    


## Solution 2. CAN BUS (FD) Hat

| Type A | Type B |
| --- | --- |
| <img src="https://user-images.githubusercontent.com/81483791/224437034-fc38ef37-3b75-45ed-a8c1-22c88316a955.png"  width="285" height="245"/> |  <img src="https://user-images.githubusercontent.com/81483791/224436937-1f0803f8-8a1a-4fb4-bcc7-da138b3bdf2b.png"  width="285" height="245"/> |
1. Connect CAN BUS(FD) Hat

2. Modify your /boot/config.txt file 

    Add following line
    ```jsx
    sudo vim /boot/config.txt
    dtoverlay=seeed-can-fd-hat-v2
    ```

3. Reboot

4. Initialized

    ```jsx
    dmesg | grep spi
    ```

    OUTPUT:

    ```jsx
    [    5.848080] spi_master spi0: will run message pump with realtime priority
    [    5.861055] mcp251xfd spi0.1 can0: MCP2518FD rev0.0 (-RX_INT -MAB_NO_WARN +CRC_REG +CRC_RX +CRC_TX +ECC -HD c:40.00MHz m:20.00MHz r:17.00MHz e:16.66MHz) successfully initialized.
    [    5.873396] mcp251xfd spi0.0 can1: MCP2518FD rev0.0 (-RX_INT -MAB_NO_WARN +CRC_REG +CRC_RX +CRC_TX +ECC -HD c:40.00MHz m:20.00MHz r:17.00MHz e:16.66MHz) successfully initialized.
    ```

5. Check ifconfig list

    ```jsx
    ifconfig -a
    ```

    OUTPUT:
    
    <img src="https://user-images.githubusercontent.com/81483791/194759745-bf0ca7c9-9d24-4511-8da6-451ba709fe5a.png"  width="533" height="200"/> 

6. Install CAN tools

    ```jsx
    sudo apt-get install can-utils
    pip3 install python-can
    ```

7. Set CAN protocol

    Arduino CAN_L <===> Raspberry pi 0_L

    Arduino CAN_H <===> Raspberry pi 0_H

    ```jsx
    sudo ip link set can0 up type can bitrate 500000
    ```

8. Check details

    ```jsx
    ip -details link show can0
    ```


## Raspberry pi to Arduino CAN communication


- ### Arduino Code (Send data)
    [CAN_send_data.ino](src/CAN_send_data.ino)

- ### Raspberry pi Code (Recv data)
    1. Open terminal and following:

        ```jsx
        candump can0
        ```


    2. Make a python file

        [CAN_recv_data.py](src/CAN_recv_data.py)

    OUTPUT:

    unsigned char stmp[8] = {1, 2, 3, 4, 5, 6, 7, 8};

    <img width="722" height="278" src="https://user-images.githubusercontent.com/81483791/224431801-d45689b8-214d-413f-aa30-25eda011b47c.png">
