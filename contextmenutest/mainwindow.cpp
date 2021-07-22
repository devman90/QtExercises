#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "listwidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ListWidget* widget = new ListWidget;
    setCentralWidget(widget);
}

MainWindow::~MainWindow()
{
}
