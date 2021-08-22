#include "CGraphicsTestItem.h"
#include <QtWidgets>
#include <QtGui>
#include <QDebug>

static const bool DEBUG_GRAPHICS_TEST_ITEM = true;

CGraphicsTestItem::CGraphicsTestItem()
{
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsSelectable);
}

QRectF CGraphicsTestItem::boundingRect() const
{
    return QRectF(-10, -10, 20, 20);
}

void CGraphicsTestItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawRoundRect(-10, -10, 20, 20, 5, 5);
}

bool CGraphicsTestItem::sceneEvent(QEvent *event)
{
    if (DEBUG_GRAPHICS_TEST_ITEM) {
        qDebug() << __PRETTY_FUNCTION__ << event;
    }
    QGraphicsItem::sceneEvent(event);
}

void CGraphicsTestItem::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
    if (DEBUG_GRAPHICS_TEST_ITEM) {
        qDebug() << __PRETTY_FUNCTION__ << event;
    }
    QGraphicsItem::contextMenuEvent(event);
}

void CGraphicsTestItem::dragEnterEvent(QGraphicsSceneDragDropEvent *event)
{
    if (DEBUG_GRAPHICS_TEST_ITEM) {
        qDebug() << __PRETTY_FUNCTION__ << event;
    }
    QGraphicsItem::dragEnterEvent(event);
}

void CGraphicsTestItem::dragLeaveEvent(QGraphicsSceneDragDropEvent *event)
{
    if (DEBUG_GRAPHICS_TEST_ITEM) {
        qDebug() << __PRETTY_FUNCTION__ << event;
    }
    QGraphicsItem::dragLeaveEvent(event);
}

void CGraphicsTestItem::dragMoveEvent(QGraphicsSceneDragDropEvent *event)
{
    if (DEBUG_GRAPHICS_TEST_ITEM) {
        qDebug() << __PRETTY_FUNCTION__ << event;
    }
    QGraphicsItem::dragMoveEvent(event);
}

void CGraphicsTestItem::dropEvent(QGraphicsSceneDragDropEvent *event)
{
    if (DEBUG_GRAPHICS_TEST_ITEM) {
        qDebug() << __PRETTY_FUNCTION__ << event;
    }
    QGraphicsItem::dropEvent(event);
}

void CGraphicsTestItem::focusInEvent(QFocusEvent *event)
{
    if (DEBUG_GRAPHICS_TEST_ITEM) {
        qDebug() << __PRETTY_FUNCTION__ << event;
    }
    QGraphicsItem::focusInEvent(event);
}

void CGraphicsTestItem::focusOutEvent(QFocusEvent *event)
{
    if (DEBUG_GRAPHICS_TEST_ITEM) {
        qDebug() << __PRETTY_FUNCTION__ << event;
    }
    QGraphicsItem::focusOutEvent(event);
}

void CGraphicsTestItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    if (DEBUG_GRAPHICS_TEST_ITEM) {
        qDebug() << __PRETTY_FUNCTION__ << event;
    }
    QGraphicsItem::hoverEnterEvent(event);
}

void CGraphicsTestItem::hoverMoveEvent(QGraphicsSceneHoverEvent *event)
{
    if (DEBUG_GRAPHICS_TEST_ITEM) {
        qDebug() << __PRETTY_FUNCTION__ << event;
    }
    QGraphicsItem::hoverMoveEvent(event);
}

void CGraphicsTestItem::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    if (DEBUG_GRAPHICS_TEST_ITEM) {
        qDebug() << __PRETTY_FUNCTION__ << event;
    }
    QGraphicsItem::hoverLeaveEvent(event);
}

void CGraphicsTestItem::keyPressEvent(QKeyEvent *event)
{
    if (DEBUG_GRAPHICS_TEST_ITEM) {
        qDebug() << __PRETTY_FUNCTION__ << event;
    }
    QGraphicsItem::keyPressEvent(event);
}

void CGraphicsTestItem::keyReleaseEvent(QKeyEvent *event)
{
    if (DEBUG_GRAPHICS_TEST_ITEM) {
        qDebug() << __PRETTY_FUNCTION__ << event;
    }
    QGraphicsItem::keyReleaseEvent(event);
}

void CGraphicsTestItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (DEBUG_GRAPHICS_TEST_ITEM) {
        qDebug() << __PRETTY_FUNCTION__ << event;
    }
    QGraphicsItem::mousePressEvent(event);
}

void CGraphicsTestItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (DEBUG_GRAPHICS_TEST_ITEM) {
        qDebug() << __PRETTY_FUNCTION__ << event;
    }
    QGraphicsItem::mouseMoveEvent(event);
}

void CGraphicsTestItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if (DEBUG_GRAPHICS_TEST_ITEM) {
        qDebug() << __PRETTY_FUNCTION__ << event;
    }
    QGraphicsItem::mouseReleaseEvent(event);
}

void CGraphicsTestItem::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    if (DEBUG_GRAPHICS_TEST_ITEM) {
        qDebug() << __PRETTY_FUNCTION__ << event;
    }
    QGraphicsItem::mouseDoubleClickEvent(event);
}

void CGraphicsTestItem::wheelEvent(QGraphicsSceneWheelEvent *event)
{
    if (DEBUG_GRAPHICS_TEST_ITEM) {
        qDebug() << __PRETTY_FUNCTION__ << event;
    }
    QGraphicsItem::wheelEvent(event);
}

void CGraphicsTestItem::inputMethodEvent(QInputMethodEvent *event)
{
    if (DEBUG_GRAPHICS_TEST_ITEM) {
        qDebug() << __PRETTY_FUNCTION__ << event;
    }
    QGraphicsItem::inputMethodEvent(event);
}
