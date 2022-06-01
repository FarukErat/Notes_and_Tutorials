#include "mainwindow.hpp"
#include "menu.hpp"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Menu m(&w);
    m.show();
    return a.exec();
}
