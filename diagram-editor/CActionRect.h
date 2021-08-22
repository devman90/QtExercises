#ifndef CACTIONRECT_H
#define CACTIONRECT_H

#include <QPointF>
#include "IActionInterface.h"

class CActionRect
    : public IActionInterface
{
public:
    enum Status {
        SetTopLeft,
        SetBottomRight
    };
    CActionRect(IDiagramEditorScene* scene);

    void finish();
    void trigger();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
    QPointF m_TopLeft;
    QPointF m_BottomRight;
};

#endif // CACTIONRECT_H
