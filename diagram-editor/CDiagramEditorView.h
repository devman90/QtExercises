#ifndef CDIAGRAMEDITORVIEW_H
#define CDIAGRAMEDITORVIEW_H

#include <QGraphicsView>

class CDiagramEditorView
    : public QGraphicsView
{
public:
    CDiagramEditorView(QWidget *parent = nullptr);

protected:
    bool event(QEvent* event);
    bool viewportEvent(QEvent *event);
};

#endif // CDIAGRAMEDITORVIEW_H
