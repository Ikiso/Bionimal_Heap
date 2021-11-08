#include "binomial_heap.h"
#include <bitset> //для создания по битам
#include <string>
#include <iostream> //для cout
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
			cout << "\nB - " << j;
		}
	}
}

binomial_heap::binomial_heap(int size) {
	create(size);
}

binomial_heap::binomial_heap() {
}