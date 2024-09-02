#pragma once
# include <iostream>
# include <list>

template <typename T>
class CircularList : public std::list<T>
{
public:
	void	rotate(void)
	{
		if (!this->empty())
			this->splice(this->end(), *this, this->begin());
	}
};
