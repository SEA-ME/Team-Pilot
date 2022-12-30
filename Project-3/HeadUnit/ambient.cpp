#include "ambient.h"
#include <QDebug>
#include <pigpio.h>

Ambient::Ambient(QObject *parent) : QObject(parent){
    if (gpioInitialise() < 0){
        return;
    }

    qDebug() << "Success GPIO Initiaialise";

    gpioSetMode(6,  PI_OUTPUT);
    gpioSetMode(13, PI_OUTPUT);
    gpioSetMode(19, PI_OUTPUT);
    gpioSetMode(26, PI_OUTPUT);
}

void Ambient::ambientSlot(const int &msg){

    qDebug() << "hello" << msg;
    if(msg == 0){
        gpioWrite(26, PI_HIGH);
        gpioWrite(6, PI_LOW);
        gpioWrite(13, PI_LOW);
        gpioWrite(19, PI_LOW);
    }
    else if (msg == 1) {
        gpioWrite(19, PI_HIGH);
        gpioWrite(6, PI_LOW);
        gpioWrite(13, PI_LOW);
        gpioWrite(26, PI_LOW);
    }
    else if (msg == 2) {
        gpioWrite(13, PI_HIGH);
        gpioWrite(6, PI_LOW);
        gpioWrite(19, PI_LOW);
        gpioWrite(26, PI_LOW);
    }
    else if (msg == 3){
        gpioWrite(6, PI_HIGH);
        gpioWrite(13, PI_LOW);
        gpioWrite(19, PI_LOW);
        gpioWrite(26, PI_LOW);
    }
    else{
        gpioWrite(6, PI_HIGH);
        gpioWrite(13, PI_LOW);
        gpioWrite(19, PI_LOW);
        gpioWrite(26, PI_LOW);
    }
}

Ambient::~Ambient(){
    gpioTerminate();
    qDebug() << "Terminated";
}
