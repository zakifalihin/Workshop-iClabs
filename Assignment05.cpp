#include <iostream>
using namespace std;

struct Node{
	int data;
	Node *next;
};

Node *head, *tail, *n, *x;

void createNewNode(int data){
	n = new Node;
	n->data = data;
	tail = n;
	head = n;
	tail->next = NULL;
}

void addBack(int data){
	n = new Node;
	n->data = data;
	tail->next = n;
	tail = n;
	tail->next = NULL;
}

void addFront(int data){
	n = new Node;
	n->data = data;
	n->next = head;
	head = n;
}

void addMid(int j, int data){
	x = head;
	while(x->data != j) x = x->next;
	n = new Node;
	n->data = data;
	n->next = x->next;
	x->next = n;
}

void removeFront(){
	x = head;
	head = head->next;
	delete x;
	x = NULL;
}

void removeBack(){
	x = head;
	while(x->next != tail) x = x->next;
	tail = x;
	delete x->next;
	tail->next = NULL;
}

void removeMid(int i){
	Node *temp=NULL;
	x = head;
	while(x->data != i){
		temp = x;
		x = x->next;
	}
	temp->next = x->next;
	delete x;
	x = NULL;
}

bool dataExists(int data){
	x = head;
	while(x != NULL){
		if (data == x->data)
			return true;
		x = x->next;
	}
	return false;
}

void remove(int data){
	if(data == head->data)
		removeFront();
	else if(data == tail->data)
		removeBack();
	else{
		if(dataExists(data))
			removeMid(data);
	}	
}

void insert(int data) {
    if (!head) return createNewNode(data);
    if (data < head->data)
        return addFront(data);
    if (data > tail->data) 
        return addBack(data);

    Node* x = head;
    while (x->next && x->next->data < data)
        x = x->next;

    addMid(x->data, data);
}


void tampil(){
	x = head;
	while(x != NULL){
		cout << x->data << " ";
		x = x->next;
	}
}

int main(){

    // createNewNode(3);
	// addBack(5);
	// addFront(2);
	// addMid(3, 4);
	// remove(2);

    insert(5);
	insert(4);
	insert(7);
	insert(10);
    insert(8);
    insert(2);
    insert(6);
    insert(8);
    insert(7);
    
	tampil();
}