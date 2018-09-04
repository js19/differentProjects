#include <iostream>

using namespace std;

/*
Simple linked list written in C++
*/

struct node {
	int num; 
	struct node *next;
};

void printList(node *n) {
	struct node *current = n;
	
	while (current != NULL) {
		cout << current->num << " ";
		current = current->next;
	}
	cout << endl;
	delete n;
	n = NULL;
}


void addToList(int num, node *n) {
	if (n->num <= 0) {
		n->num = num;
		n->next = NULL;
	}
	else {
		struct node *next = new node();
		next->num = num;
		next->next = NULL;
		while (n->next != NULL) {
			n = n->next;
		}
		n->next = next;
	}
}

int main() {

	node *n = new node();

	for (int i = 1; i <= 10; i++) {
		addToList(i, n);
	}
	
	printList(n);

	return 0;
}