#include "IPreviewActionInterface.h"
#include "IDiagramEditorScene.h"
#include "CPreviewItem.h"

IPreviewActionInterface::IPreviewActionInterface(IDiagramEditorScene *scene)
    : IActionInterface(scene)
    , m_pPreview(new CPreviewItem)
{
    scene->addItem(m_pPreview);
}

IPreviewActionInterface::~IPreviewActionInterface()
{
    delete m_pPreview;
}

void IPreviewActionInterface::finish()
{
    deletePreview();
    IActionInterface::finish();
}

void IPreviewActionInterface::trigger()
{
    IActionInterface::trigger();
    deletePreview();
}

void IPreviewActionInterface::drawPreview()
{
    m_pScene->addItem(m_pPreview);
}

void IPreviewActionInterface::deletePreview()
{
    m_pScene->removeItem(m_pPreview);
    m_pPreview->clear();
}
