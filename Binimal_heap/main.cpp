#include "mainwindow.h"
#include "binomial_tree.h"
#include "binomial_heap.h"
#include <QApplication>
#include <ctime> //для рандома

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    binomial_heap window;
    window.menu();
    //window.create(1023);
    //binomial_heap D(window.deleteRoot(4));
    //D.move(600, 320);
    //D.show();
    //D.view();
    //window.merge(D.head);
    window.move(600, 320);
    window.setWindowTitle("Биномиальные кучи");
    window.show();
    //window.view();

    return a.exec();
}
