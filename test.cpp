#include <list>
#include <vector>
#include <iostream>
#include <memory>
#include <type_traits>
// #include "list.hpp"
#include "vector.hpp"
#include <random>

int	main()
{
	std::vector<bool>	boolvec;

	ft::vector<int>		lst;

	lst.push_back(rand() % 2);
	lst.push_back(rand() % 2);
	lst.push_back(rand() % 2);
	lst.push_back(rand() % 2);
	lst.push_back(rand() % 2);
	lst.push_back(rand() % 2);
	ft::vector<int>	vec(lst.begin(), lst.end());

	for (ft::vector<int>::iterator it = vec.begin(); it < vec.end(); it++)
		std::cout << *it << std::endl;

}