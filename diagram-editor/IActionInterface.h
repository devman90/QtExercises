#ifndef IACTIONINTERFACE_H
#define IACTIONINTERFACE_H

class QGraphicsSceneMouseEvent;
class IDiagramEditorScene;

class IActionInterface
{
public:
    IActionInterface(IDiagramEditorScene* scene);
    virtual ~IActionInterface();

    virtual int getStatus() const;
    virtual void setStatus(int status);
    virtual bool isFinished() const;
    virtual void finish();
    virtual void trigger();
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

protected:
    bool m_bFinished;
    IDiagramEditorScene* m_pScene;

private:
    int	m_nStatus;
};

#endif // IACTIONINTERFACE_H
