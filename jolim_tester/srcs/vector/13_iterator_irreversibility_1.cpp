#include "vector_common.hpp"

int	main()
{
	vecInt	vec(3, 4);

	vecInt::reverse_iterator	rit = vec.rbegin();
	vecInt::iterator	it(rit); // Error here. Should not be constructed

	return (0);
}