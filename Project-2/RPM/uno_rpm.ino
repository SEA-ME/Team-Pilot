#include <SPI.h>

int encoder_pin = 2;
uint16_t rpm;
volatile byte pulses;
unsigned long timeold;
unsigned int pulsesperturn = 1;
int v;

void counter() {
  pulses++;
}

void setup() {
    Serial.begin(9600);
    pinMode(encoder_pin, INPUT);
    attachInterrupt(0, counter, FALLING);
    
    pulses = 0;
    rpm = 0;
    v= 0;
    timeold = 0;
}

void loop() {
    if (millis() - timeold >= 1000){
        detachInterrupt(0);
        rpm = (60 * 1000 / pulsesperturn ) / (millis() - timeold) * pulses;
        v = (3.6 * 2 * 3.14 * rpm * 2.25 * 0.01) / (60 * 4);
        timeold = millis();
        pulses = 0;
        Serial.print("RPM = ");
        Serial.print(rpm, DEC);
        Serial.print(" Speed = ");
        Serial.println(v, DEC);
        attachInterrupt(0, counter, FALLING);
    }
}
