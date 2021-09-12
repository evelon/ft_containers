#include "map_common.hpp"

int	main()
{
	stdListIntStr	lst1;
	lst1.push_back(PAIR(3, "three"));
	lst1.push_back(PAIR(1, "one"));
	lst1.push_back(PAIR(2, "two"));
	lst1.push_back(PAIR(2, "two"));
	lst1.push_back(PAIR(4, "four"));

	mapIntStr	map1(lst1.begin(), lst1.end());

	stdListIntStr	lst2;
	lst2.push_back(PAIR(4, "aaaaaaaaaaaaaaaa"));
	lst2.push_back(PAIR(3, "bbbbbbbbb"));
	lst2.push_back(PAIR(5, "ccccccccccccccccccccccccc"));
	lst2.push_back(PAIR(1, "d"));
	lst2.push_back(PAIR(2, "eeee"));

	mapIntStr	map2(lst2.begin(), lst2.end());

	mapIntStr::const_iterator	bit1 = map1.begin();
	mapIntStr::iterator	eit1 = --map1.end();
	mapIntStr::const_reverse_iterator	bit2 = ++map2.rbegin();
	mapIntStr::reverse_iterator	eit2 = map2.rend();

	std::cout << "before member-swap\n";
	print_map_it(bit1, eit1);
	print_map(map1);
	print_map_it(bit2, eit2);
	print_map(map2);

	map1.swap(map2);

	std::cout << "\nafter member swap\n";
	print_map_it(bit1, eit1);
	print_map(map1);
	print_map_it(bit2, eit2);
	print_map(map2);

	bit1 = map1.begin();
	eit1 = --map1.end();
	bit2 = ++map2.rbegin();
	eit2 = map2.rend();

	NS::swap(map2, map1);
	std::cout << "after non-member swap\n";

	print_map_it(bit1, eit1);
	print_map(map1);
	print_map_it(bit2, eit2);
	print_map(map2);

	std::cout << "clear and some swap";

	map1.clear();
	map2.swap(map1);
	print_map(map1);
	print_map(map2);
	map2.swap(map1);
	print_map(map1);
	print_map(map2);
	map2.clear();
	print_map(map1);
	print_map(map2);

	return (0);
}