#include "CGMenuActionData.h"

CGMenuActionData::CGMenuActionData()
    :parent(new QObject*[1]),
      receiver(new QObject*[1]),
      strText(""),
      strIcon(""),
      ksShortcut(),
      strStatusTip(""),
      strSignal(""),
      strSlot("")
{
}

CGMenuActionData::CGMenuActionData(QObject *parent)
    :parent(new QObject*[1]),
      receiver(new QObject*[1]),
      strText(""),
      strIcon(""),
      ksShortcut(),
      strStatusTip(""),
      strSignal(""),
      strSlot("")
{
    this->parent[0] = parent;
}

CGMenuActionData::CGMenuActionData(QObject *parent, const string &text, const string &icon,
                 const QKeySequence &shortcut, const string &statustip,
                 QObject *receiver, const string &signal, const string &slot)
    :parent(new QObject*[1]),
      receiver(new QObject*[1]),
      strText(text),
      strIcon(icon),
      ksShortcut(shortcut),
      strStatusTip(statustip),
      strSignal(signal),
      strSlot(slot)
{
    this->parent[0] = parent;
    this->receiver[0] = receiver;
}

CGMenuActionData::CGMenuActionData(const CGMenuActionData &other)
    :parent(new QObject*[1]),
      receiver(new QObject*[1]),
      strText(other.strText),
      strIcon(other.strIcon),
      ksShortcut(other.ksShortcut),
      strStatusTip(other.strStatusTip),
      strSignal(other.strSignal),
      strSlot(other.strSlot)
{
    this->parent[0] = other.parent[0];
    this->receiver[0] = other.receiver[0];
}

CGMenuActionData::~CGMenuActionData()
{
    delete[] parent;
    parent = 0;

    delete[] receiver;
    receiver = 0;
}

CGMenuActionData& CGMenuActionData::operator=(const CGMenuActionData &other)
{
    if(this != &other)
    {
        if(parent != NULL)
        {
            delete[] parent;
            parent = 0;
        }

        if(receiver != NULL)
        {
            delete[] receiver;
            receiver = 0;
        }

        parent = new QObject*[1];
        this->parent[0] = other.parent[0];

        receiver = new QObject*[1];
        this->receiver[0] = other.receiver[0];

        strText = other.strText;
        strIcon = other.strIcon;
        ksShortcut = other.ksShortcut;
        strStatusTip = other.strStatusTip;
        strSignal = other.strSignal;
        strSlot = other.strSlot;
    }

    return(*this);
}

void CGMenuActionData::setParent(QObject *parent)
{
    if(parent != NULL)
    {
        this->parent[0] = parent;
    }
}

QObject* CGMenuActionData::Parent() const
{
    return (this->parent[0]);
}

void CGMenuActionData::setReceiver(QObject *receiver)
{
    if(receiver != NULL)
    {
        this->receiver[0] = receiver;
    }
}

QObject* CGMenuActionData::Receiver() const
{
    return (this->receiver[0]);
}

void CGMenuActionData::setText(const string &text)
{
    if( !text.empty() )
        strText = text;
}

string CGMenuActionData::Text() const
{
    return(strText);
}

void CGMenuActionData::setIcon(const string &icon)
{
    if( !icon.empty() )
        strIcon = icon;
}

string CGMenuActionData::Icon() const
{
    return(strIcon);
}

void CGMenuActionData::setShortcut(const QKeySequence &shortcut)
{
    if( !shortcut.isEmpty() )
        ksShortcut = shortcut;
}

QKeySequence CGMenuActionData::Shortcut() const
{
    return(ksShortcut);
}

void CGMenuActionData::setStatusTip(const string &statustip)
{
    if( !statustip.empty() )
        strStatusTip = statustip;
}

string CGMenuActionData::StatusTip() const
{
    return(strStatusTip);
}

void CGMenuActionData::setSignal(const string &signal)
{
    if( !signal.empty() )
        strSignal = signal;
}

string CGMenuActionData::Signal() const
{
    return(strSignal);
}

void CGMenuActionData::setSlot(const string &slot)
{
    if( !slot.empty() )
        strSlot = slot;
}

string CGMenuActionData::Slot() const
{
    return(strSlot);
}

bool CGMenuActionData::isProper() const
{
    bool status = true;

    if((parent == 0) || (parent[0] == NULL))
        status = false;
    else if( strText.empty() )
        status = false;
    else if((receiver == 0) || (receiver[0] == NULL))
        status = false;
    else if( strSignal.empty() || strSlot.empty())
        status = false;

    return(status);
}

bool CGMenuActionData::setAction(QAction **action)
{
    bool status = false;

    if( ( action != NULL ) && ( isProper() ) )
    {
        *action = new QAction(QObject::tr(Text().c_str()), Parent());

        if( !strIcon.empty() )
            (*action)->setIcon(QIcon(Icon().c_str()));

        if( !ksShortcut.isEmpty() )
            (*action)->setShortcut(ksShortcut);

        if( !strStatusTip.empty() )
            (*action)->setStatusTip(QObject::tr(StatusTip().c_str()));

        QObject::connect(*action, Signal().c_str(),
                            Receiver(), Slot().c_str());
    }

    return(status);
}
