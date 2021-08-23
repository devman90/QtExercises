#ifndef CMAINWINDOW_H
#define CMAINWINDOW_H

#include <QMainWindow>

class IActionManager;
class IDiagramEditorScene;
class CDiagramEditorView;

QT_BEGIN_NAMESPACE
namespace Ui { class CMainWindow; }
QT_END_NAMESPACE

class CMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    CMainWindow(QWidget *parent = nullptr);
    ~CMainWindow();

    void createLeftToolbar();

private:
    Ui::CMainWindow *ui;
    IDiagramEditorScene* m_pDiagramEditorScene;
    CDiagramEditorView* m_pDiagramEditorView;
    IActionManager* m_pActionManager;
};

#endif // CMAINWINDOW_H
