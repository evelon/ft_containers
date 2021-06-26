#include "list_common.hpp"
#include <vector>

int	main()
{
	listInt	lst1(8);

	fill_int(lst1, 3, 3);


	listInt	lst2(4, 12);
	lst2.assign(lst1.begin(), lst1.end());

	print_all(lst2);

	lst1.assign(3, 3);

	print_all(lst1);

	std::vector<int>	vec;
	fill_int(vec, 4, 8);
	lst2.assign(vec.begin(), vec.end());

	print_all(lst2);

	listSize::size_type	sz = 8;
	listSize	lstS(sz, sz + 8);
	lstS.assign(sz, sz + 8);
	return (0);
}