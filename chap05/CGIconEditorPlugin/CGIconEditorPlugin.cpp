#include <QtPlugin>
#include <QIcon>

#include "../CGIconEditor/CGIconEditor.h"
#include "CGIconEditorPlugin.h"

CGIconEditorPlugin::CGIconEditorPlugin(QObject *parent)
    :QObject(parent)
{
}

/*
 * Returns the name of the widget provided by the plugin
*/
QString CGIconEditorPlugin::name() const
{
    return ("CGIconEditor");
}

/*
 * Returns the name of the header file for the specified
 * widget encapsulated by the plugin. The header file is included in the code
 * generated by the uic tool.
*/
QString CGIconEditorPlugin::includeFile() const
{
    return "CGIconEditor.h";
}

/*
 * Returns the name of the widget box group this custom
 * widget should belong to. If the name isn’t already in use, Qt Designer will
 * create a new group for the widget.
*/
QString CGIconEditorPlugin::group() const
{
    return tr("Image Manipulation Widgets");
}

/*
 * Returns the icon to use to represent the custom widget in
 * Qt Designer’s widget box. Here, we assume that the IconEditorPlugin has an
 * associated Qt resource file with a suitable entry for the icon editor image.
*/
QIcon CGIconEditorPlugin::icon() const
{
    return QIcon(":/images/iconeditor.png");
}

/*
 * Returns the tooltip to show when the mouse hovers over
 * the custom widget in Qt Designer’s widget box.
*/
QString CGIconEditorPlugin::toolTip() const
{
    return tr("An icon editor widget");
}

/*
 * Returns the “What’s This?” text for Qt Designer to display.
*/
QString CGIconEditorPlugin::whatsThis() const
{
    return tr("This widget is presented in Chapter 5 of <i>C++ GUI "
                "Programming with Qt 4</i> as an example of a custom Qt widget.");
}

/*
 * returns true if the widget can contain other wid-
 * gets; otherwise, it returns false . For example, QFrame is a widget that can contain
 * other widgets. In general, any Qt widget can contain other widgets, but
 * Qt Designer disallows this when isContainer() returns false .
*/
bool CGIconEditorPlugin::isContainer() const
{
    return false;
}

/*
 * called by Qt Designer to create an instance of a widget
 * class with the given parent.
*/
QWidget* CGIconEditorPlugin::createWidget(QWidget *parent)
{
    return new CGIconEditor(parent);
}

/*
 * At the end of the source file that implements the plugin class, we must use the
 * Q_EXPORT_PLUGIN2() macro to make the plugin available to Qt Designer. The first
 * argument is the name we want to give the plugin; the second argument is the
 * name of the class that implements it.
*/
//Q_EXPORT_PLUGIN2(cgiconeditorplugin, CGIconEditorPlugin)
