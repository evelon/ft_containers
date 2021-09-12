#include "map_common.hpp"

int	main()
{
	mapCharInt	map1;

	map1['a'] = 'a';
	map1['b'] = 'b';
	map1['c'] = 'c';
	map1['d'] = 'd';
	map1['e'] = 'e';
	map1['f'] = 'f';
	map1['g'] = 'g';
	map1['h'] = 'h';
	map1['i'] = 'i';
	map1['j'] = 'j';
	map1['k'] = 'k';
	map1['l'] = 'l';
	map1['m'] = 'm';
	map1['n'] = 'n';

	mapCharInt	map2;

	map2['a'] = 'a';
	map2['b'] = 'b';
	map2['c'] = 'c';
	map2['d'] = 'd';
	map2['e'] = 'e';
	map2['f'] = 'f';
	map2['g'] = 'g';
	map2['h'] = 'h';
	map2['i'] = 'i';
	map2['j'] = 'j';
	map2['k'] = 'k';
	map2['l'] = 'l';
	map2['m'] = 'm';
	map2['n'] = 'n';

	mapCharInt::iterator	it;
	it = map1.find('a');
	if (it != map1.end())
		std::cout << it->first << it->second;
	it = map2.find('e');
	if (it != map2.end())
		std::cout << it->first << it->second;
	it = map1.find('z');
	if (it != map1.end())
		std::cout << it->first << it->second;
	std::cout << map1.value_comp()(*map1.find('c'), *map2.find('c')) << std::endl;

	std::cout << map1.count('a') << map2.count('a') << map1.count('b') << map1.count('e') << map1.count('z') << map1.count('t') << std::endl;

	return (0);
}