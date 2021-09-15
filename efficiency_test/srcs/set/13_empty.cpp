#include "../common.hpp"

int main()
{
	clock_t t;
	clock_t ft_time;
	clock_t std_time;

	{
		ft::set<int>	ftset1;
		ft::set<int>	ftset2;
		for (int i = 0; i < 100; ++i)
			ftset1.insert(i);
		t = clock();
		for (int i = 0; i < 1000; ++i)
		{
			ftset1.empty();
			ftset2.empty();
		}
		ft_time = clock() - t;

		std::set<int>	stdset1;
		std::set<int>	stdset2;
		for (int i = 0; i < 100; ++i)
			stdset1.insert(i);
		t = clock();
		for (int i = 0; i < 1000; ++i)
		{
			stdset1.empty();
			stdset2.empty();
		}
		std_time = clock() - t;
		efficiency_output(ft_time, std_time);
	}
	return 0;
}