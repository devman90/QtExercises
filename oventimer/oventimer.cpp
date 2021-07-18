#include "oventimer.h"
#include <QPainter>
#include <QPaintEvent>
#include <QBrush>
#include <QDebug>
#include <QLineF>
#include <QTimer>
#include <QConicalGradient>
#include <qmath.h>

OvenTimer::OvenTimer(QWidget *parent)
    : QDialog(parent)
{
    timer = new QTimer(this);
    timer->setInterval(1000); // 1 sec
    connect(timer, SIGNAL(timeout()),
            this, SLOT(onTimerTimeout()));
    remainTime = 0;
}

OvenTimer::~OvenTimer()
{
}

void OvenTimer::setDuration(int sec)
{
    qDebug() << "setDuration: " << sec;
    remainTime = sec;
    update();

    timer->stop();
    timer->start();
}

void OvenTimer::onTimerTimeout()
{
    if (remainTime <= 0) {
       return;
    }
    remainTime -= 1;
    qDebug() << remainTime;

    if (remainTime <= 0) {
        timer->stop();
        qDebug() << "Done!";
    }

    update();
}

void OvenTimer::paintEvent(QPaintEvent *pe)
{
    Q_UNUSED(pe);
    int w = qMin(width(), height());
    QPainter painter(this);
    painter.setWindow(-width()/ 2, -height() / 2, width(), height());
    painter.setPen(QPen(QColor(0, 0, 0)));
    QConicalGradient gradient;
    gradient.setAngle(90);
    gradient.setColorAt(0.0, QColor(255, 255, 255));
    gradient.setColorAt(0.5, QColor(100, 100, 100));
    gradient.setColorAt(1.0, QColor(255, 255, 255));
    painter.setBrush(QBrush(gradient));
    painter.drawEllipse(-w/2, -w/2, w, w);

    painter.setBrush(QBrush(QColor(100, 100, 100)));
    painter.drawEllipse(-w/4, -w/4, w/2, w/2);

    double originAngle = 90.0 + remainTime * 6;

    painter.setPen(QPen(QColor(0, 0, 0), 1));
    for (int diffAngle = 0; diffAngle < 360; diffAngle += 6) {
        double angleDeg = originAngle - diffAngle;
        double angleRad = qDegreesToRadians(angleDeg);
        int r = w / 2;
        int innerr = qMax(r - 10, 1);
        int outerr = qMax(r - 2, 1);
        double cos = qCos(angleRad);
        double sin = qSin(angleRad);
        painter.drawLine(QLineF(innerr * cos, innerr * sin, outerr * cos, outerr * sin));
    }

    painter.setPen(QPen(QColor(0, 0, 0), 3));
    for (int diffAngle = 0; diffAngle < 360; diffAngle += 30) {
        double angleDeg = originAngle - diffAngle;
        double angleRad = qDegreesToRadians(angleDeg);
        int r = w / 2;
        int innerr = qMax(r - 12, 1);
        int outerr = qMax(r - 2, 1);
        double cos = qCos(angleRad);
        double sin = qSin(angleRad);
        painter.drawLine(QLineF(innerr * cos, innerr * sin, outerr * cos, outerr * sin));

        QString numberString = QString::number(diffAngle / 6);
        double rotateAngle = angleDeg - 90.0;
        painter.rotate(rotateAngle);

        QFont originalFont = font();

        QFont clockFont;
        clockFont.setPointSize(24);
        QRect fontRect = QFontMetrics(clockFont).boundingRect(numberString);
        painter.setFont(clockFont);
        fontRect.translate(-fontRect.width()/2, -innerr-fontRect.y());
        painter.drawText(fontRect, Qt::AlignCenter, numberString);
        painter.rotate(-rotateAngle);

        painter.setFont(originalFont);
    }

    int r = w / 2;
    int innerr = qMax(r - 24, 1);
    int outerr = qMax(r - 2, 1);
    painter.setPen(QPen(QColor(255, 0, 0), 3));
    painter.drawLine(0, -innerr, 0, -outerr);
}

void OvenTimer::mousePressEvent(QMouseEvent *me)
{
    QPoint pos = me->pos();
    QPoint origin(width()/2, height()/2);
    QPoint posFromOrigin = pos - origin;

    double atanValue;
    if (posFromOrigin.x() == 0) {
        if (posFromOrigin.y() < 0) {
            atanValue = -M_PI / 2;

        } else {
            atanValue = M_PI / 2;
        }
    } else {
        double tanValue = posFromOrigin.y() / (double)posFromOrigin.x();
        atanValue = qAtan(tanValue);
    }

    int deg = qRadiansToDegrees(atanValue);
    if (posFromOrigin.x() < 0) {
        deg += 180;
    }
    deg %= 360;
    deg = 270 - deg;
    if (deg < 0)
        deg += 360;
    int time = deg / 6;
    setDuration(time);
}

