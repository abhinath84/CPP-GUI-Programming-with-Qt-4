QT  +=core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

RESOURCES += \
    mdieditor.qrc

HEADERS += \
    cgmainwindow.h \
    cgeditor.h

SOURCES += \
    main.cpp \
    cgmainwindow.cpp \
    cgeditor.cpp
