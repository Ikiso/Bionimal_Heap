#include "binomial_tree.h"
#include <iostream>

binomial_tree::binomial_tree() {
}

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
	root->child = newUnit;
}