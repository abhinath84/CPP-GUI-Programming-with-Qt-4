QT  += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT  += widgets

HEADERS += \
    CGFindDialog.h \
    CGGoToCellDialog.h \
    CGMainWindow.h \
    CGMenuActionData.h \
    CGSortDialog.h \
    CGSpreadsheet.h

SOURCES += \
    CGMainWindow.cpp \
    main.cpp \
    CGFindDialog.cpp \
    CGMenuActionData.cpp \
    CGGoToCellDialog.cpp \
    CGSortDialog.cpp \
    CGSpreadsheet.cpp

RESOURCES += \
    spreadsheet.qrc
