#include "map_common.hpp"

int	main()
{
	stdListIntStr	lst;
	lst.push_back(PAIR(4, "aaaaaaaaaaaaaaaa"));
	lst.push_back(PAIR(3, "bbbbbbbbb"));
	lst.push_back(PAIR(5, "ccccccccccccccccccccccccc"));
	lst.push_back(PAIR(1, "d"));
	lst.push_back(PAIR(2, "eeee"));

	mapIntStr	mp(lst.begin(), lst.end());

	std::cout << mp.begin()->second.c_str() << '\n';
	std::cout << (++(mp.begin()))->second.c_str() << '\n';

	mapIntStr::const_iterator	cit = --mp.end();
	mapIntStr::const_reverse_iterator	crit = mp.rbegin();

	std::cout << (cit->second.capacity() == (crit++)->second.capacity()) << '\n';
	std::cout << ((*(--cit)).second.capacity() == (*crit).second.capacity()) << '\n';
	std::cout << (cit->second.get_allocator() == (*crit).second.get_allocator()) << '\n';
	std::cout << (*cit).second << (*crit).second << '\n';

	return (0);
}
