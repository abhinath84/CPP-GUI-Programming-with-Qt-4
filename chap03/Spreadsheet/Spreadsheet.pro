QT  += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT  += widgets

HEADERS += \
    CGMainWindow \
    CGFindDialog \
    CGMenuActionData \
    CGGoToCellDialog \
    CGSortDialog

SOURCES += \
    CGMainWindow.cpp \
    main.cpp \
    CGFindDialog.cpp \
    CGMenuActionData.cpp \
    CGGoToCellDialog.cpp \
    CGSortDialog.cpp

RESOURCES += \
    spreadsheet.qrc
