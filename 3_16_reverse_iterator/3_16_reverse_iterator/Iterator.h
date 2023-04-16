#pragma once

namespace Janonez
{
	template<class Iterator, class Ref, class Ptr>
	struct ReverseIterator
	{
		typedef ReverseIterator<Iterator, Ref, Ptr> self;
		Iterator _cur;

		ReverseIterator(Iterator it)
			: _cur(it)
		{}

		Ref operator*()
		{
			Iterator tmp = _cur;
			--tmp;
			return *tmp;
		}

		self& operator++()
		{
			--_cur;
			return *this;
		}

		self& operator--()
		{
			++_cur;
			return *this;
		}

		bool operator!=(const self& s)
		{
			return _cur != s._cur;
		}
	};
}