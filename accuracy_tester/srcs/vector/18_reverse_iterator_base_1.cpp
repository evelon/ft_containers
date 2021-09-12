#include "vector_common.hpp"

int	main()
{
	vecStr	vec(1, "4");

	vec.push_back("abababab");
	vec.push_back("123123123123123123123");
	vec.push_back("1234123412341234123412341234123412341234124");

	*(vec.rend().base()) = "changed";
	vecStr::const_reverse_iterator	crit = vec.rend();
	*(crit.base()) = "should not be changeable";

	return (0);
}
