#include "binomial_tree.h"
#include <iostream>

binomial_tree::binomial_tree() {
}

//struct unit {
//		int key; // Ц приоритет узла(ключ)
//		int	value; // Ц данные
//		int degree; //Ц степень узла
//		unit* parent; // Ц указатель на родительский узел
//		unit* child; // Ц указатель на крайний левый дочерний узел
//		unit* sibling; // Ц указатель на правый сестринский узел
//};

//struct node //элемент списка
//{
//	unit* root;
//	node* next;
//};

void binomial_tree::createTree(unit*& root) {
	if (root->degree == 0) {
		return;
	}
	unit* newUnit = new unit;
	newUnit->key = (rand() % 10 + 1) * 3 + root->key;
	newUnit->value = rand() % 10000;
	newUnit->degree = root->degree - 1;
	newUnit->child = createUnit(newUnit, "child");
	newUnit->parent = root;
	newUnit->sibling = createUnit(newUnit, "sibling");
}