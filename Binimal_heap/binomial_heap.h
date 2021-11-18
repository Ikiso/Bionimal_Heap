#ifndef BINOMIAL_HEAP_H
#define BINOMIAL_HEAP_H

#include <QMainWindow>
#include <QWidget>
#include "binomial_tree.h"

class binomial_heap : public Binomial_tree
{
public:
    binomial_heap(QWidget *parent = 0);
    void view();
};

#endif // BINOMIAL_HEAP_H
