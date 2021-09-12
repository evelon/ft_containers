#include "map_common.hpp"

int	main()
{
	mapIntSize	map1;
	mapIntSize	map2;

	for (size_t i = 0; i < 12; ++i)
	{
		map1[i] = i * 2;
	}

	for (size_t i = 0; i < 14; ++i)
	{
		map2[i] = i * 3;
	}

	mapIntSize::const_iterator	bit1 = map1.begin();
	mapIntSize::iterator	eit1 = --map1.end();
	mapIntSize::const_reverse_iterator	bit2 = ++map2.rbegin();
	mapIntSize::reverse_iterator	eit2 = map2.rend();

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

	std::cout << "clear and some swap\n";

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