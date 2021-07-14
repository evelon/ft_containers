#include "map_common.hpp"

int	main()
{
	stdListIntStr	lst;
	lst.push_back(PAIR(3, "three"));

	mapIntStr	mp(lst.begin(), lst.end());

	mapIntStr::reverse_iterator	rit = mp.rbegin();
	mapIntStr::iterator	it(rit); // Error here. Should not be constructed

	(void)it;

	return (0);
}