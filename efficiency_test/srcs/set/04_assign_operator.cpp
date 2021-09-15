#include "../common.hpp"

int main()
{
	clock_t t;
	clock_t ft_time;
	clock_t std_time;

	{
		std::vector<int>	vec;
		for (int i = 0; i < 100; ++i)
			vec.push_back(i);

		ft::set<int>	ftset1(vec.begin(), vec.end());
		ft::set<int>	ftset2;
		t = clock();
		for (int i = 0; i < 100; ++i)
			ftset2 = ftset1;
		ft_time = clock() - t;

		std::set<int>	stdset1(vec.begin(), vec.end());
		std::set<int>	stdset2;
		t = clock();
		for (int i = 0; i < 100; ++i)
			stdset2 = stdset1;
		std_time = clock() - t;
		efficiency_output(std_time, std_time);
	}
	return 0;
}