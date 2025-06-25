#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

Node *head = nullptr, *tail = nullptr, *n = nullptr, *x = nullptr;

void push(int data) {
	n = new Node;
	n->data = data;
	n->next = head;
	head = n;

	if (head->next == nullptr) {
		tail = head;
	}
}

void pop() {
	if (head != nullptr) {
		x = head;
		head = head->next;
		delete x;

		if (head == nullptr) {
			tail = nullptr;
		}
	}
}

void tampil() {
	x = head;
	while (x != nullptr) {
		cout << x->data << " ";
		x = x->next;
	}
	cout << endl;
}

int main() {
	push(10);
	push(20);
	push(30);
	cout << "Isi stack: ";
	tampil(); 

	return 0;
}
