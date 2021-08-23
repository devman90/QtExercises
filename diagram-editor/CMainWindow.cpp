#include "CMainWindow.h"
#include "ui_CMainWindow.h"

#include <QGraphicsView>
#include <QSplitter>
#include <QToolBar>
#include "CDiagramEditorScene.h"
#include "CDiagramEditorView.h"
#include "CActionManager.h"
#include "CGraphicsTestItem.h"
#include "CActionRect.h"

CMainWindow::CMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CMainWindow)
    , m_pDiagramEditorScene(new CDiagramEditorScene)
    , m_pDiagramEditorView(new CDiagramEditorView)
    , m_pActionManager(new CActionManager(this))
{
    ui->setupUi(this);
    setCentralWidget(m_pDiagramEditorView);

    m_pDiagramEditorScene->setCurrentAction(new CActionRect(m_pDiagramEditorScene));
    m_pDiagramEditorView->setScene(m_pDiagramEditorScene);
    m_pDiagramEditorScene->addItem(new CGraphicsTestItem);

    m_pActionManager->setCurrentScene(m_pDiagramEditorScene);

    createLeftToolbar();
}

CMainWindow::~CMainWindow()
{
    delete ui;
}

void CMainWindow::createLeftToolbar()
{
    QToolBar* leftToolbar = new QToolBar("Actions", this);
    QList<QAction*> actions = m_pActionManager->getActions();
    for (QAction* action : actions) {
        leftToolbar->addAction(action);
    }
    addToolBar(Qt::LeftToolBarArea, leftToolbar);
}

