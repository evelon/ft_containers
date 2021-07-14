#include "map_common.hpp"

int	main()
{
	mapIntStr	map1;

	std::cout << "\n\nInsert test\n";

	NS::pair<mapIntStr::iterator, bool>	ret;
	mapIntStr::iterator					it;
	ret = map1.insert(PAIR(1, "one"));
	it = ret.first;
	std::cout << "inserted?: " << ret.second << '\n';
	std::cout << it->first << ": " << it->second << '\n';

	ret = map1.insert(PAIR(1, "first"));
	it = ret.first;
	std::cout << "inserted?: " << ret.second << '\n';
	std::cout << it->first << ": " << it->second << '\n';

	it = map1.insert(map1.begin(), PAIR(2, "two"));
	std::cout << it->first << ": " << it->second << '\n';

	it = map1.insert(map1.begin(), PAIR(2, "second"));
	std::cout << it->first << ": " << it->second << '\n';

	stdListIntStr	lst;
	lst.push_back(PAIR(3, "three"));
	lst.push_back(PAIR(1, "one"));
	lst.push_back(PAIR(2, "two"));
	lst.push_back(PAIR(2, "two"));
	lst.push_back(PAIR(4, "four"));

	map1.insert(lst.begin(), lst.end());

	print_map(map1);

	std::cout << "\n\nErase test\n";

	mapIntStr	map2(map1);

	it = map1.begin();
	map1.erase(it);
	print_map(map1);

	map1.erase(3);
	print_map(map1);

	map1.erase(map1.begin(), map1.end());
	print_map(map1);

	map2.erase(++map2.begin(), --map2.end());
	print_map(map2);

	return (0);
}