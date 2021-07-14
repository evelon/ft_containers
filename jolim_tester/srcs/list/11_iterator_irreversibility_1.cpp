#include "list_common.hpp"

int	main()
{
	listInt	lst(3, 4);

	listInt::reverse_iterator	rit = lst.rbegin();
	listInt::iterator	it(rit); // Error here. Should not be constructed

	(void)it;

	return (0);
}