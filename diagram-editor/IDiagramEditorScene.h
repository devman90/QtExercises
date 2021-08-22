#ifndef IDIAGRAMEDITORSCENE_H
#define IDIAGRAMEDITORSCENE_H

class QGraphicsItem;
class CEventHandler;
class IActionInterface;

class IDiagramEditorScene
{
public:
    IDiagramEditorScene();
    virtual ~IDiagramEditorScene();

    virtual void addItem(QGraphicsItem *item)=0;
    virtual void removeItem(QGraphicsItem *item)=0;
    void setCurrentAction(IActionInterface *action);
    void killAllActions();

protected:
    CEventHandler* m_pEventHandler;
};

#endif // IDIAGRAMEDITORSCENE_H
