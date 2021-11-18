#ifndef BINOMIAL_TREE_H
#define BINOMIAL_TREE_H

#include <QMainWindow>
#include <QWidget>
#include <QString>

class Binomial_tree : public QWidget
{
    Q_OBJECT
public:
    explicit Binomial_tree(QWidget *parent = nullptr);
    //Binomial_tree();

        struct unit {
            int key; // – приоритет узла(ключ)
            int	value; // – данные
            int degree; //– степень узла
            unit* parent; // – указатель на родительский узел
            unit* child; // – указатель на крайний левый дочерний узел
            unit* sibling; // – указатель на правый сестринский узел
        };

        struct node //элемент списка
        {
            unit* root;
            node* next;
        };

        void createTree(unit*& root);

        unit* createUnit(unit*& Unit, QString str) {
            if (Unit->degree == 0) {
                return NULL;
            }
            unit* newUnit = new unit;
            newUnit->key = (rand() % 10 + 1) * 3 + Unit->key;
            newUnit->value = rand() % 10000;
            newUnit->degree = Unit->degree - 1;
            if (str == "child") {
                newUnit->parent = Unit;
            }
            else
            {
                newUnit->parent = Unit->parent;
            }
            newUnit->child = createUnit(newUnit, "child");
            newUnit->sibling = createUnit(newUnit, "sibling");
            return newUnit;
        }

signals:

};

#endif // BINOMIAL_TREE_H
