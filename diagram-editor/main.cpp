#include "CMainWindow.h"

#include <QApplication>
#include "CCore.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CCore core;
    CMainWindow w;
    w.show();
    return a.exec();
}
