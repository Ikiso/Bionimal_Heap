#pragma once
#include "binomial_tree.h"
class binomial_heap : public binomial_tree
{
private:

public:
	//конструкторы
	binomial_heap();
	binomial_heap(int size);
	node* head = new node; //голова списка
	void create(int size); //функция создания элементов по числу узлов
};

