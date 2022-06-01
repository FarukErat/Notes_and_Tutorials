QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    menu.cpp

HEADERS += \
    mainwindow.hpp \
    menu.hpp

FORMS += \
    mainwindow.ui \
    menu.ui

RESOURCES += \
    res

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    res/black.bmp \
    res/empty.bmp \
    res/icon.png \
    res/legal_black.bmp \
    res/legal_white.bmp \
    res/white.bmp
