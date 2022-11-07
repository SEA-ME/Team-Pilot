# Calculate PiRacer RPM

## Contents
- [Calculate Vehicle Speed $V_v$](#calculate-vehicle-speed)
- [Calculate Motor Speed $N_e$](#calculate-motor-speed)
- [Calculate Crankshaft RPM $N_k$](#calculate-crankshaft-rpm)

---

<br/>

## Reference
- [https://x-engineer.org/calculate-wheel-vehicle-speed-engine-speed/](https://x-engineer.org/calculate-wheel-vehicle-speed-engine-speed/)

- [https://www.circuitmagic.com/arduino/diy-digital-rpm-tachometer-with-arduino/](https://www.circuitmagic.com/arduino/diy-digital-rpm-tachometer-with-arduino/)

<br/>

## Calculate Vehicle Speed $V_v$
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

## Calculate Motor Speed $N_e$

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

## Calculate Crankshaft RPM $N_k$