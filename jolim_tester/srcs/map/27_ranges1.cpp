#include "map_common.hpp"

typedef	NS::pair<mapCharInt::iterator, mapCharInt::iterator>	iter_pair;
typedef	NS::pair<mapCharInt::const_iterator, mapCharInt::const_iterator>	citer_pair;

int	main()
{
	mapCharInt	mp;

	mp.insert(PAIR('a', 1));
	mp.insert(PAIR('b', 10));
	mp.insert(PAIR('c', 100));
	mp.insert(PAIR('d', 1000));
	mp.insert(PAIR('e', 10000));

	const mapCharInt	cmp(mp);

	iter_pair	it_pair;
	citer_pair	cit_pair;

	it_pair = mp.equal_range('a');
	print_map_it(it_pair.first, ++it_pair.second);
	cit_pair = mp.equal_range('b');
	print_map_it(cit_pair.first, ++cit_pair.second);

	cit_pair = cmp.equal_range('c');
	print_map_it(cit_pair.first, ++cit_pair.second);

	return (0);
}