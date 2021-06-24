#include "list_common.hpp"

int	main()
{
	listInt	lst(3, 4);

	listInt::const_iterator	cit = lst.begin();
	listInt::iterator	it(cit); // Error here. Should not be constructed

	return (0);
}