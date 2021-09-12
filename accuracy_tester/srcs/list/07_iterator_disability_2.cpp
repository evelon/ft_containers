#include "list_common.hpp"

int	main()
{
	listInt	lst(10, 10);

	listInt::const_iterator	cit = lst.begin();

	*cit = 13; // Error here.
}