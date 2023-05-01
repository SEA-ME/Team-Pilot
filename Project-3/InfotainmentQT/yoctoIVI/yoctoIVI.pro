TEMPLATE = app

QT += qml quick
CONFIG += c++11
_ROOT = $$_PRO_FILE_PWD_
INCLUDEPATH += src-gen/

SOURCES += main.cpp \


RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \



DISTFILES += \
    Background.qml \
    PRND.qml


