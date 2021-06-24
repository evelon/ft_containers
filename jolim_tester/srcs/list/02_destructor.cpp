#include "list_common.hpp"
#include <vector>

typedef std::vector<std::string> strvec;

int	main()
{
	strvec::iterator	it;
	{
		strvec	sv(4, "asfd");
		NS::list<strvec>	lst(4, sv);
		it = lst.begin()->begin();
	}
	std::cout << *it << std::endl;
	return (0);
}