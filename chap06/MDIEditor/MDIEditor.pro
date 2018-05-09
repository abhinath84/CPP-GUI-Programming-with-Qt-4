QT  +=core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

RESOURCES += \
    mdieditor.qrc

HEADERS += \
    editor.h \
    mainwindow.h

SOURCES += \
    editor.cpp \
    main.cpp \
    mainwindow.cpp
