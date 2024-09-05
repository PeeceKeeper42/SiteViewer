#include "logger.h"

#include <QMutexLocker>

//==============================================================================
Logger::Logger(QString& filePath)
    : _filePath(filePath)
{
    _logFile = new QFile(_filePath);
    if(!_logFile->open(QIODevice::Append | QIODevice::Text))
    {
        qWarning() << tr("Can't open log file: %1").arg(_filePath);

        _logFile->deleteLater();
        _logFile = nullptr;
    }
}
//==============================================================================
Logger::~Logger()
{

}
//==============================================================================
bool Logger::setLogFilePath(const QString &path)
{
    return false;
}
//==============================================================================
QString Logger::logFilePath()
{
    return _filePath;
}
//==============================================================================
Logger Logger::getInstance(QString& filePath,QObject *parent)
{
    QMutexLocker locker(&mutex);

    if(_instance) { return _instance; }

    _instance = new Logger(filePath);

}
//==============================================================================

//==============================================================================

//==============================================================================

//==============================================================================

//==============================================================================
