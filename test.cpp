#include <list>
#include <vector>
#include <iostream>
#include <memory>
#include <type_traits>
// #include "list.hpp"
#include "vector.hpp"

int	main()
{

	ft::vector<int>	vec(4, 1);
	vec.clear();

	std::cout << (vec.begin() > vec.rbegin()) << std::endl;;
	std::cout << *vec.begin() << std::endl;

}