#include "list.hpp"
#include "vector.hpp"

#include <iostream>
#include <list>

void	size_check(ft::list<int> lst)
{
	int	i = 0;
	for (ft::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
		i++;
	std::cout << "size: " << lst.size() << "?=" << i << std::endl;
}

void	print_lst(ft::list<int> lst)
{
	for (ft::list<int>::reverse_iterator rit = lst.rbegin(); rit != lst.rend(); ++rit)
		std::cout << *rit << std::endl;
	std::cout << std::endl;
}

bool	reverse(int a, int b)
{
	return (a > b);
}

int	main()
{
	ft::vector
}
