#include "mainwindow.hpp"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setGameMode(2);
    w.setHumanSide(BLACK);
    // w.setUserSide(WHITE);
    w.show();
    return a.exec();
}
