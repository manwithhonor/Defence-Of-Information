#-------------------------------------------------
#
# Project created by QtCreator 2015-09-17T11:45:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = string_transform
TEMPLATE = app
CONFIG += c++11

SOURCES += main.cpp\
    Cipher.cpp \
    Password.cpp \
    mainwindow.cpp \
    dialog2.cpp \
    dialog_for_admin.cpp \
    dialog_for_admin_1.cpp \
    administration.cpp \
    dialog_for_delete.cpp \
    dialog_if_match.cpp \
    dialog.cpp

HEADERS  += \
    Cipher.h \
    Config.h \
    Password.h \
    Mem_cleaning.h \
    mainwindow.h \
    dialog2.h \
    dialog_for_admin.h \
    dialog_for_admin_1.h \
    administration.h \
    dialog_for_delete.h \
    dialog_if_match.h \
    dialog.h

FORMS    += \
    mainwindow.ui \
    dialog2.ui \
    dialog_for_admin.ui \
    dialog_for_admin_1.ui \
    dialog_for_delete.ui \
    dialog_if_match.ui \
    dialog.ui
