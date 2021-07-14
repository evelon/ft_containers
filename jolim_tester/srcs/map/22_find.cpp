#include "map_common.hpp"

int	main()
{
	mapIntStr	mp;

	mp.insert(PAIR(238, "238"));
	mp.insert(PAIR(765, "765"));
	mp.insert(PAIR(432, "432"));
	mp.insert(PAIR(345, "345"));
	mp.insert(PAIR(837, "837"));
	mp.insert(PAIR(678, "678"));
	mp.insert(PAIR(909, "909"));
	mp.insert(PAIR(876, "876"));
	mp.insert(PAIR(532, "532"));

	print_map(mp);

	print_map_it(mp.find(345), mp.find(532));
	print_map_it(mp.find(238), mp.find(0));

	mapIntStr::iterator	it0 = mp.begin();
	mapIntStr::iterator	it1 = mp.find(345);
	mapIntStr::iterator	it2 = mp.find(837);
	mapIntStr::iterator	eit = mp.find(0);

	print_map_it(it0, it1);
	print_map_it(it1, it2);
	print_map_it(it2, eit);

	mapIntStr::const_iterator	cit0 = mp.begin();
	mapIntStr::const_iterator	cit1 = mp.find(345);
	mapIntStr::const_iterator	cit2 = mp.find(837);
	mapIntStr::const_iterator	ecit = mp.find(0);

	print_map_it(cit0, cit1);
	print_map_it(cit1, cit2);
	print_map_it(cit2, ecit);

	return (0);
}