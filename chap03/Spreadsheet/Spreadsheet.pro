QT  += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

HEADERS += \
    CGMainWindow \
    CGFindDialog \
    CGMenuActionData

SOURCES += \
    CGMainWindow.cpp \
    main.cpp \
    CGFindDialog.cpp \
    CGMenuActionData.cpp

RESOURCES += \
    spreadsheet.qrc
