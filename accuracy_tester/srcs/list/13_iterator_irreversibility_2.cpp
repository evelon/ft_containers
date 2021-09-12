#include "list_common.hpp"

int	main()
{
	listInt	lst(3, 4);

	listInt::const_reverse_iterator	crit = lst.rbegin();
	listInt::reverse_iterator	rit(crit); // Error here. Should not be constructed

	(void)rit;

	return (0);
}