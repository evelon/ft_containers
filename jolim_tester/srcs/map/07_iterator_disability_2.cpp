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

	mapIntStr::const_iterator	cit = mp.begin();

	*cit = NS::make_pair<const wrapper<int>, std::string>(0, std::string("zero")); // Error here.
}