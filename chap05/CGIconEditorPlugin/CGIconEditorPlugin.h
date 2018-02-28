#ifndef CGICONEDITORPLUGIN_H
#define CGICONEDITORPLUGIN_H

#include <QtUiPlugin/QDesignerCustomWidgetInterface>

class CGIconEditorPlugin : public QObject,
                           public QDesignerCustomWidgetInterface
{
    Q_OBJECT
    Q_INTERFACES(QDesignerCustomWidgetInterface)

public:
    CGIconEditorPlugin(QObject *parent = nullptr);

    QString name() const;
    QString includeFile() const;
    QString group() const;
    QIcon icon() const;
    QString toolTip() const;
    QString whatsThis() const;
    bool isContainer() const;
    QWidget *createWidget(QWidget *parent);
};

#endif // CGICONEDITORPLUGIN_H
