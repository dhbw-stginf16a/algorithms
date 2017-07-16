#include <stdlib.h>

#include "stack.h"

stack* initStack(size_t size)
{
	stack* temp = malloc(sizeof(stack));
	temp->integers = calloc(size, sizeof(int));
	temp->stackSize = size;
	temp->current = 0;
	return temp;
}

int* popStack(stack* stackToPop)
{
	if ((stackToPop == NULL) || (stackToPop->current == 0))
		return NULL;
	return stackToPop->integers + --stackToPop->current;
}

void pushStack(stack* theStack, int value)
{
	if ((theStack == NULL) || (theStack->current == theStack->stackSize))
		return;
	
	theStack->integers[theStack->current++] = value;
	return;
}

void destroyStack(stack* theStack)
{
	if (theStack == NULL)
		return;
	
	free(theStack->integers);
}
