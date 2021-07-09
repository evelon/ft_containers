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

	(*mp.rend().base()).second = "changed";
	mapIntStr::const_reverse_iterator	crit = mp.rend();
	(*crit.base()).second = "should not be changeable";

	return (0);
}
