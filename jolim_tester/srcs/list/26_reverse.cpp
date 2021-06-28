#include "list_common.hpp"

int	main()
{
	listStr	lst;

	print_all(lst);
	lst.reverse();
	print_all(lst);
	lst.push_back("a");
	lst.reverse();
	print_all(lst);
	lst.push_front("b");
	lst.reverse();
	print_all(lst);
	lst.push_front("c");
	lst.reverse();
	print_all(lst);
	lst.push_back("d");
	lst.reverse();
	print_all(lst);
	return (0);
}