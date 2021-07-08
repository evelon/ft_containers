#include "map_common.hpp"

int	main()
{
	stdListIntStr	lst;
	lst.push_back(PAIR(3, "three"));
	lst.push_back(PAIR(1, "one"));
	lst.push_back(PAIR(2, "two"));
	lst.push_back(PAIR(2, "two"));
	lst.push_back(PAIR(4, "four"));

	mapIntStr	mp(lst.begin(), lst.end());

	mapIntStr::iterator			it1 = mp.begin();
	mapIntStr::reverse_iterator	it2(++it1);

	std::cout << (*it1).second << '\n'; // two
	std::cout << (*it2).second << '\n'; // one

	std::cout << (++it2 == mp.rend()) << '\n'; // 1

	return (0);
}