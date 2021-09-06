#include "map_common.hpp"

int	main()
{
	mapIntStr	mp;

	mp.insert(PAIR(1, "1"));
	mp.insert(PAIR(1, "2"));
	mp.insert(PAIR(1, "3"));
	mp.insert(PAIR(2, "2"));
	mp.insert(PAIR(2, "1"));
	mp.insert(PAIR(3, "3"));

	print_map(mp);

	std::cout << mp.count(0) << '\n';
	std::cout << mp.count(1) << '\n';
	std::cout << mp.count(2) << '\n';
	std::cout << mp.count(3) << '\n';
	std::cout << mp.count(4) << '\n';

	return (0);
}