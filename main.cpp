#include "list.hpp"

#include <iostream>

int	main()
{
	ft::list<int>	lst;

	for (int i = 0; i < 5; i++)
		lst.push_back(i);

	ft::list<int>::iterator bit = lst.begin();
	ft::list<int>::iterator eit = lst.end();

	lst.resize(7, 12);


	ft::list<int>	lst2(4, 35);

	ft::list<int>::iterator bit2 = lst2.begin();
	ft::list<int>::iterator eit2 = lst2.end();

	lst.swap(lst2);

	lst.clear();
	bit = lst.begin();
	eit = lst.end();
	for (; bit != eit; bit++)
		std::cout << *bit << std::endl;
	std::cout << lst.size() << std::endl;
	return (0);
}
