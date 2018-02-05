#ifndef CGSPREADSHEET_H
#define CGSPREADSHEET_H

#include <QTableWidget>

class CGCell;
class CGSpreadsheetCompare;


class CGSpreadsheet : public QTableWidget
{
    Q_OBJECT

public:
    CGSpreadsheet(QWidget *parent = 0);

    bool autoRecalculate() const;
    QString currentLocation() const;
    QString currentFormula() const;
    QTableWidgetSelectionRange selectedRange() const;
    void clear();
    bool readFile(const QString &fileName);
    bool writeFile(const QString &fileName);
    void sort(const CGSpreadsheetCompare &compare);

public slots:
    void cut();
    void copy();
    void paste();
    void del();
    void selectCurrentRow();
    void selectCurrentColumn();
    void recalculate();
    void setAutoRecalculate(bool recalc);
    void findNext(const QString &str, Qt::CaseSensitivity cs);
    void findPrevious(const QString &str, Qt::CaseSensitivity cs);

private slots:
    void somethingChanged();

signals:
    void modified();

private:
    CGCell *cell(int row, int column) const;
    QString text(int row, int column) const;
    QString formula(int row, int column) const;
    void setFormula(int row, int column, const QString &formula);

private:
    enum { MagicNumber = 0x7F51C883, RowCount = 999, ColumnCount = 26 };
    bool autoRecalc;
};

class CGSpreadsheetCompare
{
    public:
    bool operator()(const QStringList &row1, const QStringList &row2) const;

    enum { KeyCount = 3 };
    int keys[KeyCount];
    bool ascending[KeyCount];
};

#endif // CGSPREADSHEET_H
