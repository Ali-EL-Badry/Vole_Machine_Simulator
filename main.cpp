#include "mainwindow.h"
#include <QApplication>
#include <QMainWindow>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setMinimumSize(1035, 725);
    w.setMaximumSize(1035, 725);
    w.show();
    return a.exec();
}
