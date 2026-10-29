#include "Stack.h"
#include "stdio.h"
/*
 initializes the stack: sets it to be empty.
*/
void initStack(Stack* s)
{
	s->head = NULL;
}

/*
 cleans the stack: frees all the nodes of the linked list.
*/
void cleanStack(Stack* s)
{
	freeList(&s->head);
}

/*
 adds element to the top of the stack.
 the top of the stack is the head of the list.
*/
void push(Stack* s, unsigned int element)
{
	addToHead(&s->head, (int)element);
}

/*
 removes the element at the top of the stack and returns it.
 if the stack is empty, returns -1.
*/
int pop(Stack* s)
{
	int value = 0;

	if (!removeFromHead(&s->head, &value))
	{
		return -1; // the list was empty
	}
	return value;
}

/*
 returns true if the stack has no elements.
*/

bool isEmpty(Stack* s)
{
	return s->head == NULL;
}

/*
 returns true if the stack is full.
 the stack has no size limit, so it is never full.
*/
bool isFull(Stack* s)
{
	return false;
}