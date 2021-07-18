#ifndef OVENTIMER_H
#define OVENTIMER_H

#include <QDialog>

class QTimer;

class OvenTimer : public QDialog
{
    Q_OBJECT

public:
    OvenTimer(QWidget *parent = nullptr);
    ~OvenTimer();

public slots:
    void setDuration(int sec);
    void onTimerTimeout();


protected:
    void paintEvent(QPaintEvent* pe) override;
    void mousePressEvent(QMouseEvent* me) override;

private:
    QTimer* timer;
    int remainTime;
};
#endif // OVENTIMER_H
