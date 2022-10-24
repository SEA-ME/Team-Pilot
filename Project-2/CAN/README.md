# CAN Communication

## Contents  
- [Arduino setting](#arduino-setting) 
- [MH-Sensor-Series](#mh-sensor-series--speed-and-rpm)
- [DHT11 Sensor ( Temperature and Humidity )](#dht11-sensor--temperature-and-humidity)  
- [CAN Shields](#can-shields)

---

<br/>

## Arduino Setting
Donwload Arduino IDE
    
```bash
sudo snap install arduino
arduino
```
<details>
<summary>Troubleshooting</summary>

<img src="https://user-images.githubusercontent.com/111988634/189864114-eeb157e5-42cf-46af-9b59-f848882e8b40.png"  width="500" height="500"/>  

```bash
sudo usermod -a -G dialout seame-three
sudo reboot
```
</details>

--- 

<br/>

## MH-Sensor-Series ( Speed and RPM )

<img src="https://user-images.githubusercontent.com/111988634/190005206-37e48b0b-eba8-4a11-9f84-69b67825110b.jpg"  width="500" height="400"/>  

| MH-Sensor-Series | Uno |
| --- | --- |
| VCC | 5V |
| GND | GND |
| D0 | 8 |
| A0  | A0 |

Add arduino file to Uno
- ### [spd_example.ino](src/spd_example.ino)

---

<br/>


## DHT11 Sensor ( Temperature and Humidity )

- Circuit

    <img src="https://user-images.githubusercontent.com/111988634/190004955-ea62c788-894f-4662-ad9f-57140d833e26.png"  width="500" height="300"/>  
    
    <img src="https://user-images.githubusercontent.com/111988634/190005137-51d631fb-e49a-4db0-86e8-eb0733afeda0.jpg"  width="600" height="300"/>  


    | Arduino Uno | CAN Module MCP2515 |
    | --- | --- |
    | VCC | 5V |
    | GND | GND |
    | CS | 9 |
    | SO | 11 |
    | SI | 10 |
    | SCK | 13 |


    | CAN Module MCP2515 | CAN Module MCP2515 |
    | --- | --- |
    | CAN H | CAN H |
    | CAN L | CAN L |


    | Arduino Nano | CAN Module MCP2515 |
    | --- | --- |
    | VCC | 5V |
    | GND | GND |
    | CS | 9 |
    | SO | 11 |
    | SI | 10 |
    | SCK | 13 |


    | DHT11 | Arduino Nano  |
    | --- | --- |
    | GND | GND |
    | DATA | A0 |
    | VCC | 5V |

- ### [uno_receiver.ino ( Uno )](src/uno_receiver.ino)
- ### [nano_transmitter.ino ( Nano )](src/nano_transmitter.ino)
    
---

<br/>

## CAN Shields

<img src="https://user-images.githubusercontent.com/111988634/192337689-a812475f-3fe9-4a5a-9b55-a79576cfffff.jpg"  width="600" height="400"/>  

| PiRacer Pro expansion board | Raspberry PI  CAN shield |
| --- | --- |
| SCL | SCL ( Don't connect with GND ) |
| SDA | SDA ( Don't connect with GND ) |
| 3V3 | 3V3 ( Soldering )  |
| GND | GND |
| 5V | 5V |
| 5V | 5V |


1. **Soldering 3V3 to Raspberry PI CAN Shield**

1. Open config.txt file
    
    ```bash
    sudo nano /boot/config.txt
    ```
    
2. Add the following line at the end of the file
    
    ```bash
    dtoverlay=seeed-can-fd-hat-v2
    ```
    
3. Reboot RPI
    
    ```bash
    sudo reboot
    ```
    
4. Check the kernel log to see if CAN-BUS HAT was initialized successfully. You will also see can0
and can1 appear in the list of ifconfig results
    
    ```bash
    (env) moon@moon:~ $ dmesg | grep spi
    [    5.682114] spi_master spi0: will run message pump with realtime priority
    [    5.690279] mcp251xfd spi0.1 can0: MCP2518FD rev0.0 (-RX_INT -MAB_NO_WARN +CRC_REG +CRC_RX +CRC_TX +ECC -HD c:40.00MHz m:20.00MHz r:17.00MHz e:16.66MHz) successfully initialized.
    [    5.702068] mcp251xfd spi0.0 can1: MCP2518FD rev0.0 (-RX_INT -MAB_NO_WARN +CRC_REG +CRC_RX +CRC_TX +ECC -HD c:40.00MHz m:20.00MHz r:17.00MHz e:16.66MHz) successfully initialized.
    ```
    
    ```bash
    (env) moon@moon:~ $ ifconfig -a
    can0: flags=128<NOARP>  mtu 16
            unspec 00-00-00-00-00-00-00-00-00-00-00-00-00-00-00-00  txqueuelen 10  (UNSPEC)
            RX packets 0  bytes 0 (0.0 B)
            RX errors 0  dropped 0  overruns 0  frame 0
            TX packets 0  bytes 0 (0.0 B)
            TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0
            device interrupt 67  
    
    can1: flags=128<NOARP>  mtu 16
            unspec 00-00-00-00-00-00-00-00-00-00-00-00-00-00-00-00  txqueuelen 10  (UNSPEC)
            RX packets 0  bytes 0 (0.0 B)
            RX errors 0  dropped 0  overruns 0  frame 0
            TX packets 0  bytes 0 (0.0 B)
            TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0
            device interrupt 68  
    
    eth0: flags=4099<UP,BROADCAST,MULTICAST>  mtu 1500
            ether e4:5f:01:64:c0:ca  txqueuelen 1000  (Ethernet)
            RX packets 0  bytes 0 (0.0 B)
            RX errors 0  dropped 0  overruns 0  frame 0
            TX packets 0  bytes 0 (0.0 B)
            TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0
    
    lo: flags=73<UP,LOOPBACK,RUNNING>  mtu 65536
            inet 127.0.0.1  netmask 255.0.0.0
            inet6 ::1  prefixlen 128  scopeid 0x10<host>
            loop  txqueuelen 1000  (Local Loopback)
            RX packets 0  bytes 0 (0.0 B)
            RX errors 0  dropped 0  overruns 0  frame 0
            TX packets 0  bytes 0 (0.0 B)
            TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0
    
    wlan0: flags=4163<UP,BROADCAST,RUNNING,MULTICAST>  mtu 1500
            inet 192.168.0.102  netmask 255.255.255.0  broadcast 192.168.0.255
            inet6 fe80::63b1:930e:fdf6:6fa7  prefixlen 64  scopeid 0x20<link>
            ether e4:5f:01:64:c0:cb  txqueuelen 1000  (Ethernet)
            RX packets 608  bytes 49980 (48.8 KiB)
            RX errors 0  dropped 0  overruns 0  frame 0
            TX packets 476  bytes 70356 (68.7 KiB)
            TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0
    ```
    
5. Raspberry pi setting and you can use can-util to receive
    
    ```bash
    sudo ip link set can1 up type can bitrate 500000
    ```
    
    add bashrc
    ```bash
    alias cl='sudo ip link set can1 up type can bitrate 500000'
    ```
    
    receive
    ```bash
    (env) moon@moon:~ $ candump can1
      can1  000   [8]  00 00 00 00 00 00 09 1C
      can1  000   [8]  00 00 00 00 00 00 09 1D
      can1  000   [8]  00 00 00 00 00 00 09 1E
      can1  000   [8]  00 00 00 00 00 00 09 1F
      can1  000   [8]  00 00 00 00 00 00 09 20
      can1  000   [8]  00 00 00 00 00 00 09 21
      can1  000   [8]  00 00 00 00 00 00 09 22
      can1  000   [8]  00 00 00 00 00 00 09 23
      can1  000   [8]  00 00 00 00 00 00 09 24
    ```
    
6. You can use python code to get the CAN data
    
    Install python-can
    ```bash
    sudo pip3 install python-can
    ```
    
    ```bash
    nano can_recv.py
    ```

- ### [uno_canshield.ino](src/uno_canshield.ino)
- ### [can_recv.py](src/rpi_canshield.py)
        
    
    ```bash
    (env) moon@moon:~ $ python3 can_recv.py
    Timestamp: 1663683669.282204        ID: 0000    S Rx                DL:  8    00 00 00 00 00 00 23 47     Channel: can1
    Timestamp: 1663683669.382681        ID: 0000    S Rx                DL:  8    00 00 00 00 00 00 23 48     Channel: can1
    Timestamp: 1663683669.482546        ID: 0000    S Rx                DL:  8    00 00 00 00 00 00 23 49     Channel: can1
    Timestamp: 1663683669.582747        ID: 0000    S Rx                DL:  8    00 00 00 00 00 00 23 4a     Channel: can1
    Timestamp: 1663683669.682920        ID: 0000    S Rx                DL:  8    00 00 00 00 00 00 23 4b     Channel: can1
    Timestamp: 1663683669.783183        ID: 0000    S Rx                DL:  8    00 00 00 00 00 00 23 4c     Channel: can1
    Timestamp: 1663683669.883471        ID: 0000    S Rx                DL:  8    00 00 00 00 00 00 23 4d     Channel: can1
    Timestamp: 1663683669.983672        ID: 0000    S Rx                DL:  8    00 00 00 00 00 00 23 4e     Channel: can1
    ```

8. You can use C++ code to get CAN data
    ```bash
    nano can_recv.cpp
    ```

- ### [can_recv.cpp](src/can_recv.cpp)

    ```bash
    g++ can_recv.cpp
    ```
    ```bash
    (env) moon@moon:~ $ ./a.out 
    Success to socket create
    (null)Success to get CAN interface index : -1090825376(null)
    Success to socket bind
    0x000 [8] 31 19 00 03 00 00 00 00 
    0x000 [8] 31 19 00 03 00 00 00 00 
    0x000 [8] 31 19 00 03 00 00 00 00 
    0x000 [8] 31 19 00 03 00 00 00 00 
    0x000 [8] 31 19 00 03 00 00 00 00 
    0x000 [8] 31 19 00 03 00 00 00 00 
    0x000 [8] 31 19 00 03 00 00 00 00 
    ```