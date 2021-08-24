#include "CActionEllipse.h"
#include <QPainter>
#include <QPixmap>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsEllipseItem>

#include "CPreviewItem.h"
#include "IDiagramEditorScene.h"


CActionEllipse::CActionEllipse(IDiagramEditorScene *scene)
    : IPreviewActionInterface(scene)
{
}

void CActionEllipse::finish()
{
    IPreviewActionInterface::finish();
}

void CActionEllipse::trigger()
{
    IPreviewActionInterface::trigger();
    QRectF rect = QRectF(m_TopLeft, m_BottomRight).normalized();

    QGraphicsEllipseItem* item = new QGraphicsEllipseItem(rect);
    item->setFlag(QGraphicsItem::ItemIsSelectable);
    m_pScene->addItem(item);
    setStatus(SetTopLeft);
}

void CActionEllipse::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() != Qt::LeftButton) {
        return;
    }

    if (getStatus() == SetTopLeft) {
        m_TopLeft = event->scenePos();
        setStatus(SetBottomRight);
    }

}

void CActionEllipse::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (getStatus() == SetTopLeft) {
        return;
    } else if (getStatus() == SetBottomRight) {
        QPointF bottomRight = event->scenePos();
        deletePreview();
        m_pPreview->addItem(new QGraphicsEllipseItem(QRectF(m_TopLeft, bottomRight).normalized()));
        drawPreview();
    }
}

void CActionEllipse::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() != Qt::LeftButton) {
        return;
    }

    if (getStatus() == SetBottomRight) {
        m_BottomRight = event->scenePos();
        trigger();
    }
}

CActionEllipseFactory::CActionEllipseFactory()
{
    createIcon();
}

QString CActionEllipseFactory::getName() const
{
    return "Ellipse";
}

IActionInterface *CActionEllipseFactory::create(IDiagramEditorScene *scene)
{
    return new CActionEllipse(scene);
}

void CActionEllipseFactory::createIcon()
{
    QPixmap pixmap(256, 256);
    pixmap.fill(Qt::transparent);
    QPainter painter(&pixmap);
    painter.setPen(QPen(Qt::black, 8));
    painter.translate(128, 128);
    painter.drawEllipse(QRectF(-100, -100, 200, 200));
    setIcon(QIcon(pixmap));
}
