#ifndef OVENTIMER_H
#define OVENTIMER_H

#include <QWidget>
#include <QDateTime>

class QTimer;

class OvenTimer : public QWidget
{
    Q_OBJECT
public:
    explicit OvenTimer(QWidget *parent = nullptr);

    void setDuration(int secs);
    int duration() const;

    void draw(QPainter* painter);

signals:
    void timeout();

protected:
    void paintEvent(QPaintEvent* event);
    void mousePressEvent(QMouseEvent* event);

private:
    QDateTime finishTime;
    QTimer* updateTimer;
    QTimer* finishTimer;
};

#endif // OVENTIMER_H
