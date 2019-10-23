#include "stack.h"
#include <gtest.h>

TEST(TStack, can_create_stack_with_positive_length)
{
  ASSERT_NO_THROW(TStack<int> st(5));
}
TEST(TStack, throws_when_create_stack_with_negative_length)
{
	ASSERT_ANY_THROW(TStack<int> st(-1));
}
TEST(TStack, throws_when_cant_create_too_large_stack)
{
	ASSERT_ANY_THROW(TStack<int> st(MaxStackSize + 1));
}
TEST(TStack, can_check_stack_is_empty)
{
	TStack<int> st(5);
	EXPECT_TRUE(1==st.IsEmpty());
}
TEST(TStack, can_check_stack_is_full)
{
	TStack<int> st(5);
	for (int i = 0; i < 5; i++)
		st.Push(i);
	EXPECT_TRUE(1 == st.IsFull());
}
TEST(TStack, take_element_on_pop_with_corrected_value)
{
	TStack<int> st(5);
	for (int i = 0; i < 5; i++)
		st.Push(i);
	EXPECT_TRUE(4== st.Pop());
}
TEST(TStack, different_memories_two_stacks)
{
	TStack<int> st1(5), st2(6);
	EXPECT_TRUE(&st1 != &st2);
}
TEST(TStack, can_check_length_stack)
{
	TStack<int> st(5);
	for (int i = 0; i < 5; i++)
		st.Push(i);
	EXPECT_TRUE(5== st.StackLength());
}