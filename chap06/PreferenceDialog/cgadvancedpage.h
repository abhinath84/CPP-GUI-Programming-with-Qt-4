#ifndef CGADVANCEDPAGE_H
#define CGADVANCEDPAGE_H

#include <QWidget>

class QCheckBox;
class QGroupBox;
class QLineEdit;


class CGAdvancedPage : public QWidget
{
    Q_OBJECT
public:
    explicit CGAdvancedPage(QWidget *parent = nullptr);

signals:

public slots:

private:
    QGroupBox *featuresGroupBox;
    QCheckBox *javaCheckBox;
    QCheckBox *ftpCheckBox;
    QLineEdit *ftpLineEdit;
};

#endif // CGADVANCEDPAGE_H
