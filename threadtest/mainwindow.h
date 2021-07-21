#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include "textprocessor.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void onDoubleButtonClicked();
    void onEraseButtonClicked();
    void onReverseButtonClicked();
    void onSetTextButtonClicked();

    void onTextReady();

private:
    Ui::MainWindow *ui;
    QThread m_thread;
    TextProcessor* m_processor;
};

#endif // MAINWINDOW_H
