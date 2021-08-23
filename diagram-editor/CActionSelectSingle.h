#ifndef CACTIONSELECTSINGLE_H
#define CACTIONSELECTSINGLE_H

#include "IActionInterface.h"
#include "IActionFactory.h"

class QGraphicsItem;

class CActionSelectSingle
    : public IActionInterface
{
public:
    CActionSelectSingle(IDiagramEditorScene* scene);

    void trigger();
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
    QGraphicsItem* item;
};


class CActionSelectSingleFactory
    : public IActionFactory
{
public:
    CActionSelectSingleFactory();
    QString getName() const;
    IActionInterface *create(IDiagramEditorScene *scene);

private:
    void createIcon();
};


#endif // CACTIONSELECTSINGLE_H
