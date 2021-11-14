#include <iostream>
#include "binomial_heap.h"
#include "binomial_tree.h"
#include <ctime> //для рандома
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(0));
    int temp;
    cout << "Введите число узлов: ";
    cin >> temp;
    binomial_heap H{temp};
    H.view("H");
    cout << "\nВведите индекс узла, который требуется удалить: ";
    cin >> temp;
    H.view(temp, "H");
    cout << endl;
    binomial_heap D{ H.deleteRoot(temp) };
    H.view("H");
    cout << endl << '+' << endl;
    D.view("D");
    cout << endl << endl;
    H.merge(D);
    H.view("H");
    cout << "Чтобы получить список элементов в корне введите ключ объекта: ";
    cin >> temp;
    H.view(temp, "H");
}
