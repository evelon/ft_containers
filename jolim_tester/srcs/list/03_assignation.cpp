#include "list_common.hpp"
#include <vector>

int	main()
{
	std::vector<std::string>	vec;
	vec.push_back("a");
	vec.push_back("b");
	vec.push_back("c");
	vec.push_back("d");
	vec.push_back("e");
	vec.push_back("f");

	NS::list<std::string>	strlst1(vec.begin(), vec.end());
	NS::list<std::string>	strlst2(++vec.begin(), vec.end());
	NS::list<std::string>	strlst3;

	print_all(strlst1);
	print_all(strlst2);
	print_all(strlst3);

	strlst2 = strlst1;
	strlst1 = strlst3;
	strlst3 = strlst2;

	print_all(strlst1);
	print_all(strlst2);
	print_all(strlst3);
	return (0);
}