#include <QtCore>
#include <QCoreApplication>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QDebug>

#include "config.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

//    QNetworkAccessManager manager;

//    // Подключаем сигнал finished к лямбда-функции
//    QObject::connect(&manager, &QNetworkAccessManager::finished, [](QNetworkReply *reply) {
//        if (reply->error() == QNetworkReply::NoError) {
//            QByteArray responseData = reply->readAll(); // Читаем данные ответа
//            qDebug() << "Response data:" << responseData; // Выводим в консоль
//        } else {
//            qDebug() << "Error:" << reply->errorString(); // Выводим ошибку
//        }
//        reply->deleteLater(); // Освобождаем память
//        QCoreApplication::quit(); // Завершаем приложение
//    });

//    // Выполняем GET-запрос
//    QNetworkRequest request(QUrl("https://example.com/"));
//    manager.get(request);

    qDebug() << CMAKE_PROJECT_NAME;
    qDebug() << GIT_AUTHOR;
    qDebug() << GIT_AUTHOR_LINK;
    qDebug() << GIT_PROJECT_LINK;
    qDebug() << BUILD_DATE;

    return a.exec();
}
