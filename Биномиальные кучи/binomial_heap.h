#pragma once
#include "binomial_tree.h"
class binomial_heap : public binomial_tree
{
private:

public:
	//������������
	binomial_heap();
	binomial_heap(int size);
	node* head = new node; //������ ������
	void create(int size); //������� �������� ��������� �� ����� �����
};

