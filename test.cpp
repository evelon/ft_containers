#include <list>
#include <vector>
#include <iostream>
#include <memory>
#include <type_traits>
#include "list.hpp"
#include "vector.hpp"
#include <random>
#define NS ft

int	main()
{

	srand(time(NULL));

	NS::list<int>		lst;

	for (int i = 0; i < 200; i++)
		lst.push_back(rand()%2);
	NS::vector<bool>	boolvec(lst.begin(), lst.end());
	bool	b;

	NS::list<int>::iterator		lit = lst.end();
	boolvec.insert(--boolvec.end(), 1);
	NS::vector<bool>::iterator	vit = boolvec.end();
	while (vit != boolvec.begin())
		std::cout << (b = *(--vit));
	std::cout << std::endl;
	while (lit != lst.begin())
		std::cout << (*(--lit));
}