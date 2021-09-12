#include "vector_common.hpp"

int	main()
{
	vecInt	vec(3, 4);

	vecInt::const_reverse_iterator	crit = vec.rbegin();
	vecInt::reverse_iterator	rit(crit); // Error here. Should not be constructed

	return (0);
}