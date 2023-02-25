# PiRacer Setup

## Contents  
- [Step 1: Create Donkeycar from Template](#step-1-create-donkeycar-from-template)  
- [Step 2: Web Control](#step-2-web-control)  
- [Step 3: Calibrate DonkeyCar](#step-3-calibrate-donkeycar)  
- [Step 4: Teleoperation ( Shanwan gamepad )](#step-4-teleoperation--shanwan-gamepad)
- [Step 5: piracer_py](#step-5-piracer_py)

---

<br/>

## Reference
- [Donkey Car Wiki](https://docs.donkeycar.com/guide/robot_sbc/setup_raspberry_pi/)
- [piracer_py](https://github.com/SEA-ME/piracer_py)

---

<br/>

## Step 1: Create Donkeycar from Template

1. Connect PiRacer by SSH

   ```bash
   ping <your hostname>.local
   ssh <username>@<your pi ip address>
   donkey createcar --path ~/mycar
   ```

<br/>

2. Configure I2C PCA9685 ( servo driver board )

    ```bash
    sudo apt-get install -y i2c-tools
    sudo i2cdetect -y 1
    ```

    <br/>

    If Pi doesn't display like below, exchange your **PiRacer expansion board**
    
    ```bash
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

<br/>  

## Step 2: Web Control

<img src="https://user-images.githubusercontent.com/111988634/189865372-29e46eb9-9c7a-4abf-a8f5-9ac2da8a535f.png"  width="300" height="200"/> 

1. Open Raspberry Pi terminal and run the follow commands
    
    ```bash
    source ~/env/bin/activate
    cd ~/mycar
    python manage.py drive
    ```

    <br/>
    
2. Go to `http://<raspberrypi_ip_address>:8887`
    
    <aside>
    :warning: If you connected with physical game controller, it overrides web control.
    
    </aside>
    
<br/>

## Step 3: Calibrate DonkeyCar

1. Adjust the value to make the servo turns to the center place and remember the value ( In our case, 380 was center )
    
    ```bash
    cd ~/mycar
    donkey calibrate --channel 0 --bus=1
    ```
    
    <br/>

1. Test if 280, and 480 can let the servo turns to the far left and the far right

    <br/>

1. Modify the config.py file and change variables
    
    ```bash
    sudo nano config.py
    # Change values
    # STEERING_LEFT_PWM = 480
    # STEERING_RIGHT_PWM = 280
    # THROTTLE_FORWARD_PWM = 500
    # THROTTLE_STOPPED_PWM = 370
    # THROTTLE_REVERSE_PWM = 220
    ```
    
<br/>

## Step 4: Teleoperation ( Shanwan gamepad )

<aside>
:warning: Nintendo Switch Pro Controller is compatible with  kernel version more than 5.16

</aside>

<img src="https://user-images.githubusercontent.com/111988634/189865479-05225856-e480-4b85-89c0-9c7b93fc58e7.png"  width="300" height="150"/> 

1. Connect game pad with PiRacer

<br/>

2. Create joystick creator wizard
    
    ```bash
    cd ~/mycar
    donkey createjs
    ```

<br/>
    
3. Map button, axis, control
In mapping steps of steering and throttle, you should set in opposite direction 
( For example, If you want to throttle Left Stick: Vertical, you need to register Right Stick: Horizontal in the throttle step )

<br/>

4. Change configuration
    
    ```bash
    cd ~/mycar
    sudo nano config.py
    # JOYSTICK_DEVICE_FIL = "/dev/input/js0"
    # CONTROLLER_TYPE = 'custom'
    ```

<br/>

## Step 5: piracer_py

https://github.com/SEA-ME/piracer_py

This is a pip package created by the SEA:ME fellow. The settings made above can be customized, but there are too many functions, so if you want to simply use the desired function, you can use the following package.

The installation method is well explained in the above Github.

Since we simply need the steering function, we use the following code. Its name is rc_example.py

```python
from piracer.vehicles import PiRacerPro
from piracer.gamepads import ShanWanGamepad

if __name__ == '__main__':

    shanwan_gamepad = ShanWanGamepad()
    piracer = PiRacerPro()
    # piracer = PiRacerStandard()

    while True:
        gamepad_input = shanwan_gamepad.read_data()

        throttle = gamepad_input.analog_stick_right.y * 0.5
        steering = -gamepad_input.analog_stick_left.x

        print(f'throttle={throttle}, steering={steering}')

        piracer.set_throttle_percent(throttle)
        piracer.set_steering_percent(steering)
```

Run it
```
python rc_example.py
```

When launched, it can be controlled with a gamepad.