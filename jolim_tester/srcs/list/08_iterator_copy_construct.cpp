#include "list_common.hpp"

int	main()
{
	listInt	lst(4);

	fill_int(lst, 3, 4);

	listInt::iterator			it1 = lst.begin();
	listInt::reverse_iterator	it2(++it1);

	std::cout << *it1 << '\n'; // 7
	std::cout << *it2 << '\n'; // 3

	std::cout << (++it2 == lst.rend()) << '\n'; // 1
}