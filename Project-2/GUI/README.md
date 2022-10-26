# GUI

- Contents
    
    [Add GUI to Raspberry Pi OS Lite](#add-gui-to-raspberry-pi-os-lite)
    
    [Change VNC resolution](#change-vnc-resolution)
    
- - - 
- Reference
    
    [Add GUI to Raspberry Pi OS Lite](https://www.paulligocki.com/add-gui-to-raspberry-pi-os-lite/)
    
- - - 
## Add GUI to Raspberry Pi OS Lite

### 1. ****Update & Rebootd****

```jsx
sudo apt update && sudo apt upgrade && sudo apt dist-upgrade && sudo reboot
```

### 2. ****Install Xorg****

```jsx
sudo apt install xserver-xorg -y
```

### 3. **Install Desktop Environment PIXEL (default)**

```jsx
sudo apt install raspberrypi-ui-mods -y
```

### 4. ****MATE****

```jsx
sudo apt install mate-desktop-environment-core
```

### 5. ****KDE****

```jsx
sudo apt install kde-plasma-desktop -y
```

### 6. ****LXDE****

```jsx
sudo apt install lxde-core lxappearance -y
```

### 7. ****XFCE****

```jsx
sudo apt install xfce4 xfce4-terminal -y
```

### 8. ****Install Display Manage****

```jsx
sudo apt install lightdm -y
```

### 9. ****Reboot****

```jsx
sudo reboot
```

### 10. Using VNC

```jsx
sudo raspi-config
```

- enable `Interfacing Options` - `VNC`

### Trouble shooting

<img src="https://user-images.githubusercontent.com/81483791/198120354-8fd7c2e9-6795-429e-a66b-6cbe74a1bfd0.png"  width="300" height="200"/> 

→ Connect OLED display moniter

- - - 

## Change VNC resolution

### 1. Edit /boot/config.txt file

```jsx
sudo vim /boot/config.txt
```

Change this line.

```jsx
hdmi_force_hotplug=1
hdmi_group=2
hdmi_mode=82
hdmi_drive=2
```

### 2. raspi-config

```jsx
sudo raspi-config
```

`Display Options` → `D1 Resolution` → `DMT Mode 82 1920x1080 60Hz 16:9`

<img src="https://user-images.githubusercontent.com/81483791/198120360-9f6128b6-8e97-4e05-b228-43f4da0f68c6.png"  width="300" height="210"/> 
<img src="https://user-images.githubusercontent.com/81483791/198120372-a9c9b367-88ff-4687-83e9-8007231290e1.png"  width="300" height="210"/> 

### 3. Monitor Setting

`raspi icon` → `Preferences` → `KDE System Settings`

<img src="https://user-images.githubusercontent.com/81483791/198120380-008918ad-2f3c-4dc6-9b51-122fc787d892.png"  width="400" height="350"/> 
<img src="https://user-images.githubusercontent.com/81483791/198120416-a70a3222-65d7-4757-b6d8-d058bca60934.png"  width="400" height="300"/> 

### 4. reboot

```jsx
sudo reboot
```