#ifndef CGCELL_H
#define CGCELL_H

#include <QTableWidgetItem>


class CGCell : public QTableWidgetItem
{
public:
    Cell();
    QTableWidgetItem *clone() const;
    void setData(int role, const QVariant &value);
    QVariant data(int role) const;
    void setFormula(const QString &formula);
    QString formula() const;
    void setDirty();

private:
    QVariant value() const;
    QVariant evalExpression(const QString &str, int &pos) const;
    QVariant evalTerm(const QString &str, int &pos) const;
    QVariant evalFactor(const QString &str, int &pos) const;

private:
    mutable QVariant cachedValue;
    mutable bool cacheIsDirty;
};

#endif // CGCELL_H
