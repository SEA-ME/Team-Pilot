#include "ambient.h"

Ambient::Ambient(QObject *parent) : QObject(parent)
{
    if (-1 == wiringPiSetup()) {
        std::cout << "setup wiringPi failed!" << std::endl;
    } else {
        softPwmCreate(RED, 0, 0xff);
        softPwmCreate(GREEN, 0, 0xff);
        softPwmCreate(BLUE, 0, 0xff);

        delay(1000);
        printf("LED Initialization complete\n");
    }
}

Ambient::~Ambient() {
    // Turn off LED
    // Don't understand why, but ledColorSet(0,0,0); doesn't work
    pinMode(RED, OUTPUT);
    digitalWrite(RED, LOW);
    pinMode(GREEN, OUTPUT);
    digitalWrite(GREEN, LOW);
    pinMode(BLUE, OUTPUT);
    digitalWrite(BLUE, LOW);

    std::cout << "Exiting..." << std::endl;
    exit(0);
}

void Ambient::ambientSlot(const int &msg) {
    if (msg == 0)      m_ledColorSet(0x00,0x00,0xff);   //blue P
    else if (msg == 1) m_ledColorSet(0xff,0x00,0x00);   //red R
    else if (msg == 2) m_ledColorSet(0xff,0xa5,0x00);   //orange N
    else if (msg == 3) m_ledColorSet(0x00,0xff,0x00);   //green D
    else               m_ledColorSet(0,0,0);
}

void Ambient::m_ledColorSet(uchar r_val, uchar g_val, uchar b_val) {
    softPwmWrite(RED,   r_val);
    softPwmWrite(GREEN, g_val);
    softPwmWrite(BLUE,  b_val);
}
