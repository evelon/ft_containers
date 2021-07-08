#include "map_common.hpp"

int	main()
{
	mapIntStr::iterator	isit;
	mapStrInt::iterator	siit;
	std::cout << (isit == siit) << '\n'; // Error here. Should not be comparable
	std::cout << (isit != siit) << '\n'; // Error here. Should not be comparable

	return (0);
}