#include "map_common.hpp"
#include <vector>

typedef std::vector<std::string> strvec;
typedef std::vector<NS::pair<int, strvec> > pairvec;

int	main()
{
	strvec::iterator	it;
	{
		strvec	sv(4, "asfd");
		pairvec	pv(4, NS::make_pair(3, sv));
		NS::map<int, strvec>	vecmap(pv.begin(), pv.end());
		it = vecmap.begin()->second.begin();
	}
	std::cout << *it << std::endl;
	return (0);
}