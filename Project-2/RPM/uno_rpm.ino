#include <SPI.h>

int encoder_pin = 2;
uint16_t crank_rpm;
volatile byte pulses;
unsigned long timeold;
unsigned int pulsesperturn = 4;
float radius = 0.023;
float gear_ratio = 3.55;
float v;

void counter() {
  pulses++;
}

void setup() {
    Serial.begin(9600);
    pinMode(encoder_pin, INPUT);
    attachInterrupt(0, counter, FALLING);
    
    pulses = 0;
    crank_rpm = 0;
    v= 0;
    timeold = 0;
}

void loop() {
    if (millis() - timeold >= 1000){
        detachInterrupt(0);
        crank_rpm = (60 * 1000 / pulsesperturn ) / (millis() - timeold) * pulses;
        v = (3.6 * TWO_PI * crank_rpm * radius) / (60 * gear_ratio);
        timeold = millis();
        pulses = 0;
        Serial.print("RPM = ");
        Serial.print(crank_rpm, DEC);
        Serial.print(" Speed = ");
        Serial.print(v, DEC);
        Serial.println(" km/h");
        attachInterrupt(0, counter, FALLING);
    }
}
