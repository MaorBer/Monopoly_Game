QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    main.cpp \
    mainwindow.cpp \
    cppFiles/GameBoard.cpp \
    cppFiles/GameManager.cpp \
    cppFiles/Player.cpp \
    cppFiles/Slot.cpp \
    cppFiles/SpecialSlot.cpp \
    cppFiles/Street.cpp \
    cppFiles/Train.cpp

HEADERS += \
    mainwindow.h \
    hppFiles/GameBoard.hpp \
    hppFiles/GameManager.hpp \
    hppFiles/Player.hpp \
    hppFiles/Slot.hpp \
    hppFiles/SpecialSlot.hpp \
    hppFiles/Street.hpp \
    hppFiles/Train.hpp


FORMS += \
    mainwindow.ui

# Include the directories for headers and sources
INCLUDEPATH += hppFiles
DEPENDPATH += cppFiles

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
