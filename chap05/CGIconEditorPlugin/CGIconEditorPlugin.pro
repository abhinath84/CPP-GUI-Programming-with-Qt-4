QT  += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT  += widgets designer

TEMPLATE = lib
CONFIG += plugin
TARGET = CGIconEditorPlugin
DEPENDPATH += .
INCLUDEPATH += .

HEADERS += \
    ../CGIconEditor/CGIconEditor.h \
    CGIconEditorPlugin.h

SOURCES += \
    ../CGIconEditor/CGIconEditor.cpp \
    CGIconEditorPlugin.cpp

RESOURCES += \
    CGIconEditorPlugin.qrc

OTHER_FIFLES += CGIconEditor.json
