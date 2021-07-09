#include "map_common.hpp"

int	main()
{
	stdListIntStr	lst;
	lst.push_back(PAIR(3, "three"));

	mapIntStr	mp(lst.begin(), lst.end());

	mapIntStr::const_reverse_iterator	crit = mp.rbegin();
	mapIntStr::reverse_iterator	rit(crit); // Error here. Should not be constructed

	return (0);
}