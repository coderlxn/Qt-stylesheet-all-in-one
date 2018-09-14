#include "mainwindow.h"
#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile file(":/basic.css");
    file.open(QFile::ReadOnly);
    QString styleSheet = QString::fromUtf8(file.readAll());

    a.setStyleSheet(styleSheet);

    MainWindow w;
    w.show();

    return a.exec();
}
