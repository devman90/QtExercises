#ifndef IPREVIEWACTIONINTERFACE_H
#define IPREVIEWACTIONINTERFACE_H

#include "IActionInterface.h"

class CPreviewItem;

class IPreviewActionInterface
    : public IActionInterface
{
public:
    IPreviewActionInterface(IDiagramEditorScene* scene);
    ~IPreviewActionInterface();

    void finish();
    void trigger();
    void drawPreview();
    void deletePreview();

protected:
    CPreviewItem* m_pPreview;
};

#endif // IPREVIEWACTIONINTERFACE_H
