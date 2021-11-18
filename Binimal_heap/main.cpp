#include "mainwindow.h"
#include "binomial_tree.h"
#include "binomial_heap.h"
#include <QApplication>
#include <ctime> //для рандома

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    binomial_heap window;
    window.create(511);
    //binomial_heap H(window.deleteRoot(4));
    //window.merge(H);
    window.move(300, 300);
    window.setWindowTitle("Биномиальные кучи");
    window.show();
    window.view();
    return a.exec();
}
