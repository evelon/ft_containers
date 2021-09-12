#include "set_common.hpp"

int	main()
{
	std::list<int>	lst;

	lst.push_back(5);
	lst.push_back(2);
	lst.push_back(1);
	lst.push_back(3);
	lst.push_back(4);

	setInt	mp(lst.begin(), lst.end());

	std::cout << (mp.begin() == mp.rend().base()) << '\n';
	std::cout << (mp.end() == mp.rbegin().base()) << '\n';

	setInt::iterator	it = mp.begin();
	setInt::reverse_iterator	rit = mp.rend();

	std::cout << *it << '\n';
	std::cout << (it == rit.base()) << '\n';
	std::cout << (it != rit.base()) << '\n';
	// std::cout << (++it == (++rit).base()) << '\n'; // undefined behavior

	return (0);
}
