#include "vector_common.hpp"

int	main()
{
	vecInt::iterator	intit;
	vecStr::iterator	strit;
	std::cout << (intit == strit) << '\n'; // Error here. Should not be comparable
	std::cout << (intit != strit) << '\n'; // Error here. Should not be comparable

	return (0);
}