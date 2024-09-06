#ifndef LOGGER_H
#define LOGGER_H
//==============================================================================
#include <QCoreApplication>
#include <QObject>
#include <QMutex>
#include <QDir>


//==============================================================================
class Logger : public QObject
{
    Q_OBJECT
public:
    Logger(Logger &other) = 0;
    Logger(Logger &&other) = 0;
    void operator=(const Logger &) = 0;
    ~Logger();

    bool isLogFileOpen();
    static Logger* getInstance();

private:
    static Logger *_instance {nullptr};
    static QMutex mutex;
    Logger();


    /*!
     * \brief _logFile
     *
     * \todo v1.1 - Remake to several files
     * \todo v1.2 - Implement write destination class (console,file,server),
     * add functionality to add/remove destinations,
     * add features to implement own destinations
     */
    QFile* _logFile {nullptr};
    QString _filePath;

    const QString _defaultLogFilePath { QCoreApplication::applicationDirPath()
                                           .append(QDir::separator())
                                           .append(QString("latest.txt")) };
};
//==============================================================================
using Log = Logger;
#endif // LOGGER_H
