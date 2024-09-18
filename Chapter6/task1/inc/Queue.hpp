#pragma once
# include <queue>

template <typename T>
class Queue : public std::queue<T>
{
public:
	using iterator = typename std::queue<T>::container_type::iterator;
	using const_iterator = typename std::queue<T>::container_type::const_iterator;

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
	const_iterator begin() const { return this->c.begin(); }
	const_iterator end() const { return this->c.end(); }
};
