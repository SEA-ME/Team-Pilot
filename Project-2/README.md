# **DES Project - Instrument Cluster**

PiRacer instrument cluster Qt application running on RPi and receiving speed data from a speed sensor via CAN

## **Project Intro**

The PiRacer instrument cluster Qt application project is aimed at creating a real-time speedometer for a racing car. The application will run on a Raspberry Pi and receive speed data from a speed sensor via the Controller Area Network (CAN) protocol. 


<p align="center">
  <img width="807" height="370" src="https://user-images.githubusercontent.com/81483791/224406250-42e7ed3c-664e-4e7f-9d1b-a78e43e0103b.png">
</p>  

## **What is CAN protocol?**
A Controller Area Network (CAN bus) is a vehicle bus standard designed to allow microcontrollers and devices to communicate with each other's applications without a host computer. It is a message-based protocol, designed originally for multiplex electrical wiring within automobiles to save on copper, but it can also be used in many other contexts. For each device, the data in a frame is transmitted serially but in such a way that if more than one device transmits at the same time, the highest priority device can continue while the others back off. Frames are received by all devices, including by the transmitting device.
<p align="center">
  <img width="688" height="305" src="https://user-images.githubusercontent.com/81483791/235360897-9e5b6ab0-f319-4528-b0ca-9176caa34010.png">
</p>  


## **Table of Contents**

### Step 1. [CAN communication](CAN)
### Step 2. [Get Sensor data](Sensor)
### Step 3. [Get Battery data](Battery)
### Step 4. [OLED display (optional)](OLED)
### Step 5. [Add GUI to Rpi OS LIte](GUI)
### Step 6. [Commonapi-Dbus](Commonapi-Dbus)

