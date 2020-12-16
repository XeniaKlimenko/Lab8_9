#include "QueueList.h"
#include "../gtest/gtest.h"

TEST(TQueueList, can_create_QueueList)
{
	ASSERT_NO_THROW(TQueueList<int> Q);
}

TEST(TQueueList, create_empty_QueueList)
{
	TQueueList<int> Q;
	EXPECT_EQ(true, Q.IsEmpty());
}

TEST(TQueueList, create_full_QueueList)
{
	TQueueList<int> Q;
	EXPECT_EQ(false, Q.IsFull());
}

TEST(TQueueList, can_push)
{
	TQueueList<int> Q;
	ASSERT_NO_THROW(Q.Push(3));
}

TEST(TQueueList, can_get_elem)
{
	TQueueList<int> Q;
	Q.Push(4);
	EXPECT_EQ(4, Q.Get());
}

TEST(TQueueList, can_copy_QueueList)
{
	TQueueList<int> Q1;
	Q1.Push(1);
	ASSERT_NO_THROW(TQueueList<int> Q2(Q1));
}

TEST(TQueueList, can_get_count)
{
	TQueueList<int> Q;
	Q.Push(1);
	Q.Push(2);
	EXPECT_EQ(2, Q.GetCount());
}

TEST(TQueueList, can_get_max_elem)
{
	TQueueList<int> Q;
	Q.Push(1);
	Q.Push(5);
	Q.Push(3);
	Q.Push(15);
	EXPECT_EQ(15, Q.Max_elem());
}

TEST(TQueueList, can_get_min_elem)
{
	TQueueList<int> Q;
	Q.Push(1);
	Q.Push(5);
	Q.Push(3);
	Q.Push(15);
	EXPECT_EQ(1, Q.Min_elem());
}