#include "list_common.hpp"

int	main()
{
	listStr	lst1;
	compare_all(lst1, lst1);

	listStr	lst2;
	compare_all(lst1, lst2);

	lst1.push_front("bool");
	compare_all(lst1, lst2);

	lst2.push_front("bool");
	compare_all(lst1, lst2);

	lst1.push_back("abc");
	compare_all(lst1, lst2);

	lst2.push_back("ab");
	compare_all(lst1, lst2);

	return (0);
}