TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    queue.c \
    graphics.c \
    game.c \
    menu.c \
    timer.c

# openGL include
QT += gl
LIBS += /usr/lib/libglut.so /usr/lib/libGL.so

HEADERS += \
    queue.h \
    types.h \
    graphics.h \
    game.h \
    menu.h \
    timer.h
