#ifndef VSOMEDATA_H
#define VSOMEDATA_H

#include <memory>
#include <QObject>
#include <CommonAPI/CommonAPI.hpp>
#include "canstubimpl.h"

class VsomeData : public QObject
{
    Q_OBJECT

    Q_PROPERTY(uint8_t  hum READ getHum WRITE setHum NOTIFY humChanged)
    Q_PROPERTY(int8_t   tmp READ getTmp WRITE setTmp NOTIFY tmpChanged)
    Q_PROPERTY(uint16_t rpm READ getRpm WRITE setRpm NOTIFY rpmChanged)
    Q_PROPERTY(uint8_t  spd READ getSpd WRITE setSpd NOTIFY spdChanged)
    Q_PROPERTY(uint8_t  bat READ getBat WRITE setBat NOTIFY batChanged)

public:
    explicit VsomeData(QObject *parent = 0);
    uint8_t  getHum() const;
    int8_t   getTmp() const;
    uint16_t getRpm() const;
    uint8_t  getSpd() const;
    uint8_t  getBat() const;

    void setHum(uint8_t  value);
    void setTmp(int8_t   value);
    void setRpm(uint16_t value);
    void setSpd(uint8_t  value);
    void setBat(uint8_t  value);

private:
    uint8_t  spd;
    int8_t   tmp;
    uint16_t rpm;
    uint8_t  spd;
    uint8_t  bat;

    std::shared_ptr<class QTimer> timer;
    std::shared_ptr<CANStubImpl> myService;

signals:
    void humChanged();
    void tmpChanged();
    void rpmChanged();
    void spdChanged();
    void batChanged();

public slots:
    void updateFunc();
};

#endif // VSOMEDATA_H
