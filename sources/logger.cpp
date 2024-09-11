#include "logger.h"

#include <QMutexLocker>
#include <QDebug>

//==============================================================================
Logger::Logger()
{
    _logFile = new QFile();
}
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
Logger &Logger::getInstance()
{
    /*
        C++11 guarantee thread safe realisation

        §6.7 [stmt.dcl] p4 If control enters the declaration concurrently while the variable is being initialized,
        the concurrent execution shall wait for completion of the initialization.
    */
    static Logger instance;

    return instance;
}
//==============================================================================
bool Logger::openFile(QString &fileName)
{
    if(_logFile)
    {
        qWarning() << tr("Found not closed file! File name: %1").arg(_logFile->fileName());

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
        return false;
    }

    return true;
}
//==============================================================================
bool Logger::isOpen()
{
    return(_logFile && _logFile->isOpen());
}
//==============================================================================
//bool Logger::Log
//==============================================================================

//==============================================================================

//==============================================================================
