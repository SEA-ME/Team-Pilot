// demo: CAN-BUS Shield, send data
// loovee@seeed.cc
#include "DHT.h"
#include <TimerOne.h>
#include <mcp_can.h>
#include <SPI.h>

#define DHTPIN 3     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11   // DHT 22  (AM2302), AM2321

DHT dht(DHTPIN, DHTTYPE);

// the cs pin of the version after v1.1 is default to D9
// v0.9b and v1.0 is default D10
const int SPI_CS_PIN = 10;
 
MCP_CAN CAN(SPI_CS_PIN);   // Set CS pin

int input = 0;
unsigned int counter=0;
unsigned char stmp[4] = {0,0,0,0};
float radius = 0.023;
float gear_ratio = 3.55;
float v;

void docount()  // counts from the speed sensor
{
  counter++;  // increase +1 the counter value
} 

void timerIsr()
{
  Timer1.detachInterrupt();  //stop the timer
  int rotation = (counter / 4);// divide by number of holes in Disc -> I used a disk with four holes

  int crank_rpm = rotation*60;
  int sp = (3.6 * TWO_PI * crank_rpm * radius) / (60 * gear_ratio);
  Serial.print("RPM = ");
  Serial.print(crank_rpm, DEC);                                        
  Serial.print(" Speed = ");
  Serial.print(sp, DEC);
  Serial.println(" km/h");
  stmp[2]=crank_rpm/100;
  stmp[3]=sp;
   
  counter=0;  //  reset counter to zero
  Timer1.attachInterrupt( timerIsr );  //enable the timer
}

void setup()
{
    Serial.begin(9600);
    dht.begin();
    pinMode(2, INPUT); //핀2를 입력값으로 받는다.
    
    Timer1.initialize(1000000); // set timer for 1sec
    attachInterrupt(0, docount, RISING);  // increase counter when speed sensor pin goes High
    Timer1.attachInterrupt( timerIsr ); // enable the timer
 
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


      float h = dht.readHumidity();
      float t = dht.readTemperature();
      
      stmp[0]=t;
      stmp[1]=h;    

    
    //send data:  id = 0x00, standrad frame, data len = 4, stmp: data buf

 
      CAN.sendMsgBuf(0x00, 0, 4, stmp);

   
}
// END FILE