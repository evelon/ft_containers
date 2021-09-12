#include "map_common.hpp"

int	main()
{
	mapStrInt	map1;
	mapStrInt::iterator	itup, itlow;
	mapStrInt::const_iterator	citup, citlow;

	map1["abc"] = 27;
	map1["2r3"] = 124;
	map1["abc"] = 1343;
	map1["a"] = 133;
	map1["b"] = 132;
	map1["c"] = 131;
	map1["d"] = 125;
	map1["ef"] = 13;

	itup = map1.upper_bound("c");
	itlow = map1.lower_bound("c");

	print_map_it(itlow, itup);

	citup = map1.upper_bound("ef");
	citlow = map1.lower_bound("abc");

	print_map_it(citlow, citup);

	NS::pair<mapStrInt::iterator, mapStrInt::iterator>				range1;
	NS::pair<mapStrInt::iterator, mapStrInt::iterator>				range2;
	NS::pair<mapStrInt::const_iterator, mapStrInt::const_iterator>	crange1;
	NS::pair<mapStrInt::const_iterator, mapStrInt::const_iterator>	crange2;

	range1 = map1.equal_range("2r3");
	range2.first = map1.lower_bound("2r3");
	range2.second = map1.upper_bound("2r3");

	std::cout << (range1 == range2) << std::endl;

	map1.clear();
	std::cout << (map1.lower_bound("a") == map1.upper_bound("a") << std::endl;
	map1["a"] = 1;
	std::cout << (map1.lower_bound("a") == map1.upper_bound("a") << std::endl;
}