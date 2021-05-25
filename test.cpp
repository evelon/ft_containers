#include <list>
#include <vector>
#include <iostream>
#include <memory>
#include <type_traits>
#include "list.hpp"
#include "vector.hpp"

int	main()
{

	ft::vector<bool>	vec(true, 1);
	ft::vector<bool>::reverse_iterator(vec.begin());


	std::cout << (vec.begin() != vec.rbegin()) << std::endl;;
	std::cout << *vec.begin() << std::endl;

}