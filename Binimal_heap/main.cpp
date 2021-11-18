#include "mainwindow.h"
#include "binomial_tree.h"
#include "binomial_heap.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    binomial_heap window;
    window.view();
    window.move(300, 300);
      window.setWindowTitle("Calculator");
      window.show();
    return a.exec();
}
