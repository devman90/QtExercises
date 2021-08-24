#ifndef CACTIONDEFAULT_H
#define CACTIONDEFAULT_H

#include "IActionInterface.h"
#include "IActionFactory.h"

class QGraphicsItem;
class QGraphicsRectItem;


class CActionDefault
    : public IActionInterface
{
public:
    enum Status {
        Idle,
        DrawRubber,
    };
    CActionDefault(IDiagramEditorScene* scene);

    void trigger();

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
    QList<QGraphicsItem*> m_selectedItems;
    QGraphicsRectItem* m_rubberBand;

    QRectF m_curRubberBandRect;
    QPointF m_rubberBandStartScenePos;
    QPointF m_rubberBandEndScenePos;

    QPoint m_rubberBandStartScreenPos;
    QPoint m_rubberBandEndScreenPos;

    void startDrawRubberBand();
    void updateDrawRubberBand(const QPointF& curPos);
    void endDrawRubberBand();

    void selectItems();
    void clearSelection();
};


class CActionDefaultFactory
    : public IActionFactory
{
public:
    CActionDefaultFactory();
    QString getName() const;
    IActionInterface *create(IDiagramEditorScene *scene);

private:
    void createIcon();
};


#endif // CACTIONDEFAULT_H
