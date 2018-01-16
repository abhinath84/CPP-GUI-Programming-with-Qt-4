#include "CGMenuActionData"

CGMenuActionData::CGMenuActionData()
    :parent(new QObject*[1]),
      receiver(new QObject*[1]),
      strText(),
      strIcon(),
      strShortcut(),
      strStatusTip(),
      strSignal(),
      strSlot()
{
}

CGMenuActionData::CGMenuActionData(QObject *parent)
    :parent(new QObject*[1]),
      receiver(new QObject*[1]),
      strText(),
      strIcon(),
      strShortcut(),
      strStatusTip(),
      strSignal(),
      strSlot()
{
    this->parent[0] = parent;
}

CGMenuActionData::CGMenuActionData(QObject *parent, const QString &text, const QString &icon,
                 const QString &shortcut, const QString &statustip,
                 QObject *receiver,const QString &signal, const QString &slot)
    :parent(new QObject*[1]),
      receiver(new QObject*[1]),
      strText(text),
      strIcon(icon),
      strShortcut(shortcut),
      strStatusTip(statustip),
      strSignal(signal),
      strSlot(slot)
{
    this->parent[0] = parent;
    this->receiver[0] = receiver;
}

CGMenuActionData::CGMenuActionData(const CGMenuActionData &other)
    :parent(other.parent),
      receiver(other.receiver),
      strText(other.strText),
      strIcon(other.strIcon),
      strShortcut(other.strShortcut),
      strStatusTip(other.strStatusTip),
      strSignal(other.strSignal),
      strSlot(other.strSlot)
{
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
        parent = other.parent;
        receiver = other.receiver;

        strText = other.strText;
        strIcon = other.strIcon;
        strShortcut = other.strShortcut;
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

    if((parent == 0) || (parent[0] == NULL))
        status = false;
    if((receiver == 0) || (receiver[0] == NULL))
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

bool CGMenuActionData::setAction(QAction **action)
{
    bool status = false;

    if( ( action != NULL ) && ( isProper() ) )
    {
        *action = new QAction(QObject::tr(Text().toStdString().c_str()), Parent());
        (*action)->setIcon(QIcon(Icon().toStdString().c_str()));
        (*action)->setShortcut(QObject::tr(Shortcut().toStdString().c_str()));
        (*action)->setStatusTip(QObject::tr(StatusTip().toStdString().c_str()));
        QObject::connect(*action, Signal().toStdString().c_str(),
                Receiver(), Slot().toStdString().c_str());
    }

    return(status);
}
