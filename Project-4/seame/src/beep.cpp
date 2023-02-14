#include "beep.h"

Beep::Beep(QObject *parent) : QObject(parent) {
    if (-1 == wiringPiSetup()) {
        std::cout << "setup wiringPi failed!" << std::endl;
    } else {
        pinMode(BeepPin, OUTPUT);
        std::cout << "setup wiringPi success!" << std::endl;
    }
}

void Beep::ultrasonicBeepSlot(int msg) {
    if (msg == 1) {
        _beep(cL, 500);
    } else if (msg == 5) {
        _starwarsBeep();
    }
}

void Beep::_beep(unsigned int note, unsigned int duration) {
    long beepDelay = (long)(1000000 / note);
    long time = (long) ((duration * 1000) / (beepDelay * 2));
    for (int i=0; i < time; i++) {
        digitalWrite(BeepPin, LOW);
        delayMicroseconds(beepDelay);
        digitalWrite(BeepPin, HIGH);
        delayMicroseconds(beepDelay);
    }
}

void Beep::_starwarsBeep() {
    _beep( a, 500);
    _beep( a, 500);
    _beep( f, 350);
    _beep( cH, 150);

    _beep( a, 500);
    _beep( f, 350);
    _beep( cH, 150);
    _beep( a, 1000);
    _beep( eH, 500);

    _beep( eH, 500);
    _beep( eH, 500);
    _beep( fH, 350);
    _beep( cH, 150);
    _beep( gS, 500);

    _beep( f, 350);
    _beep( cH, 150);
    _beep( a, 1000);
    _beep( aH, 500);
    _beep( a, 350);

    _beep( a, 150);
    _beep( aH, 500);
    _beep( gHS, 250);
    _beep( gH, 250);
    _beep( fHS, 125);

    _beep( fH, 125);
    _beep( fHS, 250);

    delay(250);

    _beep( aS, 250);
    _beep( dHS, 500);
    _beep( dH, 250);
    _beep( cHS, 250);
    _beep( cH, 125);

    _beep( b, 125);
    _beep( cH, 250);

    delay(250);

//    _beep( f, 125);
//    _beep( gS, 500);
//    _beep( f, 375);
//    _beep( a, 125);
//    _beep( cH, 500);

//    _beep( a, 375);
//    _beep( cH, 125);
//    _beep( eH, 1000);
//    _beep( aH, 500);
//    _beep( a, 350);

//    _beep( a, 150);
//    _beep( aH, 500);
//    _beep( gHS, 250);
//    _beep( gH, 250);
//    _beep( fHS, 125);

//    _beep( fH, 125);
//    _beep( fHS, 250);

//    delay(250);

//    _beep( aS, 250);
//    _beep( dHS, 500);
//    _beep( dH, 250);
//    _beep( cHS, 250);
//    _beep( cH, 125);

//    _beep( b, 125);
//    _beep( cH, 250);

//    delay(250);

//    _beep( f, 250);
//    _beep( gS, 500);
//    _beep( f, 375);
//    _beep( cH, 125);
//    _beep( a, 500);

//    _beep( f, 375);
//    _beep( q, 125);
//    _beep( a, 1000);
}
