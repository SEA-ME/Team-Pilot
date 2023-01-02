#include "vsomedata.h"
#include <CommonAPI/CommonAPI.hpp>
#include <QtQuick>

VsomeData::VsomeData(QObject *parent) :
    QObject(parent), qtspd(0), qtrpm(0), qttmp(0), qthum(0), qtbat(0), qtprnd(0),
    timer(std::make_shared<QTimer>())
{
    qRegisterMetaType<uint8_t>("uint8_t");
    qRegisterMetaType<int8_t>("int8_t");
    qRegisterMetaType<uint16_t>("uint16_t");

    std::shared_ptr<CommonAPI::Runtime> runtime = CommonAPI::Runtime::get();
    moonService = std::make_shared<HeadUnitStubImpl>();
    runtime->registerService("local", "headunit", moonService);

    std::cout << "Successfully Registered Service!" << std::endl;
    connect(timer.get(), SIGNAL(timeout()), this, SLOT(updateFunc()));
    timer->setInterval(1000);
    timer->start();
}

uint8_t VsomeData::getqthum() const
{
    return qthum;
}

int VsomeData::getqttmp() const
{
    return qttmp;
}

uint16_t VsomeData::getqtrpm() const
{
    return qtrpm;
}

uint8_t VsomeData::getqtspd() const
{
    return qtspd;
}

uint8_t VsomeData::getqtbat() const
{
    return qtbat;
}

uint8_t VsomeData::getqtprnd() const
{
    return qtprnd;
}

void VsomeData::setQthum(uint8_t value)
{
    if (qthum == value)
        return;
    qthum = value;
    emit qthumChanged();
}

void VsomeData::setQttmp(int value)
{
    if (qttmp == value)
        return;
    qttmp = value;
    emit qttmpChanged();
}

void VsomeData::setQtrpm(uint16_t value)
{
    if (qtrpm == value)
        return;
    qtrpm = value;
    emit qtrpmChanged();
}

void VsomeData::setQtspd(uint8_t value)
{
    if (qtspd == value)
        return;
    qtspd = value;
    emit qtspdChanged();
}

void VsomeData::setQtbat(uint8_t value)
{
    if (qtbat == value)
        return;
    qtbat = value;
    emit qtbatChanged();
}

void VsomeData::setQtprnd(uint8_t value)
{
    if (qtprnd == value)
        return;
    qtprnd = value;
    emit qtprndChanged();
}

void VsomeData::updateFunc()
{
    setQthum(moonService.get()->qt_HUM());
    setQttmp(moonService.get()->qt_TMP());
    setQtrpm(moonService.get()->qt_RPM());
    setQtspd(moonService.get()->qt_SPD());
    setQtbat(moonService.get()->qt_BAT());
    setQtprnd(moonService.get()->qt_PRND());
}

