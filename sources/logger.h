#ifndef LOGGER_H
#define LOGGER_H
//==============================================================================
#include <QCoreApplication>
#include <QObject>
#include <QMutex>
#include <QDir>

//==============================================================================
class LoggerSettings;
//==============================================================================
/*!
 * \brief The Logger class
 *
 * \todo v1.1 - Remake to several files
 * \todo v1.2 - Implement write destination class (console,file,server),
 * add functionality to add/remove destinations,
 * add features to implement own destinations
 */
class Logger : public QObject
{
    Q_OBJECT
public:
    Logger(Logger &other) = delete;
    Logger(Logger &&other) = delete;
    void operator=(const Logger &) = delete;
    ~Logger();

    static Logger &getInstance();
    bool openFile(QString &fileName);
    bool isOpen();


private:
    Logger();
    static QMutex mutex;

    QFile* _logFile {nullptr};
    QString _filePath;

    const QString _defaultLogFilePath { QCoreApplication::applicationDirPath()
                                           .append(QDir::separator())
                                           .append(QString("latest.txt")) };
};
//==============================================================================
using Log = Logger;
//==============================================================================
class LoggerSettings: public QObject
{
    Q_OBJECT
public:
    bool setLogString();

    const QString defaultFilter {"[{dateTime}] [{lvl}] [{func}] {msg}"};
    const QString defaultAllAvaibleFilters {"[{dateTime}] [{date}] [{time}] "
                                           "[{file}] [{func}] [{line}] "
                                           "[{lvl}] [{level}] [{thread}] "
                                           "[{message}] [{msg}] [{text}] [{txt}]"};
};



#endif // LOGGER_H


