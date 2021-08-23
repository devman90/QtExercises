#ifndef CACTIONELLIPSE_H
#define CACTIONELLIPSE_H


#include <QPointF>
#include "IPreviewActionInterface.h"
#include "IActionFactory.h"

class CActionEllipse
    : public IPreviewActionInterface
{
public:
    enum Status {
        SetTopLeft,
        SetBottomRight
    };

    CActionEllipse(IDiagramEditorScene* scene);

    void finish();
    void trigger();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
    QPointF m_TopLeft;
    QPointF m_BottomRight;
};

class CActionEllipseFactory
    : public IActionFactory
{
public:
    CActionEllipseFactory();
    QString getName() const;
    IActionInterface *create(IDiagramEditorScene *scene);

private:
    void createIcon();
};


#endif // CACTIONELLIPSE_H
