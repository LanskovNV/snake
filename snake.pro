TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

# openGL include
QT += gl
LIBS += /usr/lib/libglut.so /usr/lib/libGL.so

SOURCES += \
    src/main.c \
    src/queue.c \
    src/graphics.c \
    src/game.c \
    src/menu.c \
    src/timer.c

HEADERS += \
    src/queue.h \
    src/types.h \
    src/graphics.h \
    src/game.h \
    src/menu.h \
    src/timer.h
