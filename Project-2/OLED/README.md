# OLED

### **Table of Contents**
- [Solution 1. OLED display with donkeycar](#solution-1-oled-display-with-donkeycar)  
- [Solution 2. OLED display with pi-display](#solution-2-oled-display-with-pi-display)   
- [How to change display_server.py file](#how-to-change-display_serverpy-file)    
- [How to Calculate battery level](#how-to-calculate-battery-level)
### **Reference**
- [pi-display](https://github.com/waveshare/pi-display)  
- [How to Auto execute program reference](https://m.blog.naver.com/emperonics/221770579539)  
- [Process systemd reference](https://bkjeon1614.tistory.com/658)



## Solution 1. OLED display with donkeycar

### Edit config.py

`USE_SSD1306_128_32 = True`

```jsx
#SSD1306_128_32
USE_SSD1306_128_32 = True    # Enable the SSD_1306 OLED Display
SSD1306_128_32_I2C_ROTATION = 0 # 0 = text is right-side up, 1 = rotated 90 degrees clockwise, 2 = 180 degrees (flipped), 3 = 270 degrees
SSD1306_RESOLUTION = 1 # 1 = 128x32; 2 = 128x64
```

<img src="https://user-images.githubusercontent.com/81483791/194760823-9d0e02c2-b279-456b-9754-6db86e0d1044.png"  width="300" height="200"/> 

---

## Solution 2. OLED display with pi-display

It is different from the first solution.   
If you want second solution,  `Please USE_SSD1306_128_32 = False`

1. Open terminal and commend following

```jsx
cd ~
git clone https://github.com/waveshare/pi-display
cd pi-display
sudo ./install.sh
```

2. Install

```jsx
sudo pip3 install flask
```

*CHECK POINT* 

`Enable ‘I2C’`

```jsx
sudo raspi-config
# -> activate 'Interface Options' -> 'I2C'
```

3. Execute python code


```jsx
cd pidisplay
python display_server.py
```
<img src="https://user-images.githubusercontent.com/81483791/194760821-30046ed9-ac2a-476f-90c7-6a7b0f26981e.png"  width="300" height="200"/>        

If you got a problem ‘line8’

Please change `from .utils` → `from utils`
- - -

## How to change display_server.py file

When I want to change display_server.py file,

I get this ERROR

```jsx
* Serving Flask app 'testpi'
 * Debug mode: on
Address already in use
Port 8000 is in use by another program. Either identify and stop that program, or start the server with a different port.
```

Because when I reboot piracer, this python file always auto execute.

We have this `picard_display.sevice` file

```jsx
[Unit]
Description=JetCard display service
[Service]
Type=simple
User=pi
ExecStart=/bin/sh -c "python3 -m pidisplay.testpi"
WorkingDirectory=/home/pi
Restart=always
[Install]
WantedBy=multi-user.target
```

And in our [install.sh](http://install.sh) file,

```jsx
echo $password | sudo -S mv picard_display.service /etc/systemd/system/picard_display.service
echo $password | sudo -S systemctl enable picard_display
echo $password | sudo -S systemctl start picard_display
```

`systemctl start picard_display`     
it makes auto execute

SO

1. Open terminal commend following

```jsx
sudo -S systemctl stop picard_display
```

2. Check status

```jsx
sudo -S systemctl status picard_display
```

3. Execute Modified python file

```jsx
python display_server.py
```

<img src="https://user-images.githubusercontent.com/81483791/194761110-5c7eef2f-9614-453d-bc89-6c313ffef107.png"  width="300" height="200"/>   
