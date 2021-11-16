#include "binomial_heap.h"
#include <bitset> //для создания по битам
#include <string>
#include <iostream> //для cout
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

void binomial_heap::view(int degree, string nameHeap) {
	node* temp = head;
	while (temp->next != NULL && temp->root->degree != degree) {
		temp = temp->next;
	}
	if (temp->root->degree != degree) {
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

void binomial_heap::sort() {
	node* temp = head;
	if (temp == NULL) {
		return;
	}
	if (temp->next == NULL) {
		return;
	}
	if (temp->next->next == NULL) {
		if (temp->root->degree == temp->next->root->degree) {
			if (temp->root->key <= temp->next->root->key) {
				temp->next->root->parent = temp->root;
				temp->next->root->sibling = temp->root->child;
				temp->root->child = temp->next->root;
				temp->root->degree = temp->root->degree + 1;
				delete temp->next;	
				temp->next = NULL;
			}
			else
			{
				head = temp->next;
				temp->root->parent = temp->next->root;
				temp->root->sibling = temp->next->root->child;
				temp->next->root->child = temp->root;
				temp->next->root->degree = temp->next->root->degree + 1;
				delete temp;
			}
		}
		return;
	}
	while (1) {
		if (temp->next->next == NULL) {
			/*if (temp->next->root->degree == temp->next->next->root->degree) {
				if (temp->next->root->key <= temp->next->next->root->key) {
					temp->next->next->root->parent = temp->next->root;
					temp->next->next->root->sibling = temp->next->root->child;
					temp->next->root->child = temp->next->next->root;
					temp->next->root->degree = temp->next->root->degree + 1;
					delete temp->next->next;
					temp->next->next = NULL;
				}
				else
				{
					temp = temp->next;
					temp->next->root->parent = temp->next->next->root;
					temp->next->root->sibling = temp->next->next->root->child;
					temp->next->next->root->child = temp->next->root;
					temp->next->next->root->degree = temp->next->next->root->degree + 1;
					node* temp1 = temp->next;
					temp->next = temp->next->next;
					delete temp1;
				}
				return;
			}*/
			if (temp->root->degree == temp->next->root->degree) {
				if (temp->root->key <= temp->next->root->key) {
					temp->next->root->parent = temp->root;
					temp->next->root->sibling = temp->root->child;
					temp->root->child = temp->next->root;
					temp->root->degree = temp->root->degree + 1;
					delete temp->next;
					temp->next = NULL;
				}
				else
				{
					head = temp->next;
					temp->root->parent = temp->next->root;
					temp->root->sibling = temp->next->root->child;
					temp->next->root->child = temp->root;
					temp->next->root->degree = temp->next->root->degree + 1;
					delete temp;
				}
			}
			return;
		}
		if (temp->root->degree != temp->next->root->degree) {
			temp = temp->next;
			continue;
		}
		if (temp->root->degree == temp->next->root->degree && temp->next->root->degree == temp->next->next->root->degree) {
			temp = temp->next;
			continue;
		}
		if (temp->root->degree == temp->next->root->degree && temp->next->root->degree != temp->next->next->root->degree) {
			if (temp->root->key <= temp->next->root->key) {
				temp->next->root->parent = temp->root;
				temp->next->root->sibling = temp->root->child;
				temp->root->child = temp->next->root;
				temp->root->degree = temp->root->degree + 1;
				node* temp1 = temp->next;
				temp->next = temp->next->next;
				delete temp1;
			}
			else
			{
				temp->root->parent = temp->next->root;
				temp->root->sibling = temp->next->root->child;
				temp->next->root->child = temp->root;
				temp->next->root->degree = temp->next->root->degree + 1;
				node* temp1 = head;
				while (temp1->next != temp) {
					temp1 = temp1->next;
				}
				temp1->next = temp->next;
				delete temp;
			}
			continue;
		}
	};
	return;
}

binomial_heap::binomial_heap(int size) {
	create(size);
}

binomial_heap::binomial_heap(node* head) {
	this->head = head;
}

binomial_heap::binomial_heap() {
}