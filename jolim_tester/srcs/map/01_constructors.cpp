#include "map_common.hpp"
#include <memory>
#include <list>

int	main()
{
	std::list<NS::pair<char, int> >	std_list(45);

	mapCharInt	a1;
	mapCharInt	a2((mapCharInt::key_compare()), (std::allocator<NS::pair<char, int> >()));
	mapCharInt	a3(std_list.begin(), std_list.end());
	mapCharInt	a4(++(++std_list.begin()), --(std_list.end()), mapCharInt::key_compare(), std::allocator<NS::pair<char, int> >());
	mapCharInt	b1(a1);
	mapCharInt	b2(a2);
	mapCharInt	b3(a3);
	mapCharInt	b4(a4);
	mapCharInt	c4(a4);

	return (0);
}