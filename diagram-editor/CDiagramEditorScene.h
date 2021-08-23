#ifndef CDIAGRAMEDITORSCENE_H
#define CDIAGRAMEDITORSCENE_H

#include <QGraphicsScene>
#include "IDiagramEditorScene.h"

class CDiagramEditorScene
    : public IDiagramEditorScene
{
    Q_OBJECT

public:
    CDiagramEditorScene(QObject* parent = nullptr);

    void addItem(QGraphicsItem *item);
    void removeItem(QGraphicsItem *item);
    QGraphicsItem *itemAt(const QPointF &position) const;

protected:
    bool event(QEvent *event);
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event);
    void dragEnterEvent(QGraphicsSceneDragDropEvent *event);
    void dragMoveEvent(QGraphicsSceneDragDropEvent *event);
    void dragLeaveEvent(QGraphicsSceneDragDropEvent *event);
    void dropEvent(QGraphicsSceneDragDropEvent *event);
    void focusInEvent(QFocusEvent *event);
    void focusOutEvent(QFocusEvent *event);
    void helpEvent(QGraphicsSceneHelpEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    void wheelEvent(QGraphicsSceneWheelEvent *event);
    void inputMethodEvent(QInputMethodEvent *event);
};

#endif // CDIAGRAMEDITORSCENE_H
