######################################################################
# Automatically generated by qmake (2.01a) Fr 23. Okt 14:07:47 2009
######################################################################

CONFIG += release
CONFIG += console

TEMPLATE = app
TARGET = 
DEPENDPATH += .
INCLUDEPATH += .
QT += core gui xml opengl

OBJECTS_DIR = build
MOC_DIR = mocs
UI_DIR = uis

# Input
include(GLRender.pri)

HEADERS += \
    Animation.h \
    cube.h

SOURCES += \
    Animation.cpp \
    cube.cpp
