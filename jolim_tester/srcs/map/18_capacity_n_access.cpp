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

	std::cout << mp.empty() << mp.size() << '\n';

	mapIntStr::size_type	size = mp.max_size();
	(void)size;

	std::cout << (mp[0] = "") << '\n';
	int	i;
	for (i = 0; i < 7; ++i)
		std::cout << mp[i] << '\n';

	std::cout << mp.empty() << mp.size() << '\n';

	i = 0;
	while (!mp.empty())
		mp.erase(i++);

	std::cout << mp.empty() << mp.size() << '\n';

	return (0);
}