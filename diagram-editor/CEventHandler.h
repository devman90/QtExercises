#ifndef CEVENTHANDLER_H
#define CEVENTHANDLER_H

#include <QObject>

class IActionInterface;
class QGraphicsSceneMouseEvent;

class CEventHandler
    : public QObject
{
    Q_OBJECT

public:
    CEventHandler(QObject *parent = nullptr);
    ~CEventHandler();

    bool hasAction() const;
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

    void setCurrentAction(IActionInterface* action);

    void killAllActions();

private:
    QList<IActionInterface*> m_CurrentActions;

    IActionInterface* getLastAction() const;
};

#endif // CEVENTHANDLER_H
