#include "oventimer.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    OvenTimer w;
    w.setDuration(6);
    w.show();
    return a.exec();
}
