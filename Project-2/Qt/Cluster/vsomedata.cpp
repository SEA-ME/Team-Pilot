#include "vsomedata.h"
#include <CommonAPI/CommonAPI.hpp>
#include <QtQuick>
#include "canstubimpl.h"

VsomeData::VsomeData(QObject *parent) :
    QObject(parent), spd(0), rpm(0), tmp(0), hum(0), bat(0),
    timer(std::make_shared<QTimer>())
{
    std::shared_ptr<CommonAPI::Runtime> runtime = CommonAPI::Runtime::get<();
    moonService = std::make_shared<CANStubImpl>();
    runtime->registerService("local", "can", moonService);
    std::cout << "Successfully Registered Service!" << std::endl;
    connect(timer.get(), SIGNAL(timeout()), this, SLOT(updateFunc()));
    timer->setInterval(1000);
    timer->start();
}

uint8_t VsomeData::getHum() const
{
    return hum;
}

int8_t VsomeData::getTmp() const
{
    return tmp;
}

uint16_t VsomeData::getRpm() const
{
    return rpm;
}

uint8_t VsomeData::getSpd() const
{
    return spd;
}

uint8_t VsomeData::getBat() const
{
    return bat;
}

void VsomeData::setHum(uint8_t value)
{
    if (hum == value)
        return;
    spd = value;
    emit spdChanged();
}

void VsomeData::setTmp(int8_t value)
{
    if (tmp == value)
        return;
    tmp = value;
    emit tmpChanged();
}

void VsomeData::setRpm(uint16_t value)
{
    if (rpm == value)
        return;
    rpm = value;
    emit rpmchanged();
}

void VsomeData::setSpd(uint8_t value)
{
    if (spd == value)
        return;
    spd = value;
    emit spdChanged();
}

void VsomeData::setBat(uint8_t value)
{
    if (bat == value)
        return;
    bat = value;
    emit batChanged();
}

void VsomeData::updateFunc()
{
    setHum(moonService.get()->GetHUM());
    setTmp(moonService.get()->GetTMP());
    setRpm(moonService.get()->GetRPM());
    setSpd(moonService.get()->GetSPD());
    setBat(moonService.get()->GetBAT());
}

