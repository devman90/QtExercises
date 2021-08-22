#include "IActionInterface.h"
#include <QMouseEvent>

IActionInterface::IActionInterface(IDiagramEditorScene *scene)
    : m_bFinished(false)
    , m_pScene(scene)
    , m_nStatus(0)
{
}

IActionInterface::~IActionInterface()
{

}

int IActionInterface::getStatus() const
{
    return m_nStatus;
}

void IActionInterface::setStatus(int status)
{
    m_nStatus = status;
    if (m_nStatus < 0) {
        finish();
    }
}

bool IActionInterface::isFinished() const
{
    return m_bFinished;
}

void IActionInterface::finish()
{
    m_nStatus = -1;
    m_bFinished = true;
}

void IActionInterface::trigger()
{

}

void IActionInterface::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

}

void IActionInterface::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{

}

void IActionInterface::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{

}
