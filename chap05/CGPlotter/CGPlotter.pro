QT +=core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

HEADERS += \
    CGPlotter.h \
    CGPlotSettings.h

SOURCES += \
    CGPlotter.cpp \
    CGPlotSettings.cpp \
    main.cpp

RESOURCES += \
    cgplotter.qrc

