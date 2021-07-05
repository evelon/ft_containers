#include "vector_common.hpp"

int	main()
{
	vecInt	lst1(3, 4);
	vecInt	lst2(4, 5);

	vecInt::iterator		it1;
	vecInt::const_iterator	it2;
	// std::cout << (it1 == it2) << '\n'; // 1
	// std::cout << (it1 != it2) << '\n'; // 0
	// std::cout << (it1 < it2) << '\n'; // 0
	// std::cout << (it1 <= it2) << '\n'; // 1
	// std::cout << (it1 > it2) << '\n'; // 0
	// std::cout << (it1 >= it2) << '\n'; // 1

	it1 = lst1.begin();
	it2 = lst1.begin();
	std::cout << (it1 == it2) << '\n'; // 1
	std::cout << (it1 != it2) << '\n'; // 0
	std::cout << (it1 < it2) << '\n'; // 0
	std::cout << (it1 <= it2) << '\n'; // 1
	std::cout << (it1 > it2) << '\n'; // 0
	std::cout << (it1 >= it2) << '\n'; // 1

	std::cout << (++it1 == ++it2) << '\n'; // 1
	std::cout << (it1 != ++it2) << '\n'; // 1
	std::cout << (it1 < it2) << '\n'; // 1
	std::cout << (it1 <= it2) << '\n'; // 1
	std::cout << (it1 > it2) << '\n'; // 0
	std::cout << (it1 >= it2) << '\n'; // 0

	it2 = lst2.end();
	std::cout << (it1 == it2) << '\n'; // 0

	it1 = lst1.end();
	std::cout << (it1 != it2) << '\n'; // 1

	vecInt::reverse_iterator		rit1;
	vecInt::const_reverse_iterator	rit2;

	// std::cout << (rit1 == rit2) << '\n'; // 1
	// std::cout << (rit1 != rit2) << '\n'; // 0
	// std::cout << (rit1 < rit2) << '\n'; // 0
	// std::cout << (rit1 <= rit2) << '\n'; // 1
	// std::cout << (rit1 > rit2) << '\n'; // 0
	// std::cout << (rit1 >= rit2) << '\n'; // 1

	rit1 = lst1.rbegin();
	rit2 = lst1.rbegin();
	std::cout << (rit1 == rit2) << '\n'; // 1
	std::cout << (rit1 != rit2) << '\n'; // 0
	std::cout << (rit1 < rit2) << '\n'; // 0
	std::cout << (rit1 <= rit2) << '\n'; // 1
	std::cout << (rit1 > rit2) << '\n'; // 0
	std::cout << (rit1 >= rit2) << '\n'; // 1

	std::cout << (++rit1 == ++rit2) << '\n'; // 1
	std::cout << (rit1 != ++rit2) << '\n'; // 1
	std::cout << (rit1 < rit2) << '\n'; // 1
	std::cout << (rit1 <= rit2) << '\n'; // 1
	std::cout << (rit1 > rit2) << '\n'; // 0
	std::cout << (rit1 >= rit2) << '\n'; // 0

	rit2 = lst2.rend();
	std::cout << (rit1 == rit2) << '\n'; // 0

	rit1 = lst1.rend();
	std::cout << (rit1 != rit2) << '\n'; // 1

	return (0);
}