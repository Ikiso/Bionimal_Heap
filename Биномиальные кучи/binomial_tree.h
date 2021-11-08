#pragma once
#include <iostream>
#include <string>
using namespace std;
class binomial_tree
{
public:
	binomial_tree();

	struct unit {
		int key; // � ��������� ����(����)
		int	value; // � ������
		int degree; //� ������� ����
		unit* parent; // � ��������� �� ������������ ����
		unit* child; // � ��������� �� ������� ����� �������� ����
		unit* sibling; // � ��������� �� ������ ����������� ����
	};

	struct node //������� ������
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

