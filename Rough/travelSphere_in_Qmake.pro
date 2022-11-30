QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    aftercompanylogin.cpp \
    booknow.cpp \
    chandragiri.cpp \
    contactus.cpp \
    hazarsidi.cpp \
    login2.cpp \
    main.cpp \
    loginpage.cpp \
    mainwindow.cpp \
    namobuddha.cpp \
    pokhara.cpp \
    profile.cpp \
    registeroption.cpp \
    registerpage.cpp \
    registryforcompanies.cpp

HEADERS += \
    aftercompanylogin.h \
    booknow.h \
    chandragiri.h \
    contactus.h \
    hazarsidi.h \
    login2.h \
    loginpage.h \
    mainwindow.h \
    namobuddha.h \
    pokhara.h \
    profile.h \
    registeroption.h \
    registerpage.h \
    registryforcompanies.h

FORMS += \
    aftercompanylogin.ui \
    booknow.ui \
    chandragiri.ui \
    contactus.ui \
    hazarsidi.ui \
    login2.ui \
    loginpage.ui \
    mainwindow.ui \
    namobuddha.ui \
    pokhara.ui \
    profile.ui \
    registeroption.ui \
    registerpage.ui \
    registryforcompanies.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    source.qrc
