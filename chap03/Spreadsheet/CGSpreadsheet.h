#ifndef CGSPREADSHEET_H
#define CGSPREADSHEET_H

#include <QTableWidget>

class CGSpreadsheet : public QTableWidget
{
public:
    CGSpreadsheet(QWidget *parent = 0);

    bool autoRecalculate();
};

#endif // CGSPREADSHEET_H
