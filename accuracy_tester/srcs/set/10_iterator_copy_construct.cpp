#include "set_common.hpp"

int	main()
{
	std::list<int>	lst;
	lst.push_back(3);
	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(2);
	lst.push_back(4);

	setInt	st(lst.begin(), lst.end());

	setInt::iterator			it1 = st.begin();
	setInt::reverse_iterator	it2(++it1);

	std::cout << *it1 << '\n'; // 1
	std::cout << *it2 << '\n'; // 1

	std::cout << (++it2 == st.rend()) << '\n'; // 1

	return (0);
}