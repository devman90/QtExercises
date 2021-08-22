#include "IDiagramEditorScene.h"
#include <QDebug>
#include "CEventHandler.h"

static const bool DEBUG_DIAGRAM_EDITOR_SCENE = true;

IDiagramEditorScene::IDiagramEditorScene()
    : m_pEventHandler(new CEventHandler)
{

}

IDiagramEditorScene::~IDiagramEditorScene()
{
    delete m_pEventHandler;
}

void IDiagramEditorScene::setCurrentAction(IActionInterface *action)
{
    if (DEBUG_DIAGRAM_EDITOR_SCENE) {
        qDebug() << __PRETTY_FUNCTION__;
    }
    m_pEventHandler->setCurrentAction(action);
}

void IDiagramEditorScene::killAllActions()
{
    m_pEventHandler->killAllActions();
}
