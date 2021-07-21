#ifndef TEXTPROCESSOR_H
#define TEXTPROCESSOR_H

#include <QThread>
#include <QMutex>
#include <QDebug>

class ITextProcess
{
public:
    virtual ~ITextProcess() = default;
    virtual QString process(const QString& text) = 0;
};

class DoubleProcess
        : public ITextProcess
{
public:
    QString process(const QString &text) {
        qDebug() << "Starting: DoubleProcess::process";
        QThread::msleep(500);
        qDebug() << "Finishing: DoubleProcess::process";
        return text + text;
    }
};

class ReverseProcess
        : public ITextProcess
{
public:
    QString process(const QString &text) {
        qDebug() << "Starting: ReverseProcess::process";
        QThread::msleep(500);
        QString result;
        for (const QChar& c : text) {
            result.prepend(c);
        }
        qDebug() << "Finishing: ReverseProcess::process";
        return result;
    }
};

class EraseProcess
        : public ITextProcess
{
public:
    QString process(const QString &text) {
        qDebug() << "Starting: EraseProcess::process";
        QThread::msleep(500);
        QString result = text;
        result.remove(result.size() - 1, 1);
        qDebug() << "Finishing: EraseProcess::process";
        return result;
    }
};

class SetTextProcess
        : public ITextProcess
{
public:
    SetTextProcess(const QString& text) {
        m_text = text;
    }

    QString process(const QString &text) {
        Q_UNUSED(text)
        qDebug() << "Starting: SetTextProcess::process";
        QThread::msleep(500);
        qDebug() << "Finishing: SetTextProcess::process";
        return m_text;
    }

private:
    QString m_text;
};


class TextProcessor
        : public QObject
{
    Q_OBJECT

public:
    explicit TextProcessor(QObject* parent = 0);

    QString text() const;
    void setText(const QString& text);
    void addProcess(ITextProcess* process);

public slots:
    void doProcess();

private:
    mutable QMutex m_mutex;
    QList<ITextProcess*> m_processes;
    QString m_text;

signals:
    void textReady();
};

#endif // TEXTPROCESSOR_H
