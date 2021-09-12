#include "map_common.hpp"

int	main()
{
	mapCharInt	mp;

	mp.insert(PAIR('a', 1));
	mp.insert(PAIR('b', 10));
	mp.insert(PAIR('c', 100));
	mp.insert(PAIR('d', 1000));
	mp.insert(PAIR('e', 10000));

	mapCharInt::iterator	itlow, itup;
	mapCharInt::const_iterator	citlow, citup;

	itlow = mp.lower_bound('b');
	itup = mp.upper_bound('b');
	print_map_it(itlow, itup);

	itlow = mp.lower_bound('a');
	itup = mp.upper_bound('a');
	print_map_it(itlow, itup);

	itlow = mp.lower_bound('e');
	itup = mp.upper_bound('e');
	print_map_it(itlow, itup);

	itlow = mp.lower_bound('a');
	itup = mp.upper_bound('e');
	print_map_it(itlow, itup);

	itlow = mp.lower_bound('b');
	itup = mp.upper_bound('d');
	print_map_it(itlow, itup);

	itlow = mp.lower_bound('0');
	itup = mp.upper_bound('z');
	print_map_it(itlow, itup);


	citlow = mp.lower_bound('b');
	citup = mp.upper_bound('b');
	print_map_it(citlow, citup);

	citlow = mp.lower_bound('a');
	citup = mp.upper_bound('a');
	print_map_it(citlow, citup);

	citlow = mp.lower_bound('e');
	citup = mp.upper_bound('e');
	print_map_it(citlow, citup);

	citlow = mp.lower_bound('a');
	citup = mp.upper_bound('e');
	print_map_it(citlow, citup);

	citlow = mp.lower_bound('b');
	citup = mp.upper_bound('d');
	print_map_it(citlow, citup);

	citlow = mp.lower_bound('0');
	citup = mp.upper_bound('z');
	print_map_it(citlow, citup);

	return (0);
}