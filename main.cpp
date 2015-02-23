#include <Python.h>
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    Py_Initialize();
    PyRun_SimpleString("print('ayyyyyyoylmao')");

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    int m=a.exec();
    Py_Finalize();
    return m;
}
