// demo: CAN-BUS Shield, send data
// loovee@seeed.cc
 
#include <mcp_can.h>
#include <SPI.h>
 
// the cs pin of the version after v1.1 is default to D9
// v0.9b and v1.0 is default D10
const int SPI_CS_PIN = 9;
 
MCP_CAN CAN(SPI_CS_PIN);                                    // Set CS pin
 
void setup()
{
    Serial.begin(115200);
 
    while (CAN_OK != CAN.begin(CAN_500KBPS))              // init can bus : baudrate = 500k
    {
        Serial.println("CAN BUS Shield init fail");
        Serial.println(" Init CAN BUS Shield again");
        delay(100);
    }
    Serial.println("CAN BUS Shield init ok!");
}
 
unsigned char stmp[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    
void loop()
{   
  Serial.println("In loop");
  CAN.sendMsgBuf(0x00, 0, 8, stmp);
  delay(1000);
}
// END FILE