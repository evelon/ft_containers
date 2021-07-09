#include "map_common.hpp"

int	main()
{
	stdListIntStr	lst;
	lst.push_back(PAIR(3, "three"));

	mapIntStr	mp(lst.begin(), lst.end());

	mapIntStr::const_iterator	cit = mp.begin();
	mapIntStr::iterator	it(cit); // Error here. Should not be constructed

	return (0);
}