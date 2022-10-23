# PiRacer Assemble
- ## Contents
[Assemble following guide](#assemble-following-guide)   
[Set up Raspberry PI](#set-up-raspberry-pi)   
[Create your car application](#create-your-car-application)

- - -

## Assemble following guide

[Piracer_pro_ai_kit-en2.pdf](https://www.waveshare.com/w/upload/a/a2/Piracer_pro_ai_kit-en2.pdf)
<img src="https://user-images.githubusercontent.com/81483791/194764230-e8d5ad55-4a40-456c-b0b6-a7f33b4bc8a9.png"  width="500" height="300"/>  

- - - 

## Set up Raspberry PI

[Donkey car reference](https://docs.donkeycar.com/guide/robot_sbc/setup_raspberry_pi/)

### 1. Download  [Raspian Legacy (Buster)](https://downloads.raspberrypi.org/raspios_oldstable_lite_armhf/images/raspios_oldstable_lite_armhf-2021-12-02/2021-12-02-raspios-buster-armhf-lite.zip)

### 2. Download [Raspberry pi imager](https://www.raspberrypi.com/software/)

<img src="https://user-images.githubusercontent.com/81483791/194764308-41d1e08e-e5cf-4242-9c2f-42e0e221507c.png"  width="400" height="250"/>  

- Choose OS → others → upload .img file

(We already downloaded .img file first step)

<img src="https://user-images.githubusercontent.com/81483791/194764297-70ca6927-d730-4958-9e6a-884a40c0b081.png"  width="400" height="250"/>  

- Set up Wifi , SSH

You can change your hostname and username , password this step.

### 3. Connect Moniter with raspberry pi

```jsx
ifconfig
```

You can find your raspberry pi IP.

### 4. Connect SSH

```jsx
ssh -Y pi@10.12.248.219  # username@ip 
```

### 5. Change sudo raspi-config

```jsx
sudo raspi-config
```

<img src="https://user-images.githubusercontent.com/81483791/194764300-4a482b35-f2db-47e4-885e-ceaa9c738f16.png"  width="400" height="250"/>  

- enable `Interfacing Options` - `I2C`
- enable `Interfacing Options` - `SSH`
- enable `Interfacing Options` - `SPI`
- enable `Interfacing Options` - `Camera`
- select `Advanced Options` - `Expand Filesystem`     


Choose `finish` and `reboot` .

### 6. ****Update and Upgrade****

```jsx
sudo apt-get update --allow-releaseinfo-change
sudo apt-get upgrade
```

### 7. ****Install Dependencies****

```jsx
sudo apt-get install build-essential python3 python3-dev python3-pip python3-virtualenv python3-numpy python3-picamera python3-pandas python3-rpi.gpio i2c-tools avahi-utils joystick libopenjp2-7-dev libtiff5-dev gfortran libatlas-base-dev libopenblas-dev libhdf5-serial-dev libgeos-dev git ntp
```

### 8. ****(Optional) Install OpenCV Dependencies****

```jsx
sudo apt-get install libilmbase-dev libopenexr-dev libgstreamer1.0-dev libjasper-dev libwebp-dev libatlas-base-dev libavcodec-dev libavformat-dev libswscale-dev libqtgui4 libqt4-test
```

### 9. ****Setup Virtual Env****

```jsx
python3 -m virtualenv -p python3 env --system-site-packages
echo "source ~/env/bin/activate" >> ~/.bashrc
source ~/.bashrc
```

### 10. ****Install Donkeycar Python Code****

```jsx
mkdir projects
cd projects
```

```jsx
git clone https://github.com/autorope/donkeycar
cd donkeycar
git checkout main
pip install -e .[pi]
pip install https://github.com/lhelontra/tensorflow-on-arm/releases/download/v2.2.0/tensorflow-2.2.0-cp37-none-linux_armv7l.whl
```

You can validate your tensorflow install with

```jsx
python -c "import tensorflow; print(tensorflow.__version__)"
```

### 11. ****(Optional) Install OpenCV****

```jsx
sudo apt install python3-opencv
```

Then test to see if import succeeds.

```jsx
python -c "import cv2"
```
- - -
## ****Create your car application****

### 1. ****Create Donkeycar from Template****

Create a set of files to control your Donkey with this command:

```jsx
donkey createcar --path ~/mycar
```

### 2. ****Configure I2C PCA9685****

```jsx
sudo apt-get install -y i2c-tools
sudo i2cdetect -y 1
```

OUTPUT:

```jsx
0  1  2  3  4  5  6  7  8  9  a  b  c  d  e  f
00:          -- -- -- -- -- -- -- -- -- -- -- -- --
10: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
20: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
30: -- -- -- -- -- -- -- -- -- -- -- -- 3c -- -- --
40: 40 -- 42 -- -- -- -- -- -- -- -- -- -- -- -- --
50: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
60: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
70: 70 -- -- -- -- -- -- --
```

If you have same error like this:

<img src="https://user-images.githubusercontent.com/81483791/194764304-efa046f0-1836-4aae-99e6-679bd9f83380.png"  width="400" height="250"/>  

You should check your hardware!!