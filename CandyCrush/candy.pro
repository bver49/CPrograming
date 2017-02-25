
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Candycrush
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    tile.cpp

HEADERS  += widget.h \
    tile.h

FORMS    += widget.ui \



RESOURCES += \
    tile.qrc
