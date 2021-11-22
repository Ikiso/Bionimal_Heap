#include "mainwindow.h"
#include "binomial_tree.h"
#include "binomial_heap.h"
#include <QApplication>
#include <ctime> //для рандома

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    binomial_heap window;
    window.move(600, 320);
    window.menu();
    window.setWindowTitle("Биномиальные кучи");
    window.show();
    return a.exec();
}
