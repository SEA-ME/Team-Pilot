# Sensor

- ## Reference site

[speed sensor reference](https://www.brainy-bits.com/post/how-to-use-a-speed-sensor-with-arduino)
- - - 

- ## Contents

[Temperature Sensor](#temperature-sensor)  
[Speed sensor](#speed-sensor)
- - -

## Temperature Sensor

### 1. Connect Arduino with sensor

<img src="https://user-images.githubusercontent.com/81483791/194761365-2cd16084-32f0-406c-b24c-ecf8dd629de6.png"  width="300" height="200"/> 

- Guide line

| Sensor | Arduino |
| --- | --- |
| GND | GND |
| VCC | 5V |
| DOUT | 3 |

If you connect `D0`  ↔  `3` 

`#define DHTPIN 3` 

### 2. Execute Arduino

[temperature.ino](src/temperature.ino)

- - - 

## Speed Sensor

### 1. Connect Arduino with sensor
<img src="https://user-images.githubusercontent.com/81483791/194761783-a0a16582-f8dd-4791-96e8-d529690843ed.png"  width="300" height="200"/> 

- Guide line

| Sensor | Arduino |
| --- | --- |
| GND | GND |
| VCC | 5V |
| D0 | 2 |

If you connect `D0`  ↔  `2` 

`pinMode(2, INPUT)`     
<img src="https://user-images.githubusercontent.com/81483791/198118393-e78e8c23-9a13-460b-b102-7782f0af9bb8.jpg"  width="200" height="220"/>     
**Engine : Axis : Wheel = 5 : 2 : 1**

Wheel diameter = 47 mm

### 2. Execute Arduino

[sensor.ino](src/temperature.ino)

You can check with OLED    
<img src="https://user-images.githubusercontent.com/81483791/194762080-f6a60c57-7489-4bf4-838c-c0456fbc0455.png"  width="300" height="150"/> 