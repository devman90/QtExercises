#include "IActionManager.h"

IActionManager::IActionManager(QObject *parent)
    : QObject(parent)
    , m_scene(nullptr)
{

}

IActionManager::~IActionManager()
{

}

void IActionManager::setCurrentScene(IDiagramEditorScene *scene)
{
    if (m_scene == scene) {
        return;
    }
    m_scene = scene;
}
