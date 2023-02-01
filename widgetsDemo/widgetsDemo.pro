QT       += core gui sql widgets serialport charts axcontainer
QT       += network opengl
QT       += multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    audiorecorderform.cpp \
    client.cpp \
    codeuiform.cpp \
    customtabstyle.cpp \
    customwidgetform.cpp \
    dataanalyzeform.cpp \
    databaseOperation.cpp \
    dialogSerial.cpp \
    dialoglogin.cpp \
    exceldemoform.cpp \
    fileoperationform.cpp \
    gsform.cpp \
    ledform.cpp \
    main.cpp \
    mainwindow.cpp \
    mainwindowdemo.cpp \
    meiliform.cpp \
    mouserightdemoform.cpp \
    musicplayerform.cpp \
    mybutton.cpp \
    myudpdemoform.cpp \
    progressdialog.cpp \
    progressdialog2.cpp \
    qsimpleled.cpp \
    rsdemoform.cpp \
    server.cpp \
    slavethread.cpp \
    styledemoform.cpp \
    sysmanageform.cpp \
    tableform.cpp \
    tabwidget.cpp \
    tcpdemoform.cpp \
    themewidget.cpp \
    thirddform.cpp \
    udpclientform.cpp \
    udptestform.cpp \
    user.cpp

HEADERS += \
    audiorecorderform.h \
    client.h \
    codeuiform.h \
    customtabstyle.h \
    customwidgetform.h \
    dataanalyzeform.h \
    databaseOperation.h \
    dialogSerial.h \
    dialoglogin.h \
    exceldemoform.h \
    fileoperationform.h \
    gsform.h \
    ledform.h \
    mainwindow.h \
    mainwindowdemo.h \
    meiliform.h \
    mouserightdemoform.h \
    musicplayerform.h \
    mybutton.h \
    myudpdemoform.h \
    progressdialog.h \
    progressdialog2.h \
    qsimpleled.h \
    rsdemoform.h \
    server.h \
    slavethread.h \
    styledemoform.h \
    sysmanageform.h \
    tableform.h \
    tabwidget.h \
    tcpdemoform.h \
    themewidget.h \
    thirddform.h \
    udpclientform.h \
    udptestform.h \
    user.h

FORMS += \
    audiorecorderform.ui \
    codeuiform.ui \
    customwidgetform.ui \
    dataanalyzeform.ui \
    dialoglogin.ui \
    exceldemoform.ui \
    fileoperationform.ui \
    gsform.ui \
    ledform.ui \
    mainwindow.ui \
    mainwindowdemo.ui \
    meiliform.ui \
    mouserightdemoform.ui \
    musicplayerform.ui \
    myudpdemoform.ui \
    progressdialog.ui \
    rsdemoform.ui \
    styledemoform.ui \
    sysmanageform.ui \
    tableform.ui \
    tabwidget.ui \
    tcpdemoform.ui \
    themewidget.ui \
    thirddform.ui \
    udpclientform.ui \
    udptestform.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    img.qrc
