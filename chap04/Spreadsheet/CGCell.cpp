#include <QtGui>
#include "CGCell.h"


CGCell::CGCell()
{
    setDirty();
}

QTableWidgetItem *CGCell::clone() const
{
    return new CGCell(*this);
}

void CGCell::setFormula(const QString &formula)
{
    setData(Qt::EditRole, formula);
}

QString CGCell::data(int role) const
{
    return( data(Qt::EditRole).toString() );
}

void CGCell::setData(int role, const QVariant &value)
{
    QTableWidgetItem::setData(role, value);
    if(role == Qt::EditRole)
        setDirty();
}

void CGCell::setDirty()
{
    cacheIsDirty = true;
}

QVariant CGCell::data(int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (value().isValid())
            return value().toString();
        else
            return "####";
    }
    else if (role == Qt::TextAlignmentRole)
    {
        if (value().type() == QVariant::String)
            return int(Qt::AlignLeft | Qt::AlignVCenter);
        else
            return int(Qt::AlignRight | Qt::AlignVCenter);
    }
    else
        return QTableWidgetItem::data(role);
}


const QVariant Invalid;

QVariant CGCell::value() const
{
    if (cacheIsDirty)
    {
        cacheIsDirty = false;
        QString formulaStr = formula();
        if (formulaStr.startsWith(’\’’))
        {
        cachedValue = formulaStr.mid(1);
        }
        else if (formulaStr.startsWith(’=’))
        {
            cachedValue = Invalid;
            QString expr = formulaStr.mid(1);
            expr.replace(" ", "");
            expr.append(QChar::Null);

            int pos = 0;
            cachedValue = evalExpression(expr, pos);
            if (expr[pos] != QChar::Null)
                cachedValue = Invalid;
        }
        else
        {
            bool ok;
            double d = formulaStr.toDouble(&ok);
            if (ok)
                cachedValue = d;
            else
                cachedValue = formulaStr;
        }
    }

    return cachedValue;
}
