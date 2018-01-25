#include <QtGui>

#include "CGCell.h"
#include "CGSpreadsheet.h"


CGSpreadsheet::CGSpreadsheet(QWidget *parent)
    :QTableWidget(parent),
      autoRecalc(true)
{
    setItemPrototype(new CGCell());
    setSelectionMode(ContiguousSelection);

    connect(this, &CGSpreadsheet::itemChanged,
            this, &CGSpreadsheet::somethingChanged);

    clear();
}

bool CGSpreadsheet::autoRecalculate() const
{
    return autoRecalc;
}

void CGSpreadsheet::clear()
{
    setRowCount(0);
    setColumnCount(0);
    setRowCount(RowCount);
    setColumnCount(ColumnCount);

    for (int i = 0; i < ColumnCount; ++i)
    {
        QTableWidgetItem *item = new QTableWidgetItem;
        item->setText(QString(QChar(’A’ + i)));
        setHorizontalHeaderItem(i, item);
    }

    setCurrentCell(0, 0);
}

CGCell *CGSpreadsheet::cell(int row, int column) const
{
    return ( static_cast<CGCell *>(item(row, column)) );
}

QString CGSpreadsheet::text(int row, int column) const
{
    CGCell *c = cell(row, column);

    if (c)
        return c->text();
    else
        return "";
}

QString CGSpreadsheet::formula(int row, int column) const
{
    CGCell *c = cell(row, column);

    if (c)
        return c->formula();
    else
        return "";
}

void CGSpreadsheet::setFormula(int row, int column, const QString &formula)
{
    CGCell *c = cell(row, column);
    if (!c)
    {
        c = new CGCell();
        setItem(row, column, c);
    }

    c->setFormula(formula);
}

QString CGSpreadsheet::currentLocation() const
{
    return QChar(’A’ + currentColumn())
            + QString::number(currentRow() + 1);
}

QString CGSpreadsheet::currentFormula() const
{
    return formula(currentRow(), currentColumn());
}

void CGSpreadsheet::somethingChanged()
{
    if (autoRecalc)
        recalculate();

    emit modified();
}
