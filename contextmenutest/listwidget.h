#ifndef LISTWIDGET_H
#define LISTWIDGET_H

#include <QListWidget>

class ListWidget
        : public QListWidget
{
    Q_OBJECT

public:
    explicit ListWidget(QWidget* parent = 0);

public slots:
    void onCustomContextMenuRequested(const QPoint& pos);

protected:
    void mouseReleaseEvent(QMouseEvent* event);

private:
    bool m_customContextMenuOnButtonRelease;
};

#endif // LISTWIDGET_H
