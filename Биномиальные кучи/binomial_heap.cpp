#include "binomial_heap.h"
#include <bitset> //��� �������� �� �����
#include <string>
#include <iostream> //��� cout
#include <iomanip>
using namespace std;

void binomial_heap::create(int size) {
	string str;
	bitset<32> bit = size;
	bool first = 1;
	str = bit.to_string();
	cout << size << " - ";
	for (int i = 0; i < 32; i++) {
		if (str[i] == '1') {
			for (; i < 32; i++) {
				cout << str[i];
			}
		}
	}
	cout << endl;
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

void binomial_heap::view(string nameHeap){
	node* temp = head;
	node* temp1;
	if (temp == NULL) {
		return;
	}
	do {
		cout << nameHeap << ":(" << temp->root->degree << "|" << temp->root->key << ")   ";
		temp1 = temp;
		temp = temp->next;
	} while (temp1->next != NULL);
}

void binomial_heap::view(int key, string nameHeap) {
	node* temp = head;
	while (temp->next != NULL && temp->root->key != key) {
		temp = temp->next;
	}
	if (temp->root->key != key) {
		return;
	}
	cout << nameHeap << ":(" << temp->root->degree << "|" << temp->root->key << ")   \n";
	viewUnit(temp->root->child, nameHeap);
}

void binomial_heap::viewUnit(unit* Unit, string nameHeap) {
	if (Unit == NULL) {
		return;
	}
	unit* temp = Unit;
	unit* temp1 = Unit;
	do {
		cout << nameHeap << ":(" << temp1->degree << "|" << temp1->key << ") ";
		temp1 = temp1->sibling;
	} while (temp1 != NULL);
	cout << endl;
	viewUnit(temp->child, nameHeap);
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

binomial_heap::binomial_heap(int size) {
	create(size);
}

binomial_heap::binomial_heap(node* head) {
	this->head = head;
}

binomial_heap::binomial_heap() {
}