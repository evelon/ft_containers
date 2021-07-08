#include "map_common.hpp"

int	main()
{
	stdListIntStr	lst;
	lst.push_back(PAIR(3, "three"));
	lst.push_back(PAIR(1, "one"));
	lst.push_back(PAIR(2, "two"));
	lst.push_back(PAIR(2, "two"));
	lst.push_back(PAIR(4, "four"));

	mapIntStr	map4(lst.begin(), lst.end());
	lst.push_back(PAIR(5, "five"));
	lst.push_front(PAIR(6, "six"));
	lst.push_back(PAIR(7, "seven"));
	mapIntStr	map7(lst.begin(), lst.end());

	mapIntStr::iterator		it1;
	mapIntStr::const_iterator	it2;
	std::cout << (it1 == it2) << '\n'; // 1
	std::cout << (it1 != it2) << '\n'; // 0
	it1 = map4.begin();
	it2 = map4.begin();
	std::cout << (it1 == it2) << '\n'; // 1
	std::cout << (it1 != it2) << '\n'; // 0
	std::cout << (++it1 == ++it2) << '\n'; // 1
	std::cout << (it1 != ++it2) << '\n'; // 1

	it2 = map7.end();
	std::cout << (it1 == it2) << '\n'; // 0

	it1 = map4.end();
	std::cout << (it1 != it2) << '\n'; // 1

	mapIntStr::reverse_iterator		rit1;
	mapIntStr::const_reverse_iterator	rit2;

	std::cout << (rit1 == rit2) << '\n'; // 1
	std::cout << (rit1 != rit2) << '\n'; // 0
	rit1 = map4.rbegin();
	rit2 = map4.rbegin();
	std::cout << (rit1 == rit2) << '\n'; // 1
	std::cout << (rit1 != rit2) << '\n'; // 0
	std::cout << (++rit1 == ++rit2) << '\n'; // 1
	std::cout << (rit1 != ++rit2) << '\n'; // 1

	rit2 = map7.rend();
	std::cout << (rit1 == rit2) << '\n'; // 0

	rit1 = map4.rend();
	std::cout << (rit1 != rit2) << '\n'; // 1

	return (0);
}