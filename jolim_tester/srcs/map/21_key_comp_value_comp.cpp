#include "map_common.hpp"

int	main()
{
	mapIntStr	mp;

	mp.insert(PAIR(243, "243"));
	mp.insert(PAIR(278, "278"));
	mp.insert(PAIR(182, "182"));
	mp.insert(PAIR(332, "332"));
	mp.insert(PAIR(837, "837"));
	mp.insert(PAIR(642, "642"));
	mp.insert(PAIR(641, "641"));

	mapIntStr::key_compare	kcomp = mp.key_comp();

	std::cout << kcomp(3, 4) << '\n';
	std::cout << kcomp(132, 2) << '\n';
	std::cout << kcomp(238902, 324) << '\n';
	std::cout << kcomp(3232, 1431) << '\n';

	mapIntStr::value_compare	vcomp = mp.value_comp();

	mapIntStr::iterator it = mp.begin();
	mapIntStr::reverse_iterator rit = mp.rbegin();
	while (it != mp.end())
	{
		std::cout << vcomp(*it, *rit) << '\n';
		++it;
		++rit;
	}

	return (0);
}