#ifndef IACTIONMANAGER_H
#define IACTIONMANAGER_H

#include <QWidget>
#include <QHash>

class QAction;
class IDiagramEditorScene;
class IActionFactory;

class IActionManager
    : public QObject
{
    Q_OBJECT

public:
    IActionManager(QObject* parent);
    virtual ~IActionManager();

    virtual QList<QAction*> getActions() = 0;
    virtual void setCurrentScene(IDiagramEditorScene* scene);

protected:
    IDiagramEditorScene* m_scene;
};

#endif // IACTIONMANAGER_H
