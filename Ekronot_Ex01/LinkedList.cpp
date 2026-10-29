#include "LinkedList.h"
#include <stdio.h>
/*
 adds a new node with the given value to the start of the list.
 head is passed as a pointer to a pointer, because the head itself changes.
*/
void addToHead(Node** head, int value)
{
	Node* newNode = new Node;

	newNode->value = value;
	newNode->next = *head; // the new node points to the old head
	*head = newNode;       // and becomes the new head
}

/*
 removes the first node of the list and puts its value in *value.
 returns 1 on success, or 0 if the list is empty.
 (a return value of -1 would not be clear, because -1 can be stored in the list)
*/
int removeFromHead(Node** head, int* value)
{
	Node* temp;

	if (*head == NULL)
	{
		return 0;
	}

	temp = *head;
	*value = temp->value;
	*head = temp->next; // the second node becomes the head
	delete temp;
	return 1;
}

/*
 frees all the nodes of the list and sets the head to null.
*/
void freeList(Node** head)
{
	Node* temp;

	while (*head != NULL)
	{
		temp = *head;
		*head = temp->next;
		delete temp;
	}
}

