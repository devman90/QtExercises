#include "CDiagramEditorScene.h"
#include <QtWidgets>
#include <QtGui>
#include <QDebug>
#include "CEventHandler.h"

static const bool DEBUG_DIAGRAM_EDITOR_SCENE = false;

CDiagramEditorScene::CDiagramEditorScene(QObject *parent)
    : IDiagramEditorScene(parent)
{
    setSceneRect(0, 0, 1600, 900);
}

void CDiagramEditorScene::addItem(QGraphicsItem *item)
{
    QGraphicsScene::addItem(item);
}

void CDiagramEditorScene::removeItem(QGraphicsItem *item)
{
    QGraphicsScene::removeItem(item);
}

QGraphicsItem *CDiagramEditorScene::itemAt(const QPointF &position) const
{
    return QGraphicsScene::itemAt(position, QTransform());
}

bool CDiagramEditorScene::event(QEvent *event)
{
    if (DEBUG_DIAGRAM_EDITOR_SCENE) {
        qDebug() << __PRETTY_FUNCTION__ << event;
    }
    return QGraphicsScene::event(event);
}

void CDiagramEditorScene::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
    if (DEBUG_DIAGRAM_EDITOR_SCENE) {
        qDebug() << __PRETTY_FUNCTION__ << event;
    }
    QGraphicsScene::contextMenuEvent(event);
}

void CDiagramEditorScene::dragEnterEvent(QGraphicsSceneDragDropEvent *event)
{
    if (DEBUG_DIAGRAM_EDITOR_SCENE) {
        qDebug() << __PRETTY_FUNCTION__ << event;
    }
    QGraphicsScene::dragEnterEvent(event);
}

void CDiagramEditorScene::dragMoveEvent(QGraphicsSceneDragDropEvent *event)
{
    if (DEBUG_DIAGRAM_EDITOR_SCENE) {
        qDebug() << __PRETTY_FUNCTION__ << event;
    }
    QGraphicsScene::dragMoveEvent(event);
}

void CDiagramEditorScene::dragLeaveEvent(QGraphicsSceneDragDropEvent *event)
{
    if (DEBUG_DIAGRAM_EDITOR_SCENE) {
        qDebug() << __PRETTY_FUNCTION__ << event;
    }
    QGraphicsScene::dragLeaveEvent(event);
}

void CDiagramEditorScene::dropEvent(QGraphicsSceneDragDropEvent *event)
{
    if (DEBUG_DIAGRAM_EDITOR_SCENE) {
        qDebug() << __PRETTY_FUNCTION__ << event;
    }
    QGraphicsScene::dropEvent(event);
}

void CDiagramEditorScene::focusInEvent(QFocusEvent *event)
{
    if (DEBUG_DIAGRAM_EDITOR_SCENE) {
        qDebug() << __PRETTY_FUNCTION__ << event;
    }
    QGraphicsScene::focusInEvent(event);
}

void CDiagramEditorScene::focusOutEvent(QFocusEvent *event)
{
    if (DEBUG_DIAGRAM_EDITOR_SCENE) {
        qDebug() << __PRETTY_FUNCTION__ << event;
    }
    QGraphicsScene::focusOutEvent(event);
}

void CDiagramEditorScene::helpEvent(QGraphicsSceneHelpEvent *event) {
    if (DEBUG_DIAGRAM_EDITOR_SCENE) {
        qDebug() << __PRETTY_FUNCTION__ << event;
    }
    QGraphicsScene::helpEvent(event);
}

void CDiagramEditorScene::keyPressEvent(QKeyEvent *event)
{
    if (DEBUG_DIAGRAM_EDITOR_SCENE) {
        qDebug() << __PRETTY_FUNCTION__ << event;
    }
    QGraphicsScene::keyPressEvent(event);
}

void CDiagramEditorScene::keyReleaseEvent(QKeyEvent *event)
{
    if (DEBUG_DIAGRAM_EDITOR_SCENE) {
        qDebug() << __PRETTY_FUNCTION__ << event;
    }
    QGraphicsScene::keyReleaseEvent(event);
}

void CDiagramEditorScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (DEBUG_DIAGRAM_EDITOR_SCENE) {
        qDebug() << __PRETTY_FUNCTION__ << event;
        qDebug() << "\tscenePos:" << event->scenePos();
        qDebug() << "\tbuttons:" << event->buttons();
        qDebug() << "\tbuttonDownScenePos(Qt::LeftButton):" << event->buttonDownScenePos(Qt::LeftButton);
    }
    m_pEventHandler->mousePressEvent(event);
//    QGraphicsScene::mousePressEvent(event);
}

void CDiagramEditorScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (DEBUG_DIAGRAM_EDITOR_SCENE) {
        qDebug() << __PRETTY_FUNCTION__ << event;
        qDebug() << "\tscenePos:" << event->scenePos();
        qDebug() << "\tbuttons:" << event->buttons();
        qDebug() << "\tbuttonDownScenePos(Qt::LeftButton):" << event->buttonDownScenePos(Qt::LeftButton);
    }
    m_pEventHandler->mouseMoveEvent(event);
//    QGraphicsScene::mouseMoveEvent(event);
}

void CDiagramEditorScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if (DEBUG_DIAGRAM_EDITOR_SCENE) {
        qDebug() << __PRETTY_FUNCTION__ << event;
        qDebug() << "\tscenePos:" << event->scenePos();
        qDebug() << "\tbuttons:" << event->buttons();
        qDebug() << "\tbuttonDownScenePos(Qt::LeftButton):" << event->buttonDownScenePos(Qt::LeftButton);
    }
    m_pEventHandler->mouseReleaseEvent(event);
//    QGraphicsScene::mouseReleaseEvent(event);
}

void CDiagramEditorScene::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    if (DEBUG_DIAGRAM_EDITOR_SCENE) {
        qDebug() << __PRETTY_FUNCTION__ << event;
    }
    QGraphicsScene::mouseReleaseEvent(event);
}

void CDiagramEditorScene::wheelEvent(QGraphicsSceneWheelEvent *event)
{
    if (DEBUG_DIAGRAM_EDITOR_SCENE) {
        qDebug() << __PRETTY_FUNCTION__ << event;
    }
    QGraphicsScene::wheelEvent(event);
}

void CDiagramEditorScene::inputMethodEvent(QInputMethodEvent *event)
{
    if (DEBUG_DIAGRAM_EDITOR_SCENE) {
        qDebug() << __PRETTY_FUNCTION__ << event;
    }
    QGraphicsScene::inputMethodEvent(event);
}
