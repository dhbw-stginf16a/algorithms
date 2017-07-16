/*
 * This is a stack of signed integers
 * Implemented by Daniel Rutz
 */
typedef struct stack
{
	int* integers;
	size_t stackSize;
	size_t current;
} stack;

stack* initStack(size_t size);
int* popStack(stack* stackToPop);
void pushStack(stack* theStack, int value);
void destroyStack(stack* theStack);
