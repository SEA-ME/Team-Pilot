#ifndef AMBIENT_H
#define AMBIENT_H

#include <QObject>
#include <iostream>
#include <signal.h>
#include <softPwm.h>
#include <wiringPi.h>

#define RED   0
#define GREEN 1
#define BLUE  2
#define uchar unsigned char

class Ambient : public QObject
{
    Q_OBJECT
public:
    explicit Ambient(QObject *parent = nullptr);
    ~Ambient();

public slots:
    void ambientSlot(const int &msg);

private:
    void _ledColorSet(uchar r_val, uchar g_val, uchar b_val);
};

#endif // AMBIENT_H
