#include "vector_common.hpp"

int	main()
{
	vecInt	vec(10, 10);

	vecInt::const_iterator	cit = vec.begin();

	*cit = 13; // Error here.
}