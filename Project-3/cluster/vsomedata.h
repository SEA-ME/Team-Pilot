#ifndef VSOMEDATA_H
#define VSOMEDATA_H

#include <memory>
#include <QObject>
#include <CommonAPI/CommonAPI.hpp>
#include "headunitstubimpl.h"

class VsomeData : public QObject
{
    Q_OBJECT

    Q_PROPERTY(uint8_t  qthum READ getqthum WRITE setQthum NOTIFY qthumChanged)
    Q_PROPERTY(int   qttmp READ getqttmp WRITE setQttmp NOTIFY qttmpChanged)
    Q_PROPERTY(uint16_t qtrpm READ getqtrpm WRITE setQtrpm NOTIFY qtrpmChanged)
    Q_PROPERTY(uint8_t  qtspd READ getqtspd WRITE setQtspd NOTIFY qtspdChanged)
    Q_PROPERTY(uint8_t  qtbat READ getqtbat WRITE setQtbat NOTIFY qtbatChanged)
    Q_PROPERTY(uint8_t qtprnd READ getqtprnd WRITE setQtprnd NOTIFY qtprndChanged)

public:
    explicit VsomeData(QObject *parent = 0);
    uint8_t  getqthum() const;
    int   getqttmp() const;
    uint16_t getqtrpm() const;
    uint8_t  getqtspd() const;
    uint8_t  getqtbat() const;
    uint8_t getqtprnd() const;

    void setQthum(uint8_t  value);
    void setQttmp(int   value);
    void setQtrpm(uint16_t value);
    void setQtspd(uint8_t  value);
    void setQtbat(uint8_t  value);
    void setQtprnd(uint8_t value);

private:
    uint8_t  qthum;
    int   qttmp;
    uint16_t qtrpm;
    uint8_t  qtspd;
    uint8_t  qtbat;
    uint8_t qtprnd;

    std::shared_ptr<class QTimer> timer;
    std::shared_ptr<HeadUnitStubImpl> moonService;

signals:
    void qthumChanged();
    void qttmpChanged();
    void qtrpmChanged();
    void qtspdChanged();
    void qtbatChanged();
    void qtprndChanged();

public slots:
    void updateFunc();
};

#endif // VSOMEDATA_H
