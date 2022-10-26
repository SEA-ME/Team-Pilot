// demo: CAN-BUS Shield, send data
// loovee@seeed.cc
 
#include <mcp_can.h>
#include <SPI.h>
#include <DHT.h> //Library for using DHT sensor

#define DHTPIN A0
#define DHTTYPE DHT11
#define CANBUS_LEN 6

const int HOLE = 2; // digital input
unsigned long millisBefore;
volatile int cnt; // count holes
uint16_t rpm = 12345;
uint8_t spd = 123;
unsigned char hi;
unsigned char lo;
uint8_t h;
int8_t t;
unsigned char stmp[CANBUS_LEN] = {0, 0, 0, 0, 0, 0};

// the cs pin of the version after v1.1 is default to D9
// v0.9b and v1.0 is default D10
const int SPI_CS_PIN = 10;
 
MCP_CAN CAN(SPI_CS_PIN);  // Set CS pin
DHT dht(DHTPIN, DHTTYPE); //initialize object dht for class DHT with DHT pin with STM32 and DHT type as DHT11 

void setup()
{
    Serial.begin(115200);
    SPI.begin(); //Begins SPI communication
    dht.begin(); //Begins to read temperature & humidity sensor value
 
    pinMode (HOLE, INPUT);
    attachInterrupt(digitalPinToInterrupt(HOLE), count, FALLING);
    while (CAN_OK != CAN.begin(CAN_500KBPS))              // init can bus : baudrate = 500k
    {
        Serial.println("CAN BUS Shield init fail");
        Serial.println(" Init CAN BUS Shield again");
        delay(100);
    }
    Serial.println("CAN BUS Shield init ok!");
}

void loop()
{
    h = dht.readHumidity(); //Gets Humidity value
    t = dht.readTemperature(); //Gets Temperature value

    // Caculate RPM
    /*
    if (millis() - millisBefore > 1000){
      rpm = (cnt/12.0) * 60;
      cnt = 0;
      millisBefore = millis();
    }*/
    lo = rpm & 0xFF;
    hi = rpm >> 8;
   
    stmp[0] = h;  // Humidity
    stmp[1] = t;  // Temperature
    stmp[2] = lo; // RPM1
    stmp[3] = hi; // RPM2
    stmp[4] = spd;

    CAN.sendMsgBuf(0x00, 0, CANBUS_LEN, stmp);
    delay(100);                       // send data per 100ms
}

void count()
{
    cnt++;
}
// END FILE
