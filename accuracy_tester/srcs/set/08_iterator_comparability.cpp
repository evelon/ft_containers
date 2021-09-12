#include "set_common.hpp"

int	main()
{
	std::list<int>	lst;
	lst.push_back(3);
	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(2);
	lst.push_back(4);

	setInt	set4(lst.begin(), lst.end());

	lst.push_back(6);
	lst.push_front(5);
	lst.push_back(7);

	setInt	set7(lst.begin(), lst.end());

	setInt::iterator		it1;
	setInt::const_iterator	it2;
	std::cout << (it1 == it2) << '\n'; // 1
	std::cout << (it1 != it2) << '\n'; // 0
	it1 = set4.begin();
	it2 = set4.begin();
	std::cout << (it1 == it2) << '\n'; // 1
	std::cout << (it1 != it2) << '\n'; // 0
	std::cout << (++it1 == ++it2) << '\n'; // 1
	std::cout << (it1 != ++it2) << '\n'; // 1

	it2 = set7.end();
	std::cout << (it1 == it2) << '\n'; // 0

	it1 = set4.end();
	std::cout << (it1 != it2) << '\n'; // 1

	setInt::reverse_iterator		rit1;
	setInt::const_reverse_iterator	rit2;

	std::cout << (rit1 == rit2) << '\n'; // 1
	std::cout << (rit1 != rit2) << '\n'; // 0
	rit1 = set4.rbegin();
	rit2 = set4.rbegin();
	std::cout << (rit1 == rit2) << '\n'; // 1
	std::cout << (rit1 != rit2) << '\n'; // 0
	std::cout << (++rit1 == ++rit2) << '\n'; // 1
	std::cout << (rit1 != ++rit2) << '\n'; // 1

	rit2 = set7.rend();
	std::cout << (rit1 == rit2) << '\n'; // 0

	rit1 = set4.rend();
	std::cout << (rit1 != rit2) << '\n'; // 1

	return (0);
}