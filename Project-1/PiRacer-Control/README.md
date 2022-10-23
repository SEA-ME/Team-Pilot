# PiRacer Control

- ## Reference site
[PiRacer Pro AI Kit](https://www.waveshare.com/wiki/PiRacer_Pro_AI_Kit)   
- - -
- ## Contents
[Calibrate Donkey car](#calibrate-donkey-car)   
[Web Control](#web-control)   
[Teleoperation](#teleoperation)

- - -
## Calibrate Donkey car
### 1. Calibrate

```jsx
cd ~/mycar
donkey calibrate --channel 0 --bus=1
```

Check middle : 360

            right : 260

            left : 460

OUTPUT:

```jsx
Enter a PWM setting to test ('q' for quit) (0-1500): 360
Enter a PWM setting to test ('q' for quit) (0-1500): 260
Enter a PWM setting to test ('q' for quit) (0-1500): 460
```

### 2. Edit [config.py](http://config.py) file

```jsx
cd ~/mycar
vim config.py
```

Change `STEERING_LEFT_PWM` , `STEERING_RIGHT_PWM` 

```jsx
STEERING_CHANNEL = 0            #(deprecated) channel on the 9685 pwm board 0-15
STEERING_LEFT_PWM = 460         #pwm value for full left steering
STEERING_RIGHT_PWM = 260        #pwm value for full right steering
THROTTLE_CHANNEL = 0            #(deprecated) channel on the 9685 pwm board 0-15
THROTTLE_FORWARD_PWM = 500      #pwm value for max forward throttle
THROTTLE_STOPPED_PWM = 370      #pwm value for no movement
THROTTLE_REVERSE_PWM = 220      #pwm value for max reverse throttle
```
- - -

## Web Control



```jsx
python manage.py drive
```

Open the Chrome in host pc and go to http://<raspberrypi_ip_address>:8887

[`http://10.12.248.219:8887`](http://10.12.248.219:8887/drive)

<img src="https://user-images.githubusercontent.com/81483791/194764670-3f6d9f52-9b9a-4c10-9f14-919ac2dd5d1b.png"  width="500" height="300"/> 


- - - 
## Teleoperation


```jsx
cd ~/mycar
python manage.py drive --js
```

or 

We can change `USE_JOYSTICK_AS_DEFAULT = True`

```jsx
#JOYSTICK
USE_JOYSTICK_AS_DEFAULT = True      #when starting the manage.py, when True, will not require a --js option to use the joystick
JOYSTICK_MAX_THROTTLE = 0.5         #this scalar is multiplied with the -1 to 1 throttle value to limit the maximum throttle. This can help if you drop the controller or just don't need the full speed available.
JOYSTICK_STEERING_SCALE = 1.0       #some people want a steering that is less sensitve. This scalar is multiplied with the steering -1 to 1. It can be negative to reverse dir.
AUTO_RECORD_ON_THROTTLE = True      #if true, we will record whenever throttle is not zero. if false, you must manually toggle recording with some other trigger. Usually circle button on joystick.
CONTROLLER_TYPE = 'xbox'            #(ps3|ps4|xbox|pigpio_rc|nimbus|wiiu|F710|rc3|MM1|custom) custom will run the my_joystick.py controller written by the `donkey createjs` command
USE_NETWORKED_JS = False            #should we listen for remote joystick control over the network?
NETWORK_JS_SERVER_IP = None         #when listening for network joystick control, which ip is serving this information
JOYSTICK_DEADZONE = 0.01            # when non zero, this is the smallest throttle before recording triggered.
JOYSTICK_THROTTLE_DIR = -1.0         # use -1.0 to flip forward/backward, use 1.0 to use joystick's natural forward/backward
USE_FPV = False                     # send camera data to FPV webserver
JOYSTICK_DEVICE_FILE = "/dev/input/js0" # this is the unix file use to access the joystick.
```

It is maybe hard to control. 

So, we can change this control key.

 ---

### 1. Connect joystick with Piracer     
           

### 2. Create joystick creator wizard

```jsx
cd ~/mycar
donkey createjs
```

### 3. Map button, axis, control
- Button Map    
Set joystick button name.    
<img src="https://user-images.githubusercontent.com/81483791/197397574-a809ec35-74ec-46b6-9389-e5c08760d17d.png"  width="500" height="250"/> 

-  Axis Map    
Set joystick axis. We have 4 axis here.
<img src="https://user-images.githubusercontent.com/81483791/197397585-26a99d37-c0c7-442b-9899-47e81c402dc8.png"  width="500" height="350"/> 
- Control Map
<img src="https://user-images.githubusercontent.com/81483791/197397592-38d44e51-e921-4523-9093-bfd740f104bc.png"  width="500" height="400"/> 
<img src="https://user-images.githubusercontent.com/81483791/197397450-465a2782-8411-4bfa-9662-f58d1ebc32bb.png"  width="300" height="220"/> 

OUTPUT:    

<img src="https://user-images.githubusercontent.com/81483791/194764792-723a088f-4cf3-48fc-b8f2-7d7ec72b433e.png"  width="500" height="250"/> 

### 4. Edit [config.py](http://config.py) file

```jsx
CONTROLLER_TYPE = 'custom' 
```
