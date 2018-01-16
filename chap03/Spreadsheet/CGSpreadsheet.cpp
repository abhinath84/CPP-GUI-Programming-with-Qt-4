#include "CGSpreadsheet.h"

CGSpreadsheet::CGSpreadsheet(QWidget *parent)
    :QTableWidget(parent)
{

}

bool CGSpreadsheet::autoRecalculate()
{
    return(true);
}
