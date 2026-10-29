#ifndef LINKEDLIST_H
#define LINKEDLIST_H

/* a node in a linked list of integers (positive and negative) */
typedef struct Node
{
	int value;          // the data stored in the node
	struct Node* next;  // pointer to the next node, NULL for the last node
} Node;

void addToHead(Node** head, int value);
int removeFromHead(Node** head, int* value);
void freeList(Node** head);

#endif /* LINKEDLIST_H */
