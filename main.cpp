#include "MainWindow.h"
#include <QtWidgets/QApplication>
#include <QCoreApplication>
#include <QThread>
#include <QObject>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QObject::connect(&w, SIGNAL(exitProg()), &a, SLOT(quit()));

    return a.exec();
}
