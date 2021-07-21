#include "textprocessor.h"
#include <QMutexLocker>
#include <QTimer>

TextProcessor::TextProcessor(QObject *parent)
    : QObject(parent)
{

}

QString TextProcessor::text() const
{
    QMutexLocker locker(&m_mutex);
    return m_text;
}

void TextProcessor::setText(const QString &text)
{
    QMutexLocker locker(&m_mutex);
    m_text = text;
}

void TextProcessor::addProcess(ITextProcess *process)
{
    if (!process)
        return;
    QMutexLocker locker(&m_mutex);
    m_processes.append(process);
    QTimer::singleShot(0, this, SLOT(doProcess()));
}

void TextProcessor::doProcess()
{
    qDebug() << "Running TextProcessor::doProcess() in " << QThread::currentThreadId();

    forever {
        ITextProcess* process = 0;
        QString oldText;
        {
            QMutexLocker locker(&m_mutex);
            if (m_processes.isEmpty()) {
                return;
            } else {
                process = m_processes.takeFirst();
            }

            oldText = m_text;
        }

        if (!process) {
            break;
        }
        QString newText = process->process(oldText);
        delete process;
        {
            QMutexLocker locker(&m_mutex);
            m_text = newText;
            emit textReady();
        }
    }
}

