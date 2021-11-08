#include <iostream>
#include "binomial_heap.h"
#include "binomial_tree.h"
#include <ctime> //для рандома
using namespace std;

int main()
{
    srand(time(0));
    int size;
    cin >> size;
    binomial_heap H{size};
}
