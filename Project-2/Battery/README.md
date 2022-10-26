# Battery level

- Contents
    
    [How to Calculate battery level](#how-to-calculate-battery-level)
    
    [ina219 Using C](#1-ina219-using-c)
    
    [na219 using Python](#2-ina219-using-python)

- - -

## How to Calculate battery level

<img src="https://user-images.githubusercontent.com/81483791/194762686-8d460809-6a58-4587-b921-dea96e5f7d65.png"  width="400" height="300"/>       

8.4V, 18650 battery × 4

(two in parallel, two in series)

- series → **Voltage rise**
- parallel →**Ampere rise**

One battery has 4.2V | two in series -> total = 8.4V

4.2V = full charge

3V = discharge

nominal voltage 3.6~3.7V

### battery level = ( voltage - 6 ) /2.4 *100

If voltage is 8.4V, battery level is 100% 

If voltage is 6V, battery level is 0% 
- - -

## 1. ina219 Using C

[ina219 using C](https://kevinboone.me/pi-ina219.html?i=1) 

[git hub address Using C](https://github.com/kevinboone/pi-ina219)

```jsx
git clone https://github.com/kevinboone/pi-ina219.git
cd pi-ina219
make
cd build
gcc -o test main.o ina219.o
./test
```

OUTPUT:

<img src="https://user-images.githubusercontent.com/81483791/198119436-f2e6cc87-d877-4cdd-a20c-01345ecbea8a.png"  width="500" height="120"/>    

- - -   

## 2. ina219 using Python

[ina219 using Python](https://pypi.org/project/pi-ina219/)