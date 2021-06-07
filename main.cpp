#include "list.hpp"
#include "vector.hpp"

#include <iostream>
#include <list>

int	main()
{
	const ft::list<int>	lst;

	ft::list<int>::const_iterator	it = lst.begin();
	(void)it;
}