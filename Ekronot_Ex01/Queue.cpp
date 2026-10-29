#include "Queue.h"
#include "stdio.h"
/*
 initializes the queue: allocates an array of 'size' places
 and sets the queue to be empty.
*/
void initQueue(Queue* q, unsigned int size)
{
	q->elements = new unsigned int[size];
	q->capacity = size;
	q->count = 0;
	q->head = 0;
}

/*
 cleans the queue: frees the array and resets the fields.
*/
void cleanQueue(Queue* q)
{
	delete[] q->elements;
	q->elements = NULL;
	q->capacity = 0;
	q->count = 0;
	q->head = 0;
}

/*
 adds newValue to the end of the queue.
 if the queue is full, nothing happens.
*/
void enqueue(Queue* q, unsigned int newValue)
{
	unsigned int tail;

	if (isFull(q))
	{
		return;
	}

	// the first free place is 'count' places after the head
	// (the % makes us go back to the start of the array when we reach its end)
	tail = (q->head + q->count) % q->capacity;
	q->elements[tail] = newValue;
	q->count++;
}

/*
 removes the element at the front of the queue and returns it.
 if the queue is empty, returns -1.
*/
int dequeue(Queue* q)
{
	int value;

	if (isEmpty(q))
	{
		return -1;
	}

	value = (int)q->elements[q->head];
	q->head = (q->head + 1) % q->capacity; // move head to the next element
	q->count--;
	return value;
}

/*
 returns true if the queue has no elements.
*/
bool isEmpty(Queue* s)
{
	return s->count == 0;
}

/*
 returns true if the queue has no free places left.
*/
bool isFull(Queue* s)
{
	return s->count == s->capacity;
}