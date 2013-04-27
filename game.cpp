#include <QtGui/QApplication>
#include "mainwindow.h"

/**
 * @mainpage CSCI-102 Programming Assignment #5
 * @section purpose Purpose/Overview
 * @section requirements Requirements
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.show();

    return a.exec();
}
