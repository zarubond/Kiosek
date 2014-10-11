#include <QtGui/QGuiApplication>

#include "kiosek.h"
#include <iostream>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    Kiosek kiosek;
    kiosek.load();


    return app.exec();
}
