#include "CGMenuActionData"

CGMenuActionData::CGMenuActionData()
    :parent(new QObject()),
      receiver(new QObject()),
      strText(),
      strIcon(),
      strShortcut(),
      strStatusTip(),
      strSignal(),
      strSlot()
{
}

CGMenuActionData::CGMenuActionData(QObject *parent)
    :parent(new QObject()),
      receiver(new QObject()),
      strText(),
      strIcon(),
      strShortcut(),
      strStatusTip(),
      strSignal(),
      strSlot()
{
    parent = parent;
    receiver = 0;
}

CGMenuActionData::CGMenuActionData(QObject *parent, const QString &text, const QString &icon,
                 const QString &shortcut, const QString &statustip,
                 QObject *receiver,const QString &signal, const QString &slot)
    :parent(new QObject()),
      receiver(new QObject()),
      strText(text),
      strIcon(icon),
      strShortcut(shortcut),
      strStatusTip(statustip),
      strSignal(signal),
      strSlot(slot)
{
    parent = parent;
    receiver = receiver;
}

CGMenuActionData::CGMenuActionData(const CGMenuActionData &other)
    :parent(new QObject()),
      receiver(new QObject()),
      strText(other.strText),
      strIcon(other.strIcon),
      strShortcut(other.strShortcut),
      strStatusTip(other.strStatusTip),
      strSignal(other.strSignal),
      strSlot(other.strSlot)
{
    parent = *other.parent;
    receiver = *other.receiver;
}

CGMenuActionData::~CGMenuActionData()
{
    if(parent != NULL)
    {
        delete parent;
        parent = 0;
    }

    if(receiver != NULL)
    {
        delete receiver;
        parent = 0;
    }
}

CGMenuActionData& CGMenuActionData::operator=(const CGMenuActionData &other)
{
    if(parent != NULL)
    {
        delete parent;
        parent = 0;
    }

    if(receiver != NULL)
    {
        delete receiver;
        receiver = 0;
    }

    parent = new QObject();
    parent = *other.parent;

    receiver = new QObject();
    receiver = *other.receiver;

    strText = other.strText;
    strIcon = other.strIcon;
    strShortcut = other.strShortcut;
    strStatusTip = other.strStatusTip;
    strSignal = other.strSignal;
    strSlot = other.strSlot;
}

void CGMenuActionData::setParent(QObject *parent)
{
    if(parent != NULL)
        this->parent = parent;
}

QObject* CGMenuActionData::Parent() const
{
    return (*parent);
}

void CGMenuActionData::setReceiver(QObject *receiver)
{
    if(receiver != NULL)
        this->receiver = receiver;
}

QObject* CGMenuActionData::Receiver() const
{
    return (*receiver);
}

void CGMenuActionData::setText(const QString &text)
{
    if( !text.isEmpty() )
        strText = text;
}

QString CGMenuActionData::Text() const
{
    return(strText);
}

void CGMenuActionData::setIcon(const QString &icon)
{
    if( !icon.isEmpty() )
        strIcon = icon;
}

QString CGMenuActionData::Icon() const
{
    return(strIcon);
}

void CGMenuActionData::setShortcut(const QString &shortcut)
{
    if( !shortcut.isEmpty() )
        strShortcut = shortcut;
}

QString CGMenuActionData::Shortcut() const
{
    return(strShortcut);
}

void CGMenuActionData::setStatusTip(const QString &statustip)
{
    if( !statustip.isEmpty() )
        strStatusTip = statustip;
}

QString CGMenuActionData::StatusTip() const
{
    return(strStatusTip);
}

void CGMenuActionData::setSignal(const QString &signal)
{
    if( !signal.isEmpty() )
        strSignal = signal;
}

QString CGMenuActionData::Signal() const
{
    return(strSignal);
}

void CGMenuActionData::setSlot(const QString &slot)
{
    if( !slot.isEmpty() )
        strSlot = slot;
}

QString CGMenuActionData::Slot() const
{
    return(strSlot);
}

bool CGMenuActionData::isProper() const
{
    bool status = true;

    if((parent == NULL) && (*parent != NULL))
        status = false;
    if((receiver == NULL) && (*receiver != NULL))
        status = false;

    if( strText.isEmpty())
        status = false;
    if( strIcon.isEmpty())
        status = false;
    if( strShortcut.isEmpty())
        status = false;
    if( strStatusTip.isEmpty())
        status = false;
    if( strSignal.isEmpty())
        status = false;
    if( strSlot.isEmpty())
        status = false;

    return(status);
}
