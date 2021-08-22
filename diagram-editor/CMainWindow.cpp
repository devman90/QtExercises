#include "CMainWindow.h"
#include "ui_CMainWindow.h"

#include <QGraphicsView>
#include "CDiagramEditorScene.h"
#include "CDiagramEditorView.h"
#include "CGraphicsTestItem.h"
#include "CActionRect.h"

CMainWindow::CMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CMainWindow)
    , m_pDiagramEditorScene(new CDiagramEditorScene)
    , m_pDiagramEditorView(new CDiagramEditorView)
{
    ui->setupUi(this);
    setCentralWidget(m_pDiagramEditorView);
    m_pDiagramEditorScene->setCurrentAction(new CActionRect(m_pDiagramEditorScene));
    m_pDiagramEditorView->setScene(m_pDiagramEditorScene);
    m_pDiagramEditorScene->addItem(new CGraphicsTestItem);
}

CMainWindow::~CMainWindow()
{
    delete ui;
}

