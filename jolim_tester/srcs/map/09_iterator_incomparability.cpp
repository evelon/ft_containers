#include "map_common.hpp"

int	main()
{
	std::list<NS::pair<char, int> >		lstci(1, PAIR('a', 1));
	std::list<NS::pair<int, float> >	lstif(1, PAIR(1, 1.1));
	mapCharInt_o	mapci(lstci.begin(), lstci.end());
	mapIntFloat_o	mapif;

	std::cout << (mapci.begin() == (*mapif.begin()).second) << '\n';

	return (0);
}