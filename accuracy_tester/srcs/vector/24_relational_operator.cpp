#include "vector_common.hpp"

int	main()
{
	vecStr	vec1;
	compare_all(vec1, vec1);

	vecStr	vec2;
	compare_all(vec1, vec2);

	vec1.push_back("bool");
	compare_all(vec1, vec2);

	vec2.push_back("bool");
	compare_all(vec1, vec2);

	vec1.push_back("abc");
	compare_all(vec1, vec2);

	vec2.push_back("ab");
	compare_all(vec1, vec2);

	return (0);
}