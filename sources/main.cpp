#include <QtCore>

#include "exampleLib.hpp"

int main()
{
    QVector<int> a; // Qt object

    for (int i=0; i<10; i++)
    {
        a.append(i);
        qDebug() << i;

        qDebug() << exampleLib::add(i,i);
    }

    /* manipulate a here */

    QSettings settings;

    settings;

    return 0;
}
