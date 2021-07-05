#include "vector_common.hpp"

int	main()
{
	vecStr	vec(1, "4");

	vec.push_back("abababab");
	vec.push_back("123123123123123123123");
	vec.push_back("1234123412341234123412341234123412341234124");

	std::cout << (vec.begin() == vec.rend().base()) << '\n';
	std::cout << (vec.end() == vec.rbegin().base()) << '\n';
	*(vec.rend().base()) = "changed";

	vecStr::iterator	it = vec.begin();
	vecStr::reverse_iterator	rit = vec.rend();

	std::cout << *it << '\n';
	std::cout << (it == rit.base()) << '\n';
	std::cout << (it != rit.base()) << '\n';
	std::cout << (++it == (++rit).base()) << '\n';

	return (0);
}
