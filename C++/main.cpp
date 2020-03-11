/**
 *
 *  A linked list is a linear collection of data elements,
 *  whose order is not given by their physical placement in memory.
 *  Instead, each element points to the next. The principal benefit of
 *  a linked list over a conventional array is that the list elements can be
 *  easily inserted or removed without reallocation or reorganization of the
 *  entire structure because the data items need not be stored contiguously in
 *  memory or on disk, while restructuring an array at run-time is a much more
 *  expensive operation. Linked lists allow insertion and removal of nodes at any
 *  point in the list, and allow doing so with a constant number of operations by
 *  keeping the link previous to the link being added or removed in memory during
 *  list traversal.
 *
 *  Description source: https://en.wikipedia.org/wiki/Linked_list
 *
 */


#include <string>
#include <iostream>

#define NODES_COUNT 5

using namespace std;

typedef struct Node {

	// This will be the value stored in each node.
	int value;

	// These will be the references to the previous and next Node, respectively.
	Node *prev, *next;

	Node() {
		prev = next = nullptr;
	}

} Node;

Node *push(Node *);
void print_nodes(const Node *, const bool);

int main() {
	// Initializing head and tail Nodes to nullptr.
	Node *head = nullptr, *tail = nullptr;
	for (int i = 0; i < NODES_COUNT; i++) {
		tail = push(tail);
		// When the LinkedList is empty, the head coincides with the tail.
		if (!head) {
			head = tail;
		}
	}
	cout << "Nodes..." << endl;
	print_nodes(head, false);
	cout << "Now in reverse order..." << endl;
	print_nodes(tail, true);
	return 0;
}

Node *push(Node *tail) {
	// Allocating a new Node instance.
	Node *newNode = new Node();
	cout << "Insert new value: ";
	// Reading a value from cin and storing it into the Node.
	cin >> newNode->value;
	// If the tail is not initialized, it means that the LinkedList is empty.
	// Thus, we can't link the new Node with the tail one.
	if (tail) {
		// Since the new Node will be the tail one, we need to store its pointer
		// into the "next" variable of the current tail Node.
		tail->next = newNode;
		// Then, finalize the linking process by storing, into the "prev" variable
		// of the new Node, the pointer to the old tail.
		newNode->prev = tail;
	}
	return newNode;
}

void print_nodes(const Node *node, const bool reverse_order) {
	// Printing will stop when the Node passed as argument is invalid.
	// As can be deduced, traversing a LinkedList onwards, the recursion
	// will stop then the tail is reached because its next Node is invalid;
	// traversing backwards, it will stop when the head is reached because
	// there's no previous Node.
	if (!node) {
		return;
	}
	printf("Value: %d\n", node->value);
	print_nodes(reverse_order ? node->prev : node->next, reverse_order);
}