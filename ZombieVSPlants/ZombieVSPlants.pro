QT       += core gui
QT       += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    board.cpp \
    datahandeler.cpp \
    forgotwindow.cpp \
    globals.cpp \
    loginwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    mainwindow2.cpp \
    plants.cpp \
    sensitiveblock.cpp \
    signupwindow.cpp \
    startwindow.cpp \
    zambiesgame.cpp

HEADERS += \
    board.h \
    datahandeler.h \
    forgotwindow.h \
    globals.h \
    loginwindow.h \
    mainwindow.h \
    mainwindow2.h \
    plants.h \
    sensitiveblock.h \
    signupwindow.h \
    startwindow.h \
    zambiesgame.h

FORMS += \
    forgotwindow.ui \
    loginwindow.ui \
    mainwindow.ui \
    mainwindow2.ui \
    plants.ui \
    signupwindow.ui \
    startwindow.ui \
    zambiesgame.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc
