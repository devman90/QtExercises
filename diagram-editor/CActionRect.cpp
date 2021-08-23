#include "CActionRect.h"
#include <QPolygonF>
#include <QPainter>
#include <QPixmap>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsRectItem>

#include "CPreviewItem.h"
#include "IDiagramEditorScene.h"

CActionRect::CActionRect(IDiagramEditorScene *scene)
    : IPreviewActionInterface(scene)
{

}

void CActionRect::finish()
{

}

void CActionRect::trigger()
{
    IPreviewActionInterface::trigger();
    QRectF rect(m_TopLeft, m_BottomRight);
    rect = rect.normalized();
    m_pScene->addItem(new QGraphicsRectItem(rect));
    setStatus(SetTopLeft);
}

void CActionRect::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

}

void CActionRect::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QPointF mousePos = event->scenePos();
    if (getStatus() == SetBottomRight) {
        deletePreview();
        m_pPreview->addItem(new QGraphicsRectItem(QRectF(m_TopLeft, mousePos).normalized()));
        drawPreview();
    }
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

CActionRectFactory::CActionRectFactory()
{
    createIcon();
}

QString CActionRectFactory::getName() const
{
    return "Rectangle";
}

IActionInterface *CActionRectFactory::create(IDiagramEditorScene *scene)
{
    return new CActionRect(scene);
}

void CActionRectFactory::createIcon()
{
    QPolygonF polygon;
    polygon << QPointF(-100, +100)
            << QPointF(+100, +100)
            << QPointF(+100, -100)
            << QPointF(-100, -100)
            << QPointF(-100, +100);
    QPixmap pixmap(256, 256);
    pixmap.fill(Qt::transparent);
    QPainter painter(&pixmap);
    painter.setPen(QPen(Qt::black, 8));
    painter.translate(128, 128);
    painter.drawPolyline(polygon);
    setIcon(QIcon(pixmap));
}
