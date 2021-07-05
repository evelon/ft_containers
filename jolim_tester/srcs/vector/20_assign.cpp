#include "vector_common.hpp"
#include <list>

int	main()
{
	vecInt	vec1(8);

	fill_int(vec1, 3, 3);


	vecInt	vec2(4, 12);
	vec2.assign(vec1.begin(), vec1.end());

	print_all(vec2);

	vec1.assign(3, 3);

	print_all(vec1);

	std::list<int>	lst;
	fill_int(lst, 4, 8);
	vec2.assign(lst.begin(), lst.end());

	print_all(vec2);

	vecSize::size_type	sz = 8;
	vecSize	lstS(sz, sz + 8);
	lstS.assign(sz, sz + 8);
	return (0);
}