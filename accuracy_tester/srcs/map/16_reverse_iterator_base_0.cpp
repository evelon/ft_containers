#include "map_common.hpp"

int	main()
{
	stdListIntStr	lst;
	lst.push_back(PAIR(4, "aaaaaaaaaaaaaaaa"));
	lst.push_back(PAIR(3, "bbbbbbbbb"));
	lst.push_back(PAIR(5, "ccccccccccccccccccccccccc"));
	lst.push_back(PAIR(1, "d"));
	lst.push_back(PAIR(2, "eeee"));

	mapIntStr	mp(lst.begin(), lst.end());

	std::cout << (mp.begin() == mp.rend().base()) << '\n';
	std::cout << (mp.end() == mp.rbegin().base()) << '\n';
	(*mp.rend().base()).second = "changed";

	mapIntStr::iterator	it = mp.begin();
	mapIntStr::reverse_iterator	rit = mp.rend();

	std::cout << (*it).second << '\n';
	std::cout << (it == rit.base()) << '\n';
	std::cout << (it != rit.base()) << '\n';
	// std::cout << (++it == (++rit).base()) << '\n'; // undefined behavior

	return (0);
}
