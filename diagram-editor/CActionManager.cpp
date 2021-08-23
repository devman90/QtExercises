#include "CActionManager.h"
#include <QAction>
#include <QDebug>

#include "IDiagramEditorScene.h"
#include "IActionFactory.h"

static const bool DEBUG_ACTION_MANAGER = true;

CActionManager::CActionManager(QObject *parent)
    : IActionManager(parent)
{
    createActions();
}

QList<QAction *> CActionManager::getActions()
{
    return m_actions;
}

void CActionManager::setCurrentScene(IDiagramEditorScene *scene)
{
    IActionManager::setCurrentScene(scene);
}

void CActionManager::onActionTriggered()
{
    QAction* act = qobject_cast<QAction*>(sender());
    if (!act) {
        if (DEBUG_ACTION_MANAGER) {
            qDebug() << __FUNCTION__ << "sender() is not a QAction.";
        }
        return;
    }
    IActionFactory* fac = m_actionHash.value(act, nullptr);
    if (!fac) {
        if (DEBUG_ACTION_MANAGER) {
            qDebug() << __FUNCTION__ << "factory not found.";
        }
        return;
    }
    if (!m_scene) {
        if (DEBUG_ACTION_MANAGER) {
            qDebug() << __FUNCTION__ << "The scene is null.";
        }
        return;
    }

    if (DEBUG_ACTION_MANAGER) {
        qDebug() << "Action:" << fac->getName();
    }
    IActionInterface* actInterface = fac->create(m_scene);
    m_scene->setCurrentAction(actInterface);
}

void CActionManager::createActions()
{
    for (IActionFactory* fac : IActionFactory::allActionFactories()) {
        QAction* action = new QAction(this);
        action->setIcon(fac->getIcon());
        action->setText(fac->getName());
        connect(action, SIGNAL(triggered()), this, SLOT(onActionTriggered()));

        m_actionHash[action] = fac;
        m_actions << action;
    }
}
