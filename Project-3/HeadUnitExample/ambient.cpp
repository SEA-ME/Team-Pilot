#include "ambient.h"
#include <QDebug>

Ambient::Ambient(QObject *parent) : QObject(parent){

}

void Ambient::ambientSlot(const QString &msg){
    qDebug() << "hello" << msg;
}
