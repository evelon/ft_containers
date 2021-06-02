#include <list>
#include <vector>
#include <iostream>
#include <memory>
#include <type_traits>
#include "list.hpp"
#include "vector.hpp"
#include <random>

int	main()
{
	ft::list<int>		lst;

	srand(time(NULL));
	lst.push_back(rand() % 2);
	lst.push_back(rand() % 2);
	lst.push_back(rand() % 2);
	lst.push_back(rand() % 2);
	lst.push_back(rand() % 2);
	lst.push_back(rand() % 2);
	ft::vector<bool>	vec;

	vec.assign(lst.begin(), lst.end());

	for (ft::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << std::endl;
	std::cout << std::endl;
	// vec.resize(12, true);
	for (ft::vector<bool>::iterator it = vec.begin(); it < vec.end(); it++)
		std::cout << *it << std::endl;

}