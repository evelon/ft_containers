#include "list_common.hpp"
#include <memory>
#include <list>

int	main()
{
	std::list<A>	std_list(45);

	listA	a1;
	listA	a2((std::allocator<A>()));
	listA	a3(3);
	listA	a4(4, A());
	listA	a5(5, A(), std::allocator<A>());
	listA	a6(std_list.begin(), std_list.end());
	listA	a7(++(++std_list.begin()), --(std_list.end()), std::allocator<A>());
	listA	b1(a1);
	listA	b2(a2);
	listA	b3(a3);
	listA	b4(a4);
	listA	b5(a5);
	listA	b6(a6);
	listA	b7(a7);
	listA	c7(b7);
}