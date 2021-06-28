#include "vector_common.hpp"
#include <vector>

int	main()
{
	std::vector<A>	std_list(45);

	vecA	a1;
	vecA	a2((std::allocator<A>()));
	vecA	a3(3);
	vecA	a4(4, A());
	vecA	a5(5, A(), std::allocator<A>());
	vecA	a6(std_list.begin(), std_list.end());
	vecA	a7(++(++std_list.begin()), --(std_list.end()), std::allocator<A>());
	vecA	b1(a1);
	vecA	b2(a2);
	vecA	b3(a3);
	vecA	b4(a4);
	vecA	b5(a5);
	vecA	b6(a6);
	vecA	b7(a7);
	vecA	c7(b7);
	return (0);
}