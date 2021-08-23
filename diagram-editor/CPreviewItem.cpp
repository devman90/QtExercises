#include "CPreviewItem.h"

CPreviewItem::CPreviewItem()
{

}

CPreviewItem::~CPreviewItem()
{
}

void CPreviewItem::addItem(QGraphicsItem *item)
{
    QGraphicsItemGroup::addToGroup(item);
}

void CPreviewItem::clear()
{
    for (QGraphicsItem* item : QGraphicsItemGroup::childItems()) {
        delete item;
    }
}
