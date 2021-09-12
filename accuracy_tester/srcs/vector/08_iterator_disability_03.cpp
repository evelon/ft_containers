#include "vector_common.hpp"

int	main()
{
	vecInt::iterator			it1;
	vecInt::reverse_iterator	it2;

	std::cout << (it1 < it2) << '\n'; // Error here. Should not be comparable
	std::cout << (it1 > it2) << '\n'; // Error here. Should not be comparable
	std::cout << (it1 <= it2) << '\n'; // Error here. Should not be comparable
	std::cout << (it1 >= it2) << '\n'; // Error here. Should not be comparable

	return (0);
}