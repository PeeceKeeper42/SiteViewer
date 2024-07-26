#include <QtCore>

int main()
{
    QVector<int> a; // Qt object

    for (int i=0; i<10; i++)
    {
        a.append(i);
        qDebug() << i;
    }

    /* manipulate a here */

    return 0;
}
