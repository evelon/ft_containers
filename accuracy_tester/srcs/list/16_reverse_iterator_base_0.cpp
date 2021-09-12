#include "list_common.hpp"

int	main()
{
	listStr	lst(1, "4");

	lst.push_back("abababab");
	lst.push_back("123123123123123123123");
	lst.push_back("1234123412341234123412341234123412341234124");

	std::cout << (lst.begin() == lst.rend().base()) << '\n';
	std::cout << (lst.end() == lst.rbegin().base()) << '\n';
	*(lst.rend().base()) = "changed";

	listStr::iterator	it = lst.begin();
	listStr::reverse_iterator	rit = lst.rend();

	std::cout << *it << '\n';
	std::cout << (it == rit.base()) << '\n';
	std::cout << (it != rit.base()) << '\n';
	std::cout << (++it == (++rit).base()) << '\n';

	return (0);
}
