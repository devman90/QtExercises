#include "CActionSelectSingle.h"
#include <QDebug>
#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include "IDiagramEditorScene.h"

CActionSelectSingle::CActionSelectSingle(IDiagramEditorScene *scene)
    : IActionInterface(scene)
{

}

void CActionSelectSingle::trigger()
{
    qDebug() << "Selected:" << item;
}

void CActionSelectSingle::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        QPointF pos = event->scenePos();
        item = m_pScene->itemAt(pos);
        trigger();
    }
}

CActionSelectSingleFactory::CActionSelectSingleFactory()
{
    createIcon();
}

QString CActionSelectSingleFactory::getName() const
{
    return "Select single";
}

IActionInterface *CActionSelectSingleFactory::create(IDiagramEditorScene *scene)
{
    return new CActionSelectSingle(scene);
}

void CActionSelectSingleFactory::createIcon()
{
    QPolygonF polygon;
    polygon << QPointF(-100, -100)
            << QPointF(+100, -100)
            << QPointF(+25, -25)
            << QPointF(+100, +75)
            << QPointF(+75, +100)
            << QPointF(-25, +25)
            << QPointF(-100, +100)
            << QPointF(-100, -100);
    QPixmap pixmap(256, 256);
    pixmap.fill(Qt::transparent);
    QPainter painter(&pixmap);
    painter.setPen(QPen(Qt::black, 8));
    painter.translate(128, 128);
    painter.drawPolyline(polygon);
    setIcon(QIcon(pixmap));
}
