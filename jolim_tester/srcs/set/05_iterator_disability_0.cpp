#include "set_common.hpp"

int	main()
{
	setInt::iterator	siit;
	setFloat::iterator	sfit;

	std::cout << (sfit == siit) << '\n'; // Error here. Should not be comparable
	std::cout << (sfit != siit) << '\n'; // Error here. Should not be comparable

	return (0);
}