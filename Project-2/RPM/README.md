# Calculate PiRacer RPM

## Contents
- [Step 1: Calculate Vehicle Speed](#step-1-calculate-vehicle-speed)
- [Step 2: Calculate Motor Speed](#step-2-calculate-motor-speed)
- [Step 3: Calculate Crankshaft RPM](#step-3-calculate-crankshaft-rpm)
---

<br/>

## Reference
- [https://x-engineer.org/calculate-wheel-vehicle-speed-engine-speed/](https://x-engineer.org/calculate-wheel-vehicle-speed-engine-speed/)

- [https://www.circuitmagic.com/arduino/diy-digital-rpm-tachometer-with-arduino/](https://www.circuitmagic.com/arduino/diy-digital-rpm-tachometer-with-arduino/)

<br/>

## Step 1: Calculate Vehicle Speed
<img src="https://user-images.githubusercontent.com/111988634/200394017-5774316a-c24f-415b-8256-f2616bb5220f.png"  width="700" height="300"/>  

$ω_e$ *[rad/s]* – rotational speed of the engine

$ω_g$ *[rad/s]* – rotational speed of the gearbox output shaft speed

$ω_d$ *[rad/s]* – rotational speed of the differential crown wheel

$ω_r$ *[rad/s]* – rotational speed of the right wheel

$ω_l$ *[rad/s]* – rotational speed of the left wheel

$v_l$ *[m/s]* – linear speed of the left wheel

$v_r$ *[m/s]* – linear speed of the right wheel

$i_x$ *[-]* – gear ratio of the engaged gear

$i_0$ *[-]* – gear ratio of the differential

$r_w$ *[m]* – static radius of the wheel

PiRacer’s both wheels have the same radius This means that:

$$
ω_r=ω_l=ω_w
$$

where $ω_w$ *[rad/s]* is the common wheel rotational speed.

Since both vehicle and wheel move together, the vehicle speed is equal to the speed of the wheel. So if we calculate the wheel linear speed, we also have the vehicle’s speed.

Where $v_v$ is the vehicle speed and $v_w$ is the common wheel speed.

$$
v_r = v_l = v_w = v_v
$$

<img src="https://user-images.githubusercontent.com/111988634/200394023-34af13f2-a022-42ed-9b5f-ebb7c9cd4ee0.png"  width="500" height="400"/>  

The speed of the gearbox output shaft is equal with the engine speed divided by the gear ratio:

$$
w_g = \frac{w_e}{i_x}
$$

The rotational speed of the differential crown wheel is also reduced, being equal gearbox output shaft speed divided by the differential gear ratio:

$$
w_d = \frac{w_g}{i_o}
$$

The left and right wheel speeds are equal with the differential speed:

$$
w_r = w_l = w_d
$$

Combining all above equations, gives the formula for wheel speed function of engine speed:

$$
w_w = \frac{w_e}{i_x \times i_o}
$$

For engine speed, the conversion from *rpm* to *rad/s* is done as:

$$
w_e = \frac{N_e \times \pi}{30}
$$

Where $N_e$ is engine speed in [rpm].

The wheel’s linear speed is calculated function of rotational speed and radius as:

$$
v_w = w_w \times r_w
$$

Combining equations, gives the expression of the vehicle and wheel speed function of engine speed and gearbox and differential gear ratios:

$$
v_v[m/s] = v_w[m/s] = \frac{N_e \times \pi \times r_w}{30 \times i_x \times i_o}
$$

If we want to have the speed in [kph], the formula becomes:

$$
V_v[kph] = V_w[kph] = \frac{3.6 \times N_e \times \pi \times r_w}{30 \times i_x \times i_o}
$$

<br/>

## Step 2: Calculate Motor Speed

Due to the speed sensor’s structure, I could only find the rpm of the crankshaft.

$$
w_g = \frac{2\pi}{60} \times N_k
$$

Where $N_k$ is crankshaft speed in [rpm].

Then you can get $V_v$ using $N_k$, without engine speed $N_e$:

$$
N_e = \frac{30}{\pi} \times w_e
$$

$$
w_e = w_g \times i_x
$$

Combining equations, gives the formula for engine speed including crankshaft speed $N_k$:

$$
N_e = \frac{30}{\pi} \times w_g \times i_x
$$

$$
V_v[kph] = V_w[kph] = \frac{3.6 \times N_e \times \pi \times r_w}{30 \times i_x \times i_o} 
= \frac{3.6 \times \frac{\cancel{30}}{\cancel{\pi}}\times w_g \times \cancel{i_x} \times \cancel{\pi} \times r_w}{\cancel{30} \times \cancel{i_x} \times i_o}
$$

$$
\therefore V_v = \frac{3.6 \times w_g \times r_w}{i_o} = \frac{3.6 \times 2\pi\times N_k \times r_w}{60 \times i_o}
$$

<br/>

## Step 3: Calculate Crankshaft RPM
To get vehicle speed, we need below variables:
- $N_k$ *[rpm]* - rpm of crankshaft
- $i_o$ *[-]* – gear ratio of the differential
- $r_w$ *[m]* - radius of wheel

First, install pulse at the crankshaft to get the rpm.
For rpm of crankshaft, the formula is done as:
$$
N_k = \frac{60 \times pulse}{T_c \times PPR}
$$

Where $PPR$ is a Pulse per revolution. As you can see below, it is 4.

<img src="https://user-images.githubusercontent.com/111988634/200579087-736b044d-4d81-45f9-be5f-87ec76041ef3.jpg"  width="550" height="300"/> 

Where $T_c$ is a Time. In my case, I set in 1 second.

Second, count number of gear teeth to get gear ratio.
I counted number of differential gear teeth.
$$i_o = \frac {39}{11} \simeq 3.55$$
<img src="https://user-images.githubusercontent.com/111988634/200571585-28fb8837-ebbe-45d8-9db6-60468d070a11.jpg"  width="550" height="300"/>  
<img src="https://user-images.githubusercontent.com/111988634/200571589-b70595c8-6dd5-471c-9f3b-e688afd933f4.jpg"  width="550" height="300"/>  

Last, wheel radius is 2.3 cm, but it must be converted to meters:
$$r_w = 2.3 cm = 0.023 m$$

Now, I have all the variables I need for the equation:
$$N_k = \frac{60 \times pulse}{T_c \times PPR}$$
$$i_o = \frac {39}{11} \simeq 3.55 $$
$$r_w = 2.3 cm = 0.023 m$$

This is an arduino code to calculate the vehicle speed and rpm.
- ### [uno_rpm.ino](uno_rpm.ino)
<img src="https://user-images.githubusercontent.com/111988634/200611472-6d10c12e-b690-412f-a20f-c8b52aeb10ca.jpg"  width="550" height="300"/>  
<img src="https://user-images.githubusercontent.com/111988634/200611487-b496ad0b-4fba-4f3f-ac05-aeff1020b988.jpg"  width="550" height="300"/> 
 
If you want to get max RPM of motor, you should know $i_x$:

$$
i_x = \frac{50}{20} = 2.5
$$

Combining equations, gives the formula of engine RPM:

$$
\therefore N_e = N_k \times i_x = 2.5N_k
$$

So if you get max $N_k$, you can get $N_e$ by multiplying 2.5 at $N_k$.