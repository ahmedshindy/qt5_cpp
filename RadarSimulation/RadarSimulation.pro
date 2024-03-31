#-------------------------------------------------
#
# Project created by QtCreator 2024-03-30T01:03:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RadarSimulation
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    console.cpp \
    settingsdialog.cpp

HEADERS  += mainwindow.h \
    console.h \
    settingsdialog.h

FORMS    += mainwindow.ui
