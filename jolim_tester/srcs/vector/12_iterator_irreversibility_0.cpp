#include "vector_common.hpp"

int	main()
{
	vecInt	vec(3, 4);

	vecInt::const_iterator	cit = vec.begin();
	vecInt::iterator	it(cit); // Error here. Should not be constructed

	return (0);
}
