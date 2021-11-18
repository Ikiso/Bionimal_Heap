#include "binomial_heap.h"
#include <QPushButton>
#include <QApplication>
#include <QGridLayout>
#include <bitset> //для создания по битам

binomial_heap::binomial_heap(QWidget *parent) : Binomial_tree(parent)
{

}

using namespace std;

void binomial_heap::create(int size) {
    string str;
    bitset<32> bit = size;
    bool first = 1;
    str = bit.to_string();
    //cout << size << " - ";
    for (int i = 0; i < 32; i++) {
        if (str[i] == '1') {
            for (; i < 32; i++) {
        //		cout << str[i];
            }
        }
    }
    //cout << endl;
    for (int i = 31, j = 0; i >= 0; i--, j++) {
        if (str[i] == '1') {
            if (first == 1) {
                head->next = NULL;
                head->root = new unit;
                head->root->key = (rand() % 10 + 1) * 3;
                head->root->value = rand() % 10000;
                head->root->child = NULL;
                head->root->degree = j;
                head->root->parent = NULL;
                head->root->sibling = NULL;
                createTree(head->root);
                first = 0;
            }
            else
            {
                node* temp = head;
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                node* newNode = new node;
                newNode->next = NULL;
                newNode->root = new unit;
                newNode->root->key = (rand() % 10 + 1) * 3;
                newNode->root->value = rand() % 10000;
                newNode->root->child = NULL;
                newNode->root->degree = j;
                newNode->root->parent = NULL;
                newNode->root->sibling = NULL;
                temp->next = newNode;
                createTree(newNode->root);
            }
        }
    }
}

void binomial_heap::merge(binomial_heap H) {
    node* temp = H.head;
    node* temp1 = NULL;
    if (temp == NULL) {
        return;
    }
    while (temp->next != NULL) {
        insert(temp1);
        temp1 = temp;
        temp = temp->next;
    }
    insert(temp1);
    insert(temp);
}

void binomial_heap::insert(node*& Node) {
    if (Node == NULL) {
        return;
    }
    node* temp = head;
    if (temp == NULL) {
        head = Node;
        Node->next = NULL;
        return;
    }
    if (temp->root->degree > Node->root->degree) {
        head = Node;
        Node->next = temp;
        return;
    }
    while (temp->next != NULL && temp->next->root->degree <= Node->root->degree ) {
        temp = temp->next;
    }
    Node->next = temp->next;
    temp->next = Node;
}

void binomial_heap::sort() {
    node* temp = head;
    if (temp == NULL) {
        return;
    }
    if (temp->next == NULL) {
        return;
    }
    if (temp->next->next == NULL) {
        if (temp->root->degree == temp->next->root->degree) {
            if (temp->root->key <= temp->next->root->key) {
                temp->next->root->parent = temp->root;
                temp->next->root->sibling = temp->root->child;
                temp->root->child = temp->next->root;
                temp->root->degree = temp->root->degree + 1;
                delete temp->next;
                temp->next = NULL;
            }
            else
            {
                head = temp->next;
                temp->root->parent = temp->next->root;
                temp->root->sibling = temp->next->root->child;
                temp->next->root->child = temp->root;
                temp->next->root->degree = temp->next->root->degree + 1;
                delete temp;
            }
        }
        return;
    }
    while (1) {
        if (temp->next->next == NULL) {
            if (temp->root->degree == temp->next->root->degree) {
                if (temp->root->key <= temp->next->root->key) {
                    temp->next->root->parent = temp->root;
                    temp->next->root->sibling = temp->root->child;
                    temp->root->child = temp->next->root;
                    temp->root->degree = temp->root->degree + 1;
                    delete temp->next;
                    temp->next = NULL;
                }
                else
                {
                    head = temp->next;
                    temp->root->parent = temp->next->root;
                    temp->root->sibling = temp->next->root->child;
                    temp->next->root->child = temp->root;
                    temp->next->root->degree = temp->next->root->degree + 1;
                    delete temp;
                }
            }
            return;
        }
        if (temp->root->degree != temp->next->root->degree) {
            temp = temp->next;
            continue;
        }
        if (temp->root->degree == temp->next->root->degree && temp->next->root->degree == temp->next->next->root->degree) {
            temp = temp->next;
            continue;
        }
        if (temp->root->degree == temp->next->root->degree && temp->next->root->degree != temp->next->next->root->degree) {
            if (temp->root->key <= temp->next->root->key) {
                temp->next->root->parent = temp->root;
                temp->next->root->sibling = temp->root->child;
                temp->root->child = temp->next->root;
                temp->root->degree = temp->root->degree + 1;
                node* temp1 = temp->next;
                temp->next = temp->next->next;
                delete temp1;
            }
            else
            {
                temp->root->parent = temp->next->root;
                temp->root->sibling = temp->next->root->child;
                temp->next->root->child = temp->root;
                temp->next->root->degree = temp->next->root->degree + 1;
                node* temp1 = head;
                while (temp1->next != temp) {
                    temp1 = temp1->next;
                }
                temp1->next = temp->next;
                delete temp;
            }
            continue;
        }
    };
    return;
}

binomial_heap::binomial_heap(int size) {
    create(size);
}

binomial_heap::binomial_heap(node* head) {
    this->head = head;
}

//binomial_heap::binomial_heap() {
//}

void binomial_heap::changeQrid(unit*temp1, int xy, int xx) {
    {

        unit* temp = temp1;
        temp = temp->child;
        while (temp != NULL) {
        QString name_button;
        int sdvig = binomial_heap::sdvig(temp->degree);
        name_button += QString::number(temp->degree) + "\n" + QString::number(temp->key); // + "\n" + QString::number(xy) + "," + QString::number(xx + sdvig)
        QPushButton *btn = new QPushButton(name_button, this);
        btn->setFixedSize(40, 40);
        btn->setStyleSheet("QPushButton{"
                                                            "color: #333;"
                                                            "border: 1,5px solid #555;"
                                                            "border-radius: 20px;"
                                                            "border-style: outset;"
                                                            "background: #cbcbcb;}"
                                                            "QPushButton:hover{background: qradialgradient("
                                                            "cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,"
                                                            "radius: 1.35, stop: 0 #fff, stop: 1 #bbb"
                                                            ");}"
                                                            "QPushButton:pressed{border-style: inset;"
                                                            "background: qradialgradient("
                                                                "cx: 0.4, cy: -0.1, fx: 0.4, fy: -0.1,"
                                                                "radius: 1.35, stop: 0 #fff, stop: 1 #ddd"
                                                                ");}");
        btn->setEnabled(false);
        grid->addWidget(btn, xy, xx + sdvig);
        int xyy = xy + 1;
        changeQrid(temp, xyy, xx);
        xx = xx + sdvig;
        temp =  temp->sibling;

        }
    }
}

void binomial_heap::view(){
    setLayout(grid);
    node*temp = head;
    int x = 0;

    if (temp == NULL) {
        return;
    }

    grid->setSpacing(5);

    while (temp != NULL) {
        QString name_button;
        int sdvig;
        sdvig = binomial_heap::sdvig(temp->root->degree);
        name_button += QString::number(temp->root->degree) + "\n" + QString::number(temp->root->key); // + "\n0," + QString::number(x + sdvig)
        QPushButton *btn = new QPushButton(name_button, this);
        btn->setFixedSize(40, 40);
        btn->setStyleSheet("QPushButton{"
                                                            "color: #333;"
                                                            "border: 2px solid #555;"
                                                            "border-radius: 20px;"
                                                            "border-style: outset;"
                                                            "background: qradialgradient( cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4, radius: 1.35, stop: 0 #fff, stop: 1 #888);"
                                                            "padding: 5px;}"
                                                            "QPushButton:hover{background: qradialgradient("
                                                            "cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,"
                                                            "radius: 1.35, stop: 0 #fff, stop: 1 #bbb"
                                                            ");}"
                                                            "QPushButton:pressed{border-style: inset;"
                                                            "background: qradialgradient("
                                                                "cx: 0.4, cy: -0.1, fx: 0.4, fy: -0.1,"
                                                                "radius: 1.35, stop: 0 #fff, stop: 1 #ddd"
                                                                ");}");
        connect(btn, &QPushButton::clicked, [=]{ binomial_heap::changeQrid(temp->root, 1, x);});
        grid->addWidget(btn, 0, x + sdvig);
        x = x + sdvig;
        temp =  temp->next;
//        QThread::usleep(3000000);

    }
    QPushButton *btn = new QPushButton("Del", this);
    btn->setFixedSize(40, 40);
    btn->setStyleSheet("QPushButton{"
                                                        "color: #333;"
                                                        "border: 2px solid #aa0000;"
                                                        "border-radius: 20px;"
                                                        "border-style: outset;"
                                                        "background: qradialgradient( cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4, radius: 1.35, stop: 0 #e50000, stop: 1 #ff00e6);"
                                                        "padding: 5px;}"
                                                        "QPushButton:hover{background: qradialgradient("
                                                        "cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,"
                                                        "radius: 1.35, stop: 0 #e50000, stop: 1 #bbb"
                                                        ");}"
                                                        "QPushButton:pressed{border-style: inset;"
                                                        "background: #bbb;}");
    //connect(btn, &QPushButton::clicked, [=]{ binomial_heap::changeQrid(temp->root, 1, x);}); //changeQrid(grid, temp->root, 1, x)
    grid->addWidget(btn, 0, x + 1);
}

int binomial_heap::sdvig(int i){
    if (i == 0) return 1;
    return pow(2, i-1);
}
