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

QString CGCell::formula() const
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
        QString formulaStr = this->formula();
        if (formulaStr.startsWith('\’'))
        {
        cachedValue = formulaStr.mid(1);
        }
        else if (formulaStr.startsWith('='))
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

QVariant CGCell::evalExpression(const QString &str, int &pos) const
{
    QVariant result = evalTerm(str, pos);
    while (str[pos] != QChar::Null)
    {
        QChar op = str[pos];
        if (op != '+' && op != '-')
            return result;
        ++pos;

        QVariant term = evalTerm(str, pos);
        if (result.type() == QVariant::Double
            && term.type() == QVariant::Double)
        {
            if (op == '+')
            {
                result = result.toDouble() + term.toDouble();
            }
            else
            {
                result = result.toDouble() - term.toDouble();
            }
        }
        else
        {
            result = Invalid;
        }
    }

    return result;
}

QVariant CGCell::evalTerm(const QString &str, int &pos) const
{
    QVariant result = evalFactor(str, pos);
    while (str[pos] != QChar::Null)
    {
        QChar op = str[pos];
        if (op != '*' && op != '/')
            return result;
        ++pos;

        QVariant factor = evalFactor(str, pos);
        if (result.type() == QVariant::Double
            && factor.type() == QVariant::Double)
        {
            if (op == '*')
            {
                result = result.toDouble() * factor.toDouble();
            }
            else
            {
                if (factor.toDouble() == 0.0)
                {
                    result = Invalid;
                }
                else
                {
                    result = result.toDouble() / factor.toDouble();
                }
            }
        }
        else
        {
            result = Invalid;
        }
    }

    return result;
}

QVariant CGCell::evalFactor(const QString &str, int &pos) const
{
    QVariant result;
    bool negative = false;

    if (str[pos] == '-')
    {
        negative = true;
        ++pos;
    }

    if (str[pos] == '(')
    {
        ++pos;
        result = evalExpression(str, pos);

        if (str[pos] != ')')
            result = Invalid;
        ++pos;
    }
    else
    {
        QRegExp regExp("[A-Za-z][1-9][0-9]{0,2}");
        QString token;

        while (str[pos].isLetterOrNumber() || str[pos] == '.')
        {
            token += str[pos];
            ++pos;
        }

        if (regExp.exactMatch(token))
        {
            int column = token[0].toUpper().unicode() - 'A';
            int row = token.mid(1).toInt() - 1;
            CGCell *c = static_cast<CGCell *>(tableWidget()->item(row, column));
            if (c)
            {
                result = c->value();
            }
            else
            {
                result = 0.0;
            }
        }
        else
        {
            bool ok;
            result = token.toDouble(&ok);
            if (!ok)
                result = Invalid;
        }
    }

    if (negative)
    {
        if (result.type() == QVariant::Double)
        {
            result = -result.toDouble();
        }
        else
        {
            result = Invalid;
        }
    }

    return result;
}
