#ifndef BINOMIAL_HEAP_H
#define BINOMIAL_HEAP_H

#include <QMainWindow>
#include <QGridLayout>
#include <QWidget>
#include <QVBoxLayout>
#include "binomial_tree.h"

class binomial_heap : public Binomial_tree
{
public:
    binomial_heap(QWidget *parent = 0);
    QGridLayout * grid;
    QVBoxLayout  * menuGrid;
    void view();
    void menu();
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
                    if (temp1 == NULL) break;
                    temp1->next = newHead;
                    newHead = temp1;
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
        void merge(node* head);
        void insert(node*& Node);
        void sort();
        void changeQrid(unit*temp1, int xx, int xy);
        int sdvig(int i);
        void cleargrid(QGridLayout *layout, int row, int row_end){
            for (            int row_temp = row;row_temp <= row_end ; row_temp++) {
                removeRow(layout, row_temp, true);
            }
        }
        // Удаляет содержимое данной строки макета.
          static void removeRow(QGridLayout *layout, int row, bool deleteWidgets = true) {
            remove(layout, row, -1, deleteWidgets);
            layout->setRowMinimumHeight(row, 0);
            layout->setRowStretch(row, 0);
          }



          // Удаляет содержимое заданного столбца макета.
          static void removeColumn(QGridLayout *layout, int column, bool deleteWidgets = true) {
            remove(layout, -1, column, deleteWidgets);
            layout->setColumnMinimumWidth(column, 0);
            layout->setColumnStretch(column, 0);
          }



          // Удаляет содержимое данной ячейки макета.
          static void removeCell(QGridLayout *layout, int row, int column, bool deleteWidgets = true) {
            remove(layout, row, column, deleteWidgets);
          }
private:
          static void remove(QGridLayout *layout, int row, int column, bool deleteWidgets) {
              for (int i = layout->count() - 1; i >= 0; i--) {
                int r, c, rs, cs;
                layout->getItemPosition(i, &r, &c, &rs, &cs);
                if (
                    (row == -1 || (r <= row && r + rs > row)) &&
                    (column == -1 || (c <= column && c + cs > column))) {
                  // Этот элемент макета подлежит удалению.
                  QLayoutItem *item = layout->takeAt(i);
                  if (deleteWidgets) {
                    deleteChildWidgets(item);
                  }
                  delete item;
                }
              }
            }
          static void deleteChildWidgets(QLayoutItem *item) {
              QLayout *layout = item->layout();
              if (layout) {
                // Рекурсивно обрабатывать все дочерние элементы.
                int itemCount = layout->count();
                for (int i = 0; i < itemCount; i++) {
                  deleteChildWidgets(layout->itemAt(i));
                }
              }
              delete item->widget();
            }
};

#endif // BINOMIAL_HEAP_H
