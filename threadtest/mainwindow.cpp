#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    m_thread.start();
    ui->setupUi(this);

    m_processor = new TextProcessor;
    m_processor->moveToThread(&m_thread);
    connect(m_processor, SIGNAL(textReady()),
            this, SLOT(onTextReady()));
    connect(&m_thread, SIGNAL(finished()), m_processor, SLOT(deleteLater()));
    connect(ui->doubleButton, SIGNAL(clicked()), this, SLOT(onDoubleButtonClicked()));
    connect(ui->eraseButton, SIGNAL(clicked()), this, SLOT(onEraseButtonClicked()));
    connect(ui->reverseButton, SIGNAL(clicked()), this, SLOT(onReverseButtonClicked()));
    connect(ui->setTextButton, SIGNAL(clicked()), this, SLOT(onSetTextButtonClicked()));
}

MainWindow::~MainWindow()
{
    m_thread.quit();
    m_thread.wait();
    delete ui;
}

void MainWindow::onDoubleButtonClicked()
{
    m_processor->addProcess(new DoubleProcess);
}

void MainWindow::onEraseButtonClicked()
{
    m_processor->addProcess(new EraseProcess);
}

void MainWindow::onReverseButtonClicked()
{
    m_processor->addProcess(new ReverseProcess);
}

void MainWindow::onSetTextButtonClicked()
{
    QString text = QInputDialog::getText(this, "Set Text", "Enter text:", QLineEdit::Normal, ui->plainTextEdit->toPlainText());
    m_processor->addProcess(new SetTextProcess(text));
}

void MainWindow::onTextReady()
{
    qDebug() << "Running MainWindow::onTextReady() in " << QThread::currentThreadId();
    ui->plainTextEdit->setPlainText(m_processor->text());
}

