#pragma once

namespace BList
{
	// СBʵ��
	struct Node
	{
		struct Node* next;
		struct Node* prev;
		int val;
	};
}