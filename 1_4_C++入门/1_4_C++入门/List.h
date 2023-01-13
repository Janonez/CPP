#pragma once

namespace BList
{
	// –°B µœ÷
	struct Node
	{
		struct Node* next;
		struct Node* prev;
		int val;
	};
}