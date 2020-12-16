#include "StackList.h"
#include "../gtest/gtest.h"

TEST(TStackList, can_create_StackList)
{
	ASSERT_NO_THROW(TStackList<int> S);
}

TEST(TStackList, create_empty_StackList)
{
	TStackList<int> S;
	EXPECT_EQ(true, S.IsEmpty());
}

TEST(TStackList, create_full_StackList)
{
	TStackList<int> S;
	EXPECT_EQ(false, S.IsFull());
}

TEST(TStackList, can_push)
{
	TStackList<int> S;
	ASSERT_NO_THROW(S.Push(3));
}

TEST(TStackList, can_get_elem)
{
	TStackList<int> S;
	S.Push(4);
	EXPECT_EQ(4, S.Get());
}

TEST(TStackList, can_copy_StackList)
{
	TStackList<int> S1;
	S1.Push(1);
	ASSERT_NO_THROW(TStackList<int> S2(S1));
}

TEST(TStackList, can_get_count)
{
	TStackList<int> S;
	S.Push(1);
	S.Push(2);
	EXPECT_EQ(2, S.GetCount());
}

TEST(TStackList, can_get_max_elem)
{
	TStackList<int> S;
	S.Push(1);
	S.Push(5);
	S.Push(3);
	S.Push(15);
	EXPECT_EQ(15, S.Max_elem());
}

TEST(TStackList, can_get_min_elem)
{
	TStackList<int> S;
	S.Push(1);
	S.Push(5);
	S.Push(3);
	S.Push(15);
	EXPECT_EQ(1, S.Min_elem());
}