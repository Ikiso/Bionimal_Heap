#ifndef BINOMIAL_HEAP_H
#define BINOMIAL_HEAP_H

#include <QMainWindow>
#include <QGridLayout>
#include <QWidget>
#include "binomial_tree.h"

class binomial_heap : public Binomial_tree
{
public:
    binomial_heap(QWidget *parent = 0);
    QGridLayout *grid = new QGridLayout(this);
    void view();
    void viewUnit(unit* Unit, QString nameHeap);
    //binomial_heap();
        binomial_heap(int size);
        binomial_heap(node* head);
        node* head = new node; //голова списка
        void create(int size); //функция создания элементов по числу узлов
        node* deleteRoot(int degree) {
            node* temp = head;
            node* temp1 = head;
            while (temp->next != NULL && temp->root->degree != degree) {
                temp = temp->next;
            }
            if (temp->root->degree != degree) {
                return NULL;
            }
            if (temp1 == temp) {
                head = temp->next;
            }
            else
            {
                while (temp1->next != temp) {
                    temp1 = temp1->next;
                }
                temp1->next = temp->next;
            }
            if (temp->root->child != NULL) {
                unit* temp_unit = temp->root->child;
                node* newHead = new node; //голова нового списка
                newHead->root = temp_unit;
                newHead->next = NULL;
                temp_unit->parent = NULL;
                while (temp_unit != NULL) {
                    temp1 = new node;
                    temp1->next = NULL;
                    temp1->root = temp_unit->sibling;
                    if (temp_unit->sibling != NULL) {
                        temp_unit->sibling = NULL;
                        temp_unit = temp1->root;
                        temp1->root->parent = NULL;
                    }
                    else
                    {
                        temp_unit->sibling = NULL;
                        temp_unit = temp1->root;
                        temp1 = NULL;
                    }
                    temp = newHead;
                    while (temp->next != NULL) {
                        temp = temp->next;
                    }
                    temp->next = temp1;
                }
                //temp = head;
                //while (temp->next != NULL && temp->root->key != key) {
                //	temp = temp->next;
                //}
                return newHead;
            }
            return NULL;
        }
        void view(QString nameHeap);
        void view(int degree, QString nameHeap);
        void merge(binomial_heap H);
        void insert(node*& Node);
        void sort();
        void changeQrid(unit*temp1, int xx, int xy);
        int sdvig(int i);
};

#endif // BINOMIAL_HEAP_H
