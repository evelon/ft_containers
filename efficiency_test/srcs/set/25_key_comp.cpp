#include "../common.hpp"

int main()
{
	clock_t t;
	clock_t ft_time;
	clock_t std_time;

	{
		ft::set<int>	ftset;
		for (int i = 0; i < 1000; ++i)
			ftset.insert(i);
		t = clock();
		for (int i = 0; i < 1000; ++i)
			ftset.key_comp();
		ft_time = clock() - t;

		std::set<int>	stdset;
		for (int i = 0; i < 1000; ++i)
			stdset.insert(i);
		t = clock();
		for (int i = 0; i < 1000; ++i)
			stdset.key_comp();
		std_time = clock() - t;
		efficiency_output(ft_time, std_time);
	}
	return 0;
}