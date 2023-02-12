#include <mcp2515_can.h>
#include <SPI.h>
#include <DHT.h> //Library for using DHT sensor

#define DHTPIN A0
#define DHTTYPE DHT11
#define CANBUS_LEN 6

#define Echo_EingangsPin 7 // Echo input pin
#define Trigger_AusgangsPin 8 // Trigger output pin

// Required variables are defined
int maximumRange = 300;
int minimumRange = 2;
long distance;
long duration;

// RPM
const int encoder_pin = 2; // digital input
uint16_t crank_rpm;
volatile byte pulses;
unsigned long timeold;
unsigned int pulsesperturn = 4;
float radius = 0.023;
float gear_ratio = 3.55;
uint8_t spd;
unsigned char hi;
unsigned char lo;

// Humidity, Temperature
uint8_t h;
int8_t t;

// CANBUS
unsigned char sensor[CANBUS_LEN] = {0, 0, 0, 0, 0, 0};

// the cs pin of the version after v1.1 is default to D9
// v0.9b and v1.0 is default D10
const int SPI_CS_PIN = 10;

mcp2515_can CAN(SPI_CS_PIN);  // Set CS pin
DHT dht(DHTPIN, DHTTYPE); //initialize object dht for class DHT with DHT pin with STM32 and DHT type as DHT11

void counter() {
  pulses++;
}

void setup () {
  pinMode (Trigger_AusgangsPin, OUTPUT);
  pinMode (Echo_EingangsPin, INPUT);

  Serial.begin(115200);
  SPI.begin(); //Begins SPI communication
  dht.begin(); //Begins to read temperature & humidity sensor value

  pinMode (encoder_pin, INPUT);
  attachInterrupt(digitalPinToInterrupt(encoder_pin), counter, FALLING);
  pulses = 0;
  crank_rpm = 0;
  spd = 0;
  timeold = 0;

  // init can bus : baudrate = 500k
  while (CAN_OK != CAN.begin(CAN_500KBPS)) {
    Serial.println("CAN BUS Shield init fail");
    Serial.println(" Init CAN BUS Shield again");
    delay(100);
  }
  Serial.println("CAN BUS Shield init ok!");
}

void loop () {

  // Distance measurement is started by means of the 10us long trigger signal
  digitalWrite (Trigger_AusgangsPin, HIGH);
  delayMicroseconds (10);
  digitalWrite (Trigger_AusgangsPin, LOW);

  // Now we wait at the echo input until the signal has been activated
  // and then the time measured how long it remains activated
  duration = pulseIn (Echo_EingangsPin, HIGH);

  // Now the distance is calculated using the recorded time
  distance = duration / 58.2;

  // Check whether the measured value is within the permissible distance
  //  if (distance >= maximumRange || distance <= minimumRange)
  //  {
  //    // If not, an error message is output.
  //    Serial.println ("Distance outside the measuring range");
  //    Serial.println ("-----------------------------------");
  //  }
  //
  //  else
  //  {
  //    // The calculated distance is output in the serial output
  //    Serial.print ("The distance is:");
  //    Serial.print (distance);
  //    Serial.println ("cm");
  //    Serial.println ("-----------------------------------");
  //  }

  h = dht.readHumidity();    //Gets Humidity value
  t = dht.readTemperature(); //Gets Temperature value

  if (millis() - timeold >= 1000) {
    detachInterrupt(0);
    crank_rpm = (60 * 1000 / pulsesperturn ) / (millis() - timeold) * pulses;
    spd = (3.6 * TWO_PI * crank_rpm * radius) / (60 * gear_ratio);
    timeold = millis();
    pulses = 0;
    //    Serial.print("RPM = ");
    //    Serial.print(crank_rpm, DEC);
    //    Serial.print(" Speed = ");
    //    Serial.print(spd, DEC);
    //    Serial.println(" km/h");
    attachInterrupt(0, counter, FALLING);
  }

  lo = crank_rpm & 0xFF;
  hi = crank_rpm >> 8;

  sensor[0] = h;        // Humidity
  sensor[1] = t;        // Temperature
  sensor[2] = lo;       // RPM1
  sensor[3] = hi;       // RPM2
  sensor[4] = spd;      // Speed
  sensor[5] = distance; // Distance

  byte sndStat = CAN.sendMsgBuf(0x00, 0, CANBUS_LEN, sensor);
  if (sndStat == CAN_OK) {
    Serial.print("Success send data: ");
    for (int i = 0; i < CANBUS_LEN; i++)
    {
      Serial.print(sensor[i]);
      Serial.print(" ");
    }
    Serial.println();
  }
  else {
    Serial.println("Fail send data");
  }
  delay(100); // send data per 100ms
}
