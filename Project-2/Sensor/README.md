# Sensor

### **Table of Contents**
- [Temperature Sensor](#temperature-sensor)  
- [Speed sensor](#speed-sensor)
### **Reference**
- [speed sensor reference](https://www.brainy-bits.com/post/how-to-use-a-speed-sensor-with-arduino)


## Temperature Sensor

| Arduino UNO | DHT11 Temp seonsor |
| --- | --- |
| <img src="https://user-images.githubusercontent.com/81483791/235361477-c871f074-bb50-4fcd-8795-f06b8526da11.png"  width="376" height="267"/> |  <img src="https://user-images.githubusercontent.com/81483791/235361461-a98f4808-4a3c-41fd-8d59-0c7c8a83d38c.png"  width="250" height="123"/> |
- How to connect?    

    | Arduino | Sensor |
    | --- | --- |
    | GND | GND |
    | 5V | VCC |
    | 3 | DOUT |

If you connect `D0`  ↔  `3` 

`#define DHTPIN 3` 

- - - 

## Speed Sensor

| Arduino UNO | Speed seonsor |
| --- | --- |
| <img src="https://user-images.githubusercontent.com/81483791/235361477-c871f074-bb50-4fcd-8795-f06b8526da11.png"  width="376" height="267"/> |  <img src="https://user-images.githubusercontent.com/81483791/235361849-e224bc23-accc-46f7-a4a4-0e652f5c1ad6.png"  width="292" height="151"/> |
- How to connect?  
    | Arduino | Sensor |
    | --- | --- |
    | GND | GND |
    | 5V | VCC |
    | 2 | D0 |  


If you connect `D0`  ↔  `2` 

`pinMode(2, INPUT)`    

I connected the speed sensor as shown in the picture.    

<img src="https://user-images.githubusercontent.com/81483791/235363202-7657cc80-8dc5-435f-a187-77649221ef19.png"  width="573" height="289"/> 

If you connected sensors correctly, then execute this file.  
[sensor.ino](src/temperature.ino)

