#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Калькулятор");
    w.setFixedSize(QSize(319, 390));
    w.show();
    return a.exec();
}
