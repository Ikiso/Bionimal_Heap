#pragma once
#include "binomial_tree.h"
class binomial_heap : public binomial_tree
{
private:
	void viewUnit(unit* Unit, string nameHeap);
public:
	//������������
	binomial_heap();
	binomial_heap(int size);
	binomial_heap(node* head);
	node* head = new node; //������ ������
	void create(int size); //������� �������� ��������� �� ����� �����
	node* deleteRoot(int key) {
		node* temp = head;
		node* temp1 = head;
		while (temp->next != NULL && temp->root->key != key) {
			temp = temp->next;
		}
		if (temp->root->key != key) {
			return NULL;
		}
		if (temp1 == temp) {
			head = temp->next;
		}
		else
		{
			while (temp1->next != temp) {
				temp1 = temp1->next;
			}
			temp1->next = temp->next;
		}
		if (temp->root->child != NULL) {
			unit* temp_unit = temp->root->child;
			node* newHead = new node; //������ ������ ������
			newHead->root = temp_unit;
			newHead->next = NULL;
			temp_unit->parent = NULL;
			while (temp_unit != NULL) {
				temp1 = new node;
				temp1->next = NULL;
				temp1->root = temp_unit->sibling;
				if (temp_unit->sibling != NULL) {
					temp_unit->sibling = NULL;
					temp_unit = temp1->root;
					temp1->root->parent = NULL;
				}
				else
				{
					temp_unit->sibling = NULL;
					temp_unit = temp1->root;
					temp1 = NULL;
				}
				temp = newHead;
				while (temp->next != NULL) {
					temp = temp->next;
				}
				temp->next = temp1;
			}
			//temp = head;
			//while (temp->next != NULL && temp->root->key != key) {
			//	temp = temp->next;
			//}
			return newHead;
		}
		return NULL;
	}
	void view(string nameHeap);
	void view(int key, string nameHeap);
};

