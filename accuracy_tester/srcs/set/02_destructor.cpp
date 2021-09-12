#include "set_common.hpp"
#include <vector>

typedef std::vector<std::string> strvec;
typedef	std::list<std::vector<std::string> > svlist;
int	main()
{
	strvec::const_iterator	it;
	{
		strvec	sv(4, "asfd");
		svlist	svl(1, sv);
		NS::set<strvec>	vecset(svl.begin(), svl.end());
		it = vecset.begin()->begin();
	}
	std::cout << *it << std::endl;
	return (0);
}