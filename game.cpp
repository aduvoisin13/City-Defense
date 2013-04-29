#include <QtGui/QApplication>
#include "mainwindow.h"

/**
 * @mainpage CSCI-102 Programming Assignment #5
 * @section purpose Purpose/Overview
 * To create a fully working video game within the constraints
 * of Qt and following the provided guidelines.
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.show();

    return a.exec();
}
