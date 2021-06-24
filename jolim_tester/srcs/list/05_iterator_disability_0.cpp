#include "list_common.hpp"

int	main()
{
	listInt::iterator	intit;
	listStr::iterator	strit;
	std::cout << (intit == strit) << '\n'; // Error here. Should not be comparable
	std::cout << (intit != strit) << '\n'; // Error here. Should not be comparable

	return (0);
}