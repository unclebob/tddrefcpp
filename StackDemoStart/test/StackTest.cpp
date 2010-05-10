#include "CppUTest/TestHarness.h"
#include "CppUTest/SimpleStringExtensions.h"
#include "DemoStack.h"
#include <string>
#include <sstream>

using namespace std;

TEST_GROUP(Stack) 
{
	Stack<string>* stack;

	virtual void setup() 
	{
		stack = new Stack<string>();
	}
	virtual void teardown() 
	{
		delete stack;
	}
};   // Don't forget the semicolon!!

// TEST(Stack, newStackShouldBeEmpty)
// {
// 	CHECK(stack->Empty());
// }
// 
// TEST(Stack, newStackShouldHaveSizeZero)
// {
// 	LONGS_EQUAL(0, stack->Size());
// }
// 
// TEST(Stack, afterPushStackShouldNotBeEmpty)
// {
// 	string one("1");
// 	stack->Push(one);
// 	CHECK(stack->Empty() == false);
// }
// 
// TEST(Stack, afterFirstPushStackSizeShouldBeOne)
// {
// 	string one("1");
// 	stack->Push(one);
// 	LONGS_EQUAL(1, stack->Size());
// }
// 
// TEST(Stack, afterPushAndPopSizeIsSameAsBeforePush)
// {
// 	int expected = stack->Size();
// 	string one("1");
// 	stack->Push(one);
// 	stack->Pop();
// 	LONGS_EQUAL(expected, stack->Size());
// }
// 
// TEST(Stack, afterPushPopReturnsPushedItem)
// {
// 	string one("1");
// 	stack->Push(one);
// 	CHECK_EQUAL(one, stack->Pop());
// }
// 
// TEST(Stack, afterTwoPushesTwoPopsReturnPushedItemsInReverseOrder)
// {
// 	string one("1");
// 	string two("2");
// 	stack->Push(one);
// 	stack->Push(two);
// 	CHECK_EQUAL(two, stack->Pop());
// 	CHECK_EQUAL(one, stack->Pop());
// }
// 
// TEST(Stack, shouldThrowWhenEmptyStackPopped)
// {
// 	try 
// 	{
// 		stack->Pop();
// 		FAIL("");
// 	} 
// 	catch(Stack<string>::PoppedEmptyStackException& ex)
// 	{
// 	}
// }

