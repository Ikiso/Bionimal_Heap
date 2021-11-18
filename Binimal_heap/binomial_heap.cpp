#include "binomial_heap.h"
#include <QPushButton>
#include <QGridLayout>

binomial_heap::binomial_heap(QWidget *parent) : Binomial_tree(parent)
{

}

void binomial_heap::view(){
    QGridLayout *grid = new QGridLayout(this);
    grid->setSpacing(5);
    //grid->setHorizontalSpacing(15);

    QPushButton *btn = new QPushButton("B0\n4", this);
    btn->setFixedSize(40, 40);
    grid->addWidget(btn, 0, 0);

    btn = new QPushButton("B2\n7", this);
    btn->setFixedSize(40, 40);
    grid->addWidget(btn, 0, 2);

    btn = new QPushButton("B1\n7", this);
    btn->setFixedSize(40, 40);
    grid->addWidget(btn, 1, 1);

    btn = new QPushButton("B0\n7", this);
    btn->setFixedSize(40, 40);
    grid->addWidget(btn, 2, 1);

    btn = new QPushButton("B0\n7", this);
    btn->setFixedSize(40, 40);
    grid->addWidget(btn, 1, 2);

      setLayout(grid);
}
