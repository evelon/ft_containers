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
		for (int i = 0; i < 100; ++i)
			ftset2.insert(i * 2);
		t = clock();
		for (int i = 0; i < 1000; ++i)
			swap(ftset1, ftset2);
		ft_time = clock() - t;

		std::set<int>	stdset1;
		std::set<int>	stdset2;
		for (int i = 0; i < 100; ++i)
			stdset1.insert(i);
		for (int i = 0; i < 100; ++i)
			stdset2.insert(i * 2);
		t = clock();
		for (int i = 0; i < 1000; ++i)
			swap(stdset1, stdset2);
		std_time = clock() - t;
		efficiency_output(ft_time, std_time);
	}
	return 0;
}