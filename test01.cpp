#include <list>


class	B
{
};

class	A
{
	B	b;
};

int	main()
{
	std::list<int>	lst;

	lst.erase(lst.begin());
}