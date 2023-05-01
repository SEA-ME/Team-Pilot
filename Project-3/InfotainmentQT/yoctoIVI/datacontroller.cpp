#include "datacontroller.h"
#include <CommonAPI/CommonAPI.hpp>
#include <QtQuick>
#include "ipcstubimpl.h"
using namespace std;

DataController::DataController(QObject *parent) :
    QObject(parent),speed(0),rpm(0),temperature(0),humidity(0),battery(0),
    timer(std::make_shared<QTimer>())
{
    std::shared_ptr<CommonAPI::Runtime> runtime = CommonAPI::Runtime::get();

    myService = std::make_shared<IpcStubImpl>();

    runtime->registerService("local", "test", myService);
    std::cout << "Successfully Registered Service!" << std::endl;

    connect(timer.get(),SIGNAL(timeout()),this,SLOT(updateFunc()));
    timer->setInterval(1000);
    timer->start();

}

int DataController::getSpeed() const
{
    return speed;
}

void DataController::setSpeed(int value)
{
    if(speed == value )
        return;
    speed = value;
    emit speedChanged();
}

int DataController::getRpm() const
{
    return rpm;
}

void DataController::setRpm(int value)
{
    if(rpm == value)
        return;
    rpm = value;
    emit rpmChanged();
}

int DataController::getTemperature() const
{
    return temperature;
}

void DataController::setTemperature(int value)
{
    if(temperature == value || value >= 50 || value < -20)
        return;
    temperature = value;
    emit tempChanged();
}

int DataController::getHumidity() const
{
    return humidity;
}

void DataController::setHumidity(int value)
{
    if(humidity == value|| value >= 100)
        return;
    humidity = value;
    emit humChanged();
}

int DataController::getBattery() const
{
    return battery;
}

void DataController::setBattery(int value)
{
    if(battery == value|| value >= 100|| value < 0)
        return;
    battery = value;
    emit batteryChanged();
}

void DataController::updateFunc()
{
    setSpeed(myService.get()->getSPD());
    setRpm(myService.get()->getRPM());
    setTemperature(myService.get()->getTMP());
    setHumidity(myService.get()->getHUM());
    setBattery(myService.get()->getBAT());

}
