#include "todoapps.h"
#include <QApplication>
#include "QFile"
#include "QDebug"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ToDoApps w;
    w.show();
    return a.exec();
}
