#pragma once
#include <stack>
#include <iterator>
template <typename T, typename Container = std::deque<T>>
class stack_ex : public std::stack<T, Container>
{
private:
public:
	using stack_ex::stack::container_type;
	void swap_top() {
		auto last = c.end();
		auto start = c.begin();
		auto before_last = std::prev(last, 2);
		std::iter_swap(start, before_last);
	}
};

