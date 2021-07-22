#include "listwidget.h"
#include <QMenu>
#include <QDebug>
#include <QTimer>
#include <QMouseEvent>

ListWidget::ListWidget(QWidget *parent)
    : QListWidget(parent)
{
    addItems(QStringList{
             "Item 1",
             "Item 2",
             "Item 3",
             "Item 4",
             "Item 5",
         });
    connect(this, SIGNAL(customContextMenuRequested(QPoint)),
            this, SLOT(onCustomContextMenuRequested(QPoint)));
}

void ListWidget::onCustomContextMenuRequested(const QPoint &pos)
{
    QMenu menu;
    menu.addAction("Action 1");
    menu.addAction("Action 2");
    menu.addAction("Action 3");
    menu.addAction("Action 4");
    menu.addAction("Action 5");
    menu.exec(mapToGlobal(pos));
}

void ListWidget::mouseReleaseEvent(QMouseEvent *event)
{
    QListWidget::mouseReleaseEvent(event);
    if (m_customContextMenuOnButtonRelease) {
        if (event->button() == Qt::RightButton) {
            emit customContextMenuRequested(event->pos());
        }
    }
}
