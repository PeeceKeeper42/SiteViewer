#include "logger.h"

#include <QMutexLocker>

//==============================================================================
Logger::Logger()
{
    _logFile = new QFile();
}
//==============================================================================
//Logger::Logger()
//{
//    _logFile = new QFile(_filePath);
//    if(!_logFile->open(QIODevice::Append | QIODevice::Text))
//    {
//        qWarning() << tr("Can't open log file: %1").arg(_filePath);

//        _logFile->deleteLater();
//        _logFile = nullptr;
//    }
//}
//==============================================================================
Logger::~Logger()
{
    if(_logFile)
    {
        _logFile->close();
        _logFile->deleteLater();
        _logFile = nullptr;
    }
}
//==============================================================================
Logger Logger::getInstance()
{
    QMutexLocker locker(&mutex);

    if(!_instance)
    {
        _instance = new Logger();
    }

    return _instance;
}
//==============================================================================
bool Logger::openFile(QString &fileName)
{
    if(_logFile)
    {
        qWarning(tr("Found not closed file! File name: %1").arg(_logFile->fileName()));

        _logFile->close();
        _logFile->deleteLater();
        _logFile = nullptr; //unnecessary, but i feel safer with with
    }

    _logFile = new QFile(fileName);
    if(!_logFile->open(QIODevice::Append | QIODevice::Text))
    {
        qWarning() << tr("Can't open file! File name: %1").arg(fileName);

        _logFile->deleteLater();
        _logFile = nullptr;
        return;
    }
}
//==============================================================================
bool Logger::isLogFileOpen()
{
    return(_logFile);//return(_logFile && _methodWriteTestString);
}
//==============================================================================

//==============================================================================

//==============================================================================

//==============================================================================
