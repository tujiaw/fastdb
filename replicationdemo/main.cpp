#include "replicationdemo.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    replicationdemo w;
    w.show();
    return a.exec();
}
