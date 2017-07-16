#include "../Unity/src/unity.h"

#include "../datastructures/stack.h"

#define NUMBERS_TO_TEST 10

void test_stack(void)
{
	int i;
	int* temp;
	stack* test = initStack(NUMBERS_TO_TEST);
	TEST_ASSERT_NOT_NULL(test);
	

	//Push too many elements onto the stack, it should ignore the last one
	for (i = 1; i <= NUMBERS_TO_TEST + 1; i++)
	{
		pushStack(test, i);
	}
	
	//Pop elements and check whether the results are correct
	for (i = NUMBERS_TO_TEST; i > 0; i--)
	{
		temp = popStack(test);
		TEST_ASSERT_NOT_NULL(temp);
		TEST_ASSERT_EQUAL_INT(i, *temp);
	}
	
	//Pop one more element, should not work
	temp = popStack(test);
	TEST_ASSERT_NULL(temp);

	destroyStack(test);
}
