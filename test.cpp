#include <list>
#include <vector>
#include <iostream>
#include <memory>
#include <type_traits>
#include "list.hpp"
// #include "vector.hpp"

int	main()
{
	ft::list<int>	lst(1, 4);
	ft::list<int>::reverse_iterator rev = lst.rbegin();
	ft::list<int>::reverse_iterator rev2(rev);
	std::cout << *rev2 << std::endl;
}