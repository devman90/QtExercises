#include "CActionRect.h"
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsRectItem>

#include "IDiagramEditorScene.h"

CActionRect::CActionRect(IDiagramEditorScene *scene)
    : IActionInterface(scene)
{

}

void CActionRect::finish()
{

}

void CActionRect::trigger()
{
    IActionInterface::trigger();
    m_pScene->addItem(new QGraphicsRectItem(QRectF(m_TopLeft, m_BottomRight)));
    setStatus(SetTopLeft);
}

void CActionRect::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

}

void CActionRect::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{

}

void CActionRect::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() != Qt::LeftButton)
        return;
    if (getStatus() == SetTopLeft) {
        m_TopLeft = event->scenePos();
        setStatus(SetBottomRight);
    } else if (getStatus() == SetBottomRight) {
        m_BottomRight = event->scenePos();
        trigger();
    }
}
