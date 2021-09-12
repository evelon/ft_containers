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

	mapIntStr::iterator	it = mp.begin();

	(*it).second = "first";

	mapIntStr::const_iterator	cit = mp.begin();

	(*cit).second = "zero"; // Error here.
}