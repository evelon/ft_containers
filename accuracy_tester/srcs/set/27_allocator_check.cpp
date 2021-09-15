#include "set_common.hpp"
#include <vector>
#define lset NS::set<Leaky>

int	main()
{
	{
		lset	a;

		std::vector<Leaky>	vec;
		vec.push_back(Leaky("1"));
		vec.push_back(Leaky("2"));
		vec.push_back(Leaky("3"));

		lset	b(vec.begin(), vec.end());
		lset	c(b);

		NS::pair<lset::iterator, bool>	p = b.insert(Leaky("5"));
		std::cout << p.second;
		b.insert(*p.first);

		vec.push_back(Leaky("7"));
		vec.push_back(Leaky("8"));
		vec.push_back(Leaky("9"));
		b.insert(vec.begin(), vec.end());

		b.erase(++(++(b.begin())));
		b.erase(Leaky("9"));
		c.erase(c.begin(), c.end());
		lset	d(vec.begin(), vec.end());
		b.swap(d);
		b.clear();
	}
	system("leaks a.out | grep bytes')'");
}