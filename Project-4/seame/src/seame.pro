QT += quick

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
INCLUDEPATH += ../src-gen-seame/

SOURCES += \
        ../src-gen-seame/v1/commonapi/SEAMESomeIPDeployment.cpp \
        ../src-gen-seame/v1/commonapi/SEAMESomeIPProxy.cpp \
        ../src-gen-seame/v1/commonapi/SEAMESomeIPStubAdapter.cpp \
        ambient.cpp \
        beep.cpp \
        canclient.cpp \
        main.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
  ../src-gen-seame/v1/commonapi/SEAME.hpp \
  ../src-gen-seame/v1/commonapi/SEAMEProxy.hpp \
  ../src-gen-seame/v1/commonapi/SEAMEProxyBase.hpp \
  ../src-gen-seame/v1/commonapi/SEAMESomeIPDeployment.hpp \
  ../src-gen-seame/v1/commonapi/SEAMESomeIPProxy.hpp \
  ../src-gen-seame/v1/commonapi/SEAMESomeIPStubAdapter.hpp \
  ../src-gen-seame/v1/commonapi/SEAMEStub.hpp \
  ../src-gen-seame/v1/commonapi/SEAMEStubDefault.hpp \
  ambient.h \
  beep.h \
  canclient.h


unix:!macx: LIBS += -L$$PWD/../../../../build-commonapi/capicxx-core-runtime/build/ -lCommonAPI

INCLUDEPATH += $$PWD/../../../../build-commonapi/capicxx-core-runtime/include
DEPENDPATH += $$PWD/../../../../build-commonapi/capicxx-core-runtime/include

unix:!macx: LIBS += -L$$PWD/../../../../build-commonapi/vsomeip/build/ -lvsomeip3

INCLUDEPATH += $$PWD/../../../../build-commonapi/vsomeip/interface
DEPENDPATH += $$PWD/../../../../build-commonapi/vsomeip/interface

unix:!macx: LIBS += -L$$PWD/../../../../build-commonapi/capicxx-someip-runtime/build/ -lCommonAPI-SomeIP

INCLUDEPATH += $$PWD/../../../../build-commonapi/capicxx-someip-runtime/include
DEPENDPATH += $$PWD/../../../../build-commonapi/capicxx-someip-runtime/include

unix:!macx: LIBS += -L$$PWD/../../../../../../usr/local/lib/ -lwiringPi

INCLUDEPATH += $$PWD/../../../../../../usr/local/include
DEPENDPATH += $$PWD/../../../../../../usr/local/include
