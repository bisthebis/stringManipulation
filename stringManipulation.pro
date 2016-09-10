QT += core
QT -= gui

CONFIG += c++11

TARGET = stringManipulation
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    tests/test_qstring_qregex.cpp \
    lexer/tokentype.cpp \
    tests/test_tokentype.cpp

HEADERS += \
    catch.hpp \
    lexer/tokentype.h
