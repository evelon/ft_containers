#include "list_common.hpp"

int	main()
{
	listInt	lst1(3, 4);
	listInt	lst2(4, 5);

	listInt::iterator		it1;
	listInt::const_iterator	it2;
	std::cout << (it1 == it2) << '\n'; // 1
	std::cout << (it1 != it2) << '\n'; // 0
	it1 = lst1.begin();
	it2 = lst1.begin();
	std::cout << (it1 == it2) << '\n'; // 1
	std::cout << (it1 != it2) << '\n'; // 0
	std::cout << (++it1 == ++it2) << '\n'; // 1
	std::cout << (it1 != ++it2) << '\n'; // 1

	it2 = lst2.end();
	std::cout << (it1 == it2) << '\n'; // 0

	it1 = lst1.end();
	std::cout << (it1 != it2) << '\n'; // 1

	listInt::reverse_iterator		rit1;
	listInt::const_reverse_iterator	rit2;

	std::cout << (rit1 == rit2) << '\n'; // 1
	std::cout << (rit1 != rit2) << '\n'; // 0
	rit1 = lst1.rbegin();
	rit2 = lst1.rbegin();
	std::cout << (rit1 == rit2) << '\n'; // 1
	std::cout << (rit1 != rit2) << '\n'; // 0
	std::cout << (++rit1 == ++rit2) << '\n'; // 1
	std::cout << (rit1 != ++rit2) << '\n'; // 1

	rit2 = lst2.rend();
	std::cout << (rit1 == rit2) << '\n'; // 0

	rit1 = lst1.rend();
	std::cout << (rit1 != rit2) << '\n'; // 1

	return (0);
}