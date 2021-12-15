#include "mainwindow.h"
#include "ukeymap.h"

#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    uKeymap ukeymap("/Users/liz/VIM-shortcuts/config/keymap.json");

    /*
    QFile qssFile(":/test.qss");
    qssFile.open(QFile::ReadOnly);
    if (qssFile.isOpen()){
        QString style = QString::fromLatin1(qssFile.readAll());
        w.setStyleSheet(style);
        qssFile.close();
    }
*/
    return a.exec();
}
