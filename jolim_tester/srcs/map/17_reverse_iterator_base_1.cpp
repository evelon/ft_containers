#include "list_common.hpp"

int	main()
{
	listStr	lst(1, "4");

	lst.push_back("abababab");
	lst.push_back("123123123123123123123");
	lst.push_back("1234123412341234123412341234123412341234124");

	*(lst.rend().base()) = "changed";
	listStr::const_reverse_iterator	crit = lst.rend();
	*(crit.base()) = "should not be changeable";

	return (0);
}
