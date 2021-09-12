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


	mapIntStr::iterator	it_7b = map7.begin();
	mapIntStr::iterator	it_7e = map7.end();
	print_map_it(it_7b, it_7e);

	mapIntStr::const_iterator	cit_7b = map7.begin();
	mapIntStr::const_iterator	cit_7e = map7.end();
	print_map_it(cit_7b, cit_7e);

	mapIntStr::reverse_iterator	rit_4b = map4.rbegin();
	mapIntStr::reverse_iterator	rit_4e = map4.rend();
	print_map_it(rit_4b, rit_4e);

	mapIntStr::const_reverse_iterator	crit_4b = map4.rbegin();
	mapIntStr::const_reverse_iterator	crit_4e = map4.rend();
	print_map_it(crit_4b, crit_4e);

	print_map_it(it_7b, cit_7e); // iterator and const_iterator should be comparable
	print_map_it(rit_4b, crit_4e); // this also applys to reverse iterators
	print_map_it(cit_7b, it_7e);
	print_map_it(crit_4b, rit_4e);

	return (0);
}