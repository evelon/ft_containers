#include "vector_common.hpp"

int	main()
{
	vecInt_o		vec1(3, 4);
	vecFloat_o	vec2(3, 4.4);

	std::cout << (vec1.begin() == *vec2.begin()) << '\n';

	return (0);
}