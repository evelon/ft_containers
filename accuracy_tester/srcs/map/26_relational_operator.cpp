#include "map_common.hpp"

int	main()
{
	mapIntStr	map1;
	compare_all(map1, map1);

	mapIntStr	map2;
	compare_all(map2, map2);

	map1.insert(PAIR(1, "1"));
	compare_all(map1, map2);

	map2.insert(PAIR(1, "1"));
	compare_all(map1, map2);

	map1.insert(PAIR(2, "2"));
	compare_all(map1, map2);

	map2.insert(PAIR(2, "23"));
	compare_all(map1, map2);

	map2[2] = "2";
	compare_all(map1, map2);

	map1.insert(PAIR(3, "3"));
	map2.insert(PAIR(4, "3"));
	compare_all(map1, map2);

	return (0);
}