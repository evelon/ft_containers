#include "list.hpp"

#include <iostream>

void	size_check(ft::list<int> lst)
{
	int	i = 0;
	for (ft::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
		i++;
	std::cout << "size: " << lst.size() << "?=" << i << std::endl;
}

int	main()
{
	ft::list<int>	lst;

	for (int i = 0; i < 5; i++)
		lst.push_back(i);

	// size_check(lst);
	ft::list<int>::iterator bit = lst.begin();
	ft::list<int>::iterator eit = lst.end();

	lst.resize(7, 12);

	// size_check(lst);

	ft::list<int>	lst2(4, 35);


	// size_check(lst);

	for (ft::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << std::endl;
	std::cout << std::endl;
	// size_check(lst);
	lst.swap(lst2);
	ft::list<int>::iterator	it = lst.begin();
	it++;
	it++;
	it++;
	std::cout << *++lst2.begin() << std::endl;;
	lst.insert(it, ++lst2.begin(), --lst2.end());
	// size_check(lst);


	bit = lst.begin();
	eit = lst.end();
	for (; bit != eit; bit++)
		std::cout << *bit << std::endl;

	size_check(lst);

	return (0);
}
