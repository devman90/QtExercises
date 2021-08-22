#include "CDiagramEditorView.h"
#include <QtWidgets>
#include <QtGui>
#include <QDebug>

static const bool DEBUG_DIAGRAM_EDITOR_VIEW = true;

CDiagramEditorView::CDiagramEditorView(QWidget *parent)
    : QGraphicsView(parent)
{

}

bool CDiagramEditorView::event(QEvent *event)
{
    if (DEBUG_DIAGRAM_EDITOR_VIEW) {
        qDebug() << __PRETTY_FUNCTION__ << event;
    }
    return QGraphicsView::event(event);
}

bool CDiagramEditorView::viewportEvent(QEvent *event)
{
    if (DEBUG_DIAGRAM_EDITOR_VIEW) {
        qDebug() << __PRETTY_FUNCTION__ << event;
    }
    return QGraphicsView::viewportEvent(event);
}
