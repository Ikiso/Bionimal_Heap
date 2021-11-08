#pragma once
#include <iostream>
#include <string>
using namespace std;
class binomial_tree
{
public:
	binomial_tree();

	struct unit {
		int key; // Ц приоритет узла(ключ)
		int	value; // Ц данные
		int degree; //Ц степень узла
		unit* parent; // Ц указатель на родительский узел
		unit* child; // Ц указатель на крайний левый дочерний узел
		unit* sibling; // Ц указатель на правый сестринский узел
	};

	struct node //элемент списка
	{
		unit* root;
		node* next;
	};

	void createTree(unit*& root);

	unit* createUnit(unit*& Unit, string str) {
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
};

