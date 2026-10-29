#include <stdio.h>
#include "Utils.h"
#include "Stack.h"

/*
 reverses the array nums (of size 'size'), using a stack.
 example: 1,2,3,4 -> 4,3,2,1
*/
void reverse(int* nums, unsigned int size)
{
	Stack s;
	unsigned int i;

	initStack(&s);

	// push all the numbers: the last number pushed is on top of the stack
	for (i = 0; i < size; i++)
	{
		push(&s, (unsigned int)nums[i]);
	}

	// pop all the numbers back into the array: the last number comes out first
	for (i = 0; i < size; i++)
	{
		nums[i] = pop(&s);
	}

	cleanStack(&s);
}

/*
 reads 10 integers from the user, and returns a new array
 with the numbers in reverse order.
 the array is allocated dynamically, so the caller must delete[] it.
*/
int* reverse10()
{
	int* nums = new int[10];
	int i;

	for (i = 0; i < 10; i++)
	{
		// scanf returns the number of values read, it should be 1
		if (scanf("%d", &nums[i]) != 1)
		{
			nums[i] = 0; // reading failed, use 0 as a default value
		}
	}

	reverse(nums, 10);
	return nums;
}