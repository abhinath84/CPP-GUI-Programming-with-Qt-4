#ifndef CGMENUACTIONDATA_H
#define CGMENUACTIONDATA_H

#include <string>

#include <QObject>
#include <QAction>
#include <QKeySequence>

using std::string;

class CGMenuActionData
{
public:
    CGMenuActionData();
    CGMenuActionData(QObject *parent);
    CGMenuActionData(QObject *parent, const string &text, const string &icon,
                     const QKeySequence &shortcut, const string &statustip,
                     QObject *receiver,const string &signal, const string &slot);
    CGMenuActionData(const CGMenuActionData &other);
    ~CGMenuActionData();

    CGMenuActionData& operator=(const CGMenuActionData &other);

public:
    void setParent(QObject *parent);
    QObject* Parent() const;

    void setReceiver(QObject *receiver);
    QObject* Receiver() const;

    void setText(const string &text);
    string Text() const;

    void setIcon(const string &icon);
    string Icon() const;

    void setShortcut(const QKeySequence &shortcut);
    QKeySequence Shortcut() const;

    void setStatusTip(const string &statustip);
    string StatusTip() const;

    void setSignal(const string &signal);
    string Signal() const;

    void setSlot(const string &slot);
    string Slot() const;

    bool isProper() const;

    bool setAction(QAction **action);

private:
    QObject         **parent;
    QObject         **receiver;
    string          strText;
    string          strIcon;
    QKeySequence    ksShortcut;
    string          strStatusTip;
    string          strSignal;
    string          strSlot;
};

#endif // CGMENUACTIONDATA
