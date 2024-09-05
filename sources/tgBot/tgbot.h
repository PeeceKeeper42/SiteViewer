#ifndef TGBOT_H
#define TGBOT_H
//==============================================================================
#include <QObject>

//==============================================================================
class TgBot : public QObject
{
    Q_OBJECT
public:
    explicit TgBot(QObject *parent = nullptr);
    ~TgBot();

public slots:
    bool sendRequest();
    void getReply();

};
//==============================================================================
using Tg = TgBot;
#endif // TGBOT_H

