#include "map_common.hpp"

int	main()
{
	stdListIntStr	lst;
	lst.push_back(PAIR(3, "three"));
	lst.push_back(PAIR(1, "one"));
	lst.push_back(PAIR(5, "five"));
	lst.push_back(PAIR(2, "two"));
	lst.push_back(PAIR(2, "two"));
	lst.push_back(PAIR(4, "four"));

	mapIntStr	map1(lst.begin(), lst.end());
	lst.push_front(PAIR(0, "zero"));
	mapIntStr	map2(lst.begin(), --lst.end());
	mapIntStr	map3;

	print_map(map1);
	print_map(map2);
	print_map(map3);

	map2 = map1;
	map1 = map3;
	map3 = map2;

	print_map(map1);
	print_map(map2);
	print_map(map3);

	return (0);
}