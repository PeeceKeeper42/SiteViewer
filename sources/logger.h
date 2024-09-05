#ifndef LOGGER_H
#define LOGGER_H
//==============================================================================
#include <QObject>
#include <QCoreApplication>
#include <QSettings>
#include <QDir>


//==============================================================================
class Logger : public QObject
{
    Q_OBJECT
public:
    //explicit Logger(QObject *parent = nullptr);
    Logger() = 0;
    Logger(Logger &other) = 0;
    void operator=(const Logger &) = 0;

    ~Logger();

    static Logger *GetInstance(const QString& filePath, QObject *parent = nullptr);

private:
    QFile* _logFile;
    QString _filePath;

    const QString _defaultLogFilePath { QCoreApplication::applicationDirPath()
                                           .append(QDir::separator())
                                           .append(QString("latest.txt")) };
};
//==============================================================================
using Log = Logger;
#endif // LOGGER_H
