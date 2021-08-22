#include "CEventHandler.h"
#include <QDebug>
#include "IActionInterface.h"

static const bool DEBUG_EVENT_HANDLER = true;

CEventHandler::CEventHandler(QObject *parent)
    : QObject(parent)
{

}

CEventHandler::~CEventHandler()
{

}

bool CEventHandler::hasAction() const
{
    for (IActionInterface* act : m_CurrentActions) {
        if (!act->isFinished())
            return true;
    }
    return false;
}

void CEventHandler::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (hasAction()) {
        getLastAction()->mousePressEvent(event);
    }
}

void CEventHandler::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (hasAction()) {
        getLastAction()->mouseMoveEvent(event);
    }
}

void CEventHandler::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if (hasAction()) {
        getLastAction()->mouseReleaseEvent(event);
    }
}

void CEventHandler::setCurrentAction(IActionInterface *action)
{
    if (DEBUG_EVENT_HANDLER) {
        qDebug() << __PRETTY_FUNCTION__;
    }
    if (!action)
        return;

    m_CurrentActions.push_back(action);
}

void CEventHandler::killAllActions()
{
    for (IActionInterface* act : m_CurrentActions) {
        act->finish();
    }
}

IActionInterface *CEventHandler::getLastAction() const
{
    return m_CurrentActions.last();
}
