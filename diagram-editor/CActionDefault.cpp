#include "CActionDefault.h"
#include <QDebug>
#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsRectItem>
#include "IDiagramEditorScene.h"

CActionDefault::CActionDefault(IDiagramEditorScene *scene)
    : IActionInterface(scene)
    , m_rubberBand(nullptr)
{

}

void CActionDefault::trigger()
{
    qDebug() << "Selected:" << m_selectedItems;
}

void CActionDefault::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (getStatus() == Idle) {
        if (event->button() == Qt::LeftButton) {
            qDebug() << "Start RubberBand";
            m_rubberBandStartScreenPos = event->screenPos();
            m_rubberBandStartScenePos = event->scenePos();
            setStatus(DrawRubber);
            startDrawRubberBand();
            clearSelection();
        }
    }
}

void CActionDefault::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (getStatus() == DrawRubber) {
        if (event->buttons() | Qt::LeftButton) {
            updateDrawRubberBand(event->scenePos());
        }
    }
}

void CActionDefault::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if (getStatus() == DrawRubber) {
        if (event->button() == Qt::LeftButton) {
            qDebug() << "End RubberBand";
            endDrawRubberBand();
            m_rubberBandEndScreenPos = event->screenPos();
            m_rubberBandEndScenePos = event->scenePos();
            selectItems();
            setStatus(Idle);
            trigger();
        }
    }
}

void CActionDefault::startDrawRubberBand()
{
    if (!m_rubberBand) {
        m_rubberBand = new QGraphicsRectItem;
        m_rubberBand->setPen(QPen(Qt::blue));
        m_rubberBand->setBrush(QBrush(QColor(0, 0, 255, 100)));
        m_pScene->addItem(m_rubberBand);
    }

    m_curRubberBandRect = QRectF(m_rubberBandStartScenePos, QSize(0, 0));
    m_rubberBand->setRect(m_curRubberBandRect);
}

void CActionDefault::updateDrawRubberBand(const QPointF &curPos)
{
    m_curRubberBandRect = QRectF(m_rubberBandStartScenePos, curPos).normalized();
    m_rubberBand->setRect(m_curRubberBandRect);
}

void CActionDefault::endDrawRubberBand()
{
    if (m_rubberBand) {
        delete m_rubberBand;
        m_rubberBand = nullptr;
    }
}

void CActionDefault::selectItems()
{
    QPoint screenDiff = m_rubberBandStartScreenPos - m_rubberBandEndScreenPos;
    if (screenDiff.manhattanLength() < 8) {
        // Single Click
        QGraphicsItem* item = m_pScene->itemAt(m_rubberBandStartScenePos);
        if (item) {
            m_selectedItems << item;
        }
    } else {
        // Drag Selection
        QRectF selRect = QRectF(m_rubberBandStartScenePos, m_rubberBandEndScenePos);
        selRect = selRect.normalized();
        m_selectedItems = m_pScene->items(selRect);
    }

    // Select items
    for (QGraphicsItem* item : m_selectedItems) {
        item->setSelected(true);
    }
}

void CActionDefault::clearSelection()
{
    for (QGraphicsItem* item : m_selectedItems) {
        item->setSelected(false);
    }
    m_selectedItems.clear();
}

CActionDefaultFactory::CActionDefaultFactory()
{
    createIcon();
}

QString CActionDefaultFactory::getName() const
{
    return "Select single";
}

IActionInterface *CActionDefaultFactory::create(IDiagramEditorScene *scene)
{
    return new CActionDefault(scene);
}

void CActionDefaultFactory::createIcon()
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
