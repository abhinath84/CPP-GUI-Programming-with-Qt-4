#include <QtGui>
#include "CGHexSpinBox.h"

CGHexSpinBox::CGHexSpinBox(QWidget *parent)
    :QSpinBox(parent)
{
    setRange(0, 255);
    regexpValidator = new QRegExpValidator(QRegExp("[0-9A-Fa-f]{1,8}"), this);
}

QValidator::State CGHexSpinBox::validate(QString &text, int &pos) const
{
    return(regexpValidator->validate(text, pos));
}

QString CGHexSpinBox::textFromValue(int value) const
{
    return QString::number(value, 16).toUpper();
}

int CGHexSpinBox::valueFromText(const QString &text) const
{
    bool ok;
    return text.toInt(&ok, 16);
}
