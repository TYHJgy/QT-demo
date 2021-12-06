#include "qled.h"
#include "qledplugin.h"

#include <QtPlugin>

QLEDPlugin::QLEDPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void QLEDPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool QLEDPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *QLEDPlugin::createWidget(QWidget *parent)
{
    return new QLED(parent);
}

QString QLEDPlugin::name() const
{
    return QLatin1String("QLED");
}

QString QLEDPlugin::group() const
{
    return QLatin1String("");
}

QIcon QLEDPlugin::icon() const
{
    return QIcon(QLatin1String(":/LED.png"));
}

QString QLEDPlugin::toolTip() const
{
    return QLatin1String("");
}

QString QLEDPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool QLEDPlugin::isContainer() const
{
    return false;
}

QString QLEDPlugin::domXml() const
{
    return QLatin1String("<widget class=\"QLED\" name=\"qLED\">\n</widget>\n");
}

QString QLEDPlugin::includeFile() const
{
    return QLatin1String("qled.h");
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(qledplugin, QLEDPlugin)
#endif // QT_VERSION < 0x050000
