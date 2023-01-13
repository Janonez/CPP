#pragma once

//namespace AQueue
//{
//	// –°A µœ÷
//	struct Node
//	{
//		struct Node* next;
//		int val;
//	};
//
//	struct Queue
//	{
//		struct Node* head;
//		struct Node* tail;
//	};
//}

namespace Janonez
{
	struct Node
	{
		struct Node* next;
		int val;
	};

	struct Queue
	{
		struct Node* head;
		struct Node* tail;
	};

	void QueueInit(struct Queue* q)
	{}

	void QueuePush(struct Queue* q, int x)
	{}

}