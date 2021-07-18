#ifndef OVENTIMER_H
#define OVENTIMER_H

#include <QDialog>

class OvenTimer : public QDialog
{
    Q_OBJECT

public:
    OvenTimer(QWidget *parent = nullptr);
    ~OvenTimer();
};
#endif // OVENTIMER_H
