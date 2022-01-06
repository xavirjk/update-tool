QT += gui core

TEMPLATE = lib
DEFINES += S_UPDATELIB_LIBRARY

DEFINES += QUAZIP_STATIC

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
DEFINES += QUAZIP_STATIC
INCLUDEPATH += source \
               "C:\Program Files (x86)\QuaZip\include\QuaZip-Qt6-1.2"

SOURCES += \
    source/controllers/commandcontroller.cpp \
    source/controllers/mastercontroller.cpp \
    source/models/s_updatelib.cpp

HEADERS += \
    source/controllers/commandcontroller.h \
    source/controllers/mastercontroller.h \
    source/controllers/navigationController.h \
    source/s_updateLib_global.h \
    source/models/s_updatelib.h

LIBS += -lz
LIBS += -L$$PWD/../shadow-builds/quazip -llibquazip1-qt6
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
