#ifndef CACTIONMANAGER_H
#define CACTIONMANAGER_H

#include "IActionManager.h"

class CActionManager
    : public IActionManager
{
    Q_OBJECT

public:
    CActionManager(QObject* parent = nullptr);

    QList<QAction *> getActions();
    void setCurrentScene(IDiagramEditorScene *scene);

public slots:
    void onActionTriggered();

private:
    QList<QAction*> m_actions;
    QHash<QAction*, IActionFactory*> m_actionHash;

    void createActions();
};

#endif // CACTIONMANAGER_H
