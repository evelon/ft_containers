#include "vector_common.hpp"
#include <list>

int	main()
{
	std::list<std::string>	lst;
	lst.push_back("a");
	lst.push_back("b");
	lst.push_back("c");
	lst.push_back("d");
	lst.push_back("e");
	lst.push_back("f");

	vecStr	strvec1(lst.begin(), lst.end());
	vecStr	strvec2(++lst.begin(), lst.end());
	vecStr	strvec3;

	print_all(strvec1);
	print_all(strvec2);
	print_all(strvec3);

	strvec2 = strvec1;
	strvec1 = strvec3;
	strvec3 = strvec2;

	print_all(strvec1);
	print_all(strvec2);
	print_all(strvec3);
	return (0);
}