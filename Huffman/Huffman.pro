#-------------------------------------------------
#
# Project created by QtCreator 2015-12-11T15:55:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Huffman
TEMPLATE = app
CONFIG += c++11


SOURCES += main.cpp\
        huffman_window.cpp \
    window_for_more.cpp \
    coding.cpp \
    decoding.cpp

HEADERS  += huffman_window.h \
    window_for_more.h

FORMS    += huffman_window.ui \
    window_for_more.ui
