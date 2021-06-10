#include "list.hpp"
#include "vector.hpp"

#include <iostream>
#include <list>
#include <map>

int	main()
{
	std::map<char, int>	map1;
	std::map<char, int>	map2;

	map1.insert(std::pair<char, int>('a', 3));
	map1.insert(std::pair<char, int>('c', 4));
	map1.insert(std::pair<char, int>('d', 5));

	map2.insert(std::pair<char, int>('a', 3));
	map2.insert(std::pair<char, int>('b', 4));
	map2.insert(std::pair<char, int>('d', 5));
	map1['a'] = 4;

	for (std::map<char, int>::iterator it = map1.begin(); it != map1.end(); it++)
		std::cout << (*it).first << ": " << (*it).second << std::endl;

	std::cout << '\n';

	std::cout << (map1 == map2) << std::endl;
}