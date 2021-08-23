#include "IActionFactory.h"

static QList<IActionFactory*> s_ActionInterfaceFactories;

const QList<IActionFactory *> IActionFactory::allActionFactories()
{
    return s_ActionInterfaceFactories;
}

IActionFactory::IActionFactory()
{
    s_ActionInterfaceFactories.append(this);
}

IActionFactory::~IActionFactory()
{
    s_ActionInterfaceFactories.removeOne(this);
}

QIcon IActionFactory::getIcon() const
{
    return m_icon;
}

void IActionFactory::setIcon(QIcon icon)
{
    m_icon = icon;
}
