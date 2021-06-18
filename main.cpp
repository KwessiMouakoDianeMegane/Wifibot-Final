#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Creation de la fenetre
    MainWindow w;
    //Affichage
    w.show();
    return a.exec();
}
