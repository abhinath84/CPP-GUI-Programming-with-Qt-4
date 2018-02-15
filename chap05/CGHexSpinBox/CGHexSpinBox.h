#ifndef CGHEXSPINBOX_H
#define CGHEXSPINBOX_H

#include<QSpinBox>

class QRegExpValidator;

class CGHexSpinBox : public QSpinBox
{
    Q_OBJECT

public:
    CGHexSpinBox(QWidget *parent = 0);

protected:
    QValidator::State validate(QString &text, int &pos) const;
    int valueFromText(const QString &text) const;
    QString textFromValue(int value) const;

private:
    QRegExpValidator *regexpValidator;
};

#endif // CGHEXSPINBOX_H
