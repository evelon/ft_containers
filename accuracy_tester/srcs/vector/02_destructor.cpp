#include "vector_common.hpp"
#include <list>

typedef std::list<std::string> strlist;

int	main()
{
	strlist::iterator	it;
	strlist	sv(4, "asfd");
	NS::vector<strlist>	vec(4, sv);
	it = vec.begin()->begin();
	std::cout << *it << std::endl;
	return (0);
}
