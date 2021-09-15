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
		ft::set<int>::const_reverse_iterator	ftit;
		t = clock();
		for (int i = 0; i < 1000; ++i)
			ftit = ftset.rend();
		ft_time = clock() - t;

		std::set<int>	stdset;
		for (int i = 0; i < 1000; ++i)
			stdset.insert(i);
		std::set<int>::const_reverse_iterator	stdit;
		t = clock();
		for (int i = 0; i < 1000; ++i)
			stdit = stdset.rend();
		std_time = clock() - t;
		efficiency_output(ft_time, std_time);
	}
	return 0;
}