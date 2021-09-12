#include "vector_common.hpp"

int	main()
{
	vecInt	vec(4);

	fill_int(vec, 3, 4);

	vecInt::iterator			it1 = vec.begin();
	vecInt::reverse_iterator	it2(++it1);

	std::cout << *it1 << '\n'; // 7
	std::cout << *it2 << '\n'; // 3

	std::cout << (++it2 == vec.rend()) << '\n'; // 1

	return (0);
}