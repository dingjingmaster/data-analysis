//
// Created by dingjing on 2/14/25.
//
#include <QApplication>

#include "daemon.h"


int main(int argc, char *argv[])
{
    QApplication app (argc, argv);

    Daemon daemon;

    daemon.init();

    daemon.run();

    return QApplication::exec();
}
