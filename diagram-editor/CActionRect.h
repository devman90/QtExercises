#ifndef CACTIONRECT_H
#define CACTIONRECT_H

#include <QPointF>
#include "IPreviewActionInterface.h"
#include "IActionFactory.h"

class CActionRect
    : public IPreviewActionInterface
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

class CActionRectFactory
    : public IActionFactory
{
public:
    CActionRectFactory();
    QString getName() const;
    IActionInterface *create(IDiagramEditorScene *scene);

private:
    void createIcon();
};


#endif // CACTIONRECT_H
