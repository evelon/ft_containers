#include "map_common.hpp"
#include <vector>
#define lmap NS::map<Leaky, Leaky>

int	main()
{
	{
		lmap	a;

		std::vector<NS::pair<Leaky, Leaky> >	vec;
		vec.push_back(NS::make_pair(Leaky("1"), Leaky("a")));
		vec.push_back(NS::make_pair(Leaky("2"), Leaky("b")));
		vec.push_back(NS::make_pair(Leaky("3"), Leaky("c")));

		lmap	b(vec.begin(), vec.end());
		lmap	c(b);

		b[Leaky("4")] = Leaky("d");

		NS::pair<lmap::iterator, bool>	p = b.insert(NS::make_pair(Leaky("5"), Leaky("e")));
		std::cout << p.second;
		b.insert(p.first, NS::make_pair(Leaky("6"), Leaky("f")));

		vec.push_back(NS::make_pair(Leaky("7"), Leaky("g")));
		vec.push_back(NS::make_pair(Leaky("8"), Leaky("h")));
		vec.push_back(NS::make_pair(Leaky("9"), Leaky("i")));
		b.insert(vec.begin(), vec.end());

		b.erase(++(++(b.begin())));
		b.erase(Leaky("9"));
		c.erase(c.begin(), c.end());
		lmap	d(vec.begin(), vec.end());
		b.swap(d);
		b.clear();
	}
	system("leaks a.out | grep bytes')'");
}