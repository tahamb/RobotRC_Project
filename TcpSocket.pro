#-------------------------------------------------
# MENEBHI Taha
# 14/11/2017
#
#-------------------------------------------------

QT       += core
QT       += network
QT       -= gui

TARGET = TcpSocket
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    mytcpsocket.cpp

HEADERS += \
    mytcpsocket.h
