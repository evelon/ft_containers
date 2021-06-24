#include "list_common.hpp"

int	main()
{
	listInt		lst1(3, 4);
	listFloat	lst2(3, 4.4);

	std::cout << (lst1.begin() == *lst2.begin()) << '\n';

	return (0);
}