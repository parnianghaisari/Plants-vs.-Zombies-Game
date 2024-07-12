QT       += core gui
QT       += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    astronautzombie.cpp \
    boomerangplant.cpp \
    bucketheadzombie.cpp \
    datahandeler.cpp \
    forgotwindow.cpp \
    gamehistory.cpp \
    gamelogichandling.cpp \
    globals.cpp \
    jalapeno.cpp \
    lastpage.cpp \
    leafheadzombie.cpp \
    loginwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    mainwindow2.cpp \
    peashooterplant.cpp \
    plant.cpp \
    plants.cpp \
    plummineplant.cpp \
    purplehairzombie.cpp \
    regularzombie.cpp \
    secondstrart.cpp \
    setting.cpp \
    signupwindow.cpp \
    startwindow.cpp \
    tallzombie.cpp \
    twopeashooterplant.cpp \
    walnutplant.cpp \
    zambiesgame.cpp \
    zombie.cpp

HEADERS += \
    astronautzombie.h \
    boomerangplant.h \
    bucketheadzombie.h \
    datahandeler.h \
    forgotwindow.h \
    gamehistory.h \
    gamelogichandling.h \
    globals.h \
    jalapeno.h \
    lastpage.h \
    leafheadzombie.h \
    loginwindow.h \
    mainwindow.h \
    mainwindow2.h \
    peashooterplant.h \
    plant.h \
    plants.h \
    plummineplant.h \
    purplehairzombie.h \
    regularzombie.h \
    secondstrart.h \
    setting.h \
    signupwindow.h \
    startwindow.h \
    tallzombie.h \
    twopeashooterplant.h \
    walnutplant.h \
    zambiesgame.h \
    zombie.h

FORMS += \
    forgotwindow.ui \
    gamehistory.ui \
    lastpage.ui \
    loginwindow.ui \
    mainwindow.ui \
    mainwindow2.ui \
    secondstrart.ui \
    setting.ui \
    signupwindow.ui \
    startwindow.ui \
    zambiesgame.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc
