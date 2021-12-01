QT -= gui

TEMPLATE = lib
DEFINES += S_UPDATELIB_LIBRARY

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
INCLUDEPATH += source
SOURCES += \
    source/models/s_updatelib.cpp

HEADERS += \
    source/s_updateLib_global.h \
    source/models/s_updatelib.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
