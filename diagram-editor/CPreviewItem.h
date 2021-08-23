#ifndef CPREVIEWITEM_H
#define CPREVIEWITEM_H

#include <QGraphicsItemGroup>


class CPreviewItem
    : public QGraphicsItemGroup
{
public:
    CPreviewItem();
    ~CPreviewItem();

    void addItem(QGraphicsItem* item);
    void clear();
};

#endif // CPREVIEWITEM_H
