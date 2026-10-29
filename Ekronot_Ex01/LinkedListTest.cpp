#include <stdio.h>
#include "LinkedList.h"

/* test to print the linked list */


void printList(Node* head)
{
	Node* current = head;
	printf("Current list: ");
	while (current != NULL)
	{
		printf("%d -> ", current->value);
		current = current->next;
	}
	printf("NULL\n");
}

int main()
{
	Node* head = NULL;
	int val = 0;

	printf("List created (empty).\n");
	printList(head);

	printf("Adding 11 to the list...\n");
	addToHead(&head, 1);
	printList(head);

	printf("Removing item from the list...\n");
	if (removeFromHead(&head, &val))
	{
		printf("Removed value: %d\n", val);
	}
	printList(head);

	freeList(&head);
	printf("List freed.\n");
	printList(head);

	return 0;
}