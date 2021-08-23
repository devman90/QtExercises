#ifndef IDIAGRAMEDITORSCENE_H
#define IDIAGRAMEDITORSCENE_H

#include <QPointF>
#include <QGraphicsScene>

class QGraphicsItem;
class CEventHandler;
class IActionInterface;

class IDiagramEditorScene
        : public QGraphicsScene
{
    Q_OBJECT

public:
    IDiagramEditorScene(QObject* parent = nullptr);
    virtual ~IDiagramEditorScene();

    virtual void addItem(QGraphicsItem *item)=0;
    virtual void removeItem(QGraphicsItem *item)=0;
    virtual QGraphicsItem *itemAt(const QPointF &position) const=0;
    void setCurrentAction(IActionInterface *action);
    void killAllActions();

protected:
    CEventHandler* m_pEventHandler;
};

#endif // IDIAGRAMEDITORSCENE_H
