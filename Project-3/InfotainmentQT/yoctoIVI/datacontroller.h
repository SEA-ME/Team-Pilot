#ifndef DATACONTROLLER_H
#define DATACONTROLLER_H

#include <memory>
#include <QObject>
#include <CommonAPI/CommonAPI.hpp>
#include "ipcstubimpl.h"


class DataController : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int speed READ getSpeed WRITE setSpeed NOTIFY speedChanged)
    Q_PROPERTY(int rpm READ getRpm WRITE setRpm NOTIFY rpmChanged)
    Q_PROPERTY(int temperature READ getTemperature WRITE setTemperature NOTIFY tempChanged)
    Q_PROPERTY(int humidity READ getHumidity WRITE setHumidity NOTIFY humChanged)
    Q_PROPERTY(int battery READ getBattery WRITE setBattery NOTIFY batteryChanged)

public:
    explicit DataController(QObject *parent = 0);
    int getSpeed() const;
    void setSpeed(int value);

    int getRpm() const;
    void setRpm(int value);

    int getTemperature() const;
    void setTemperature(int value);

    int getHumidity() const;
    void setHumidity(int value);

    int getBattery() const;
    void setBattery(int value);

private:
    int speed;
    int rpm;
    int temperature;
    int humidity;
    int battery;

    std::shared_ptr<class QTimer> timer;
    std::shared_ptr<IpcStubImpl> myService;

signals:
    void speedChanged();
    void rpmChanged();
    void tempChanged();
    void humChanged();
    void batteryChanged();


public slots:
    void updateFunc();
};

#endif // DATACONTROLLER_H
