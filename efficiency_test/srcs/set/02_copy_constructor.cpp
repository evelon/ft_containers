#include "../common.hpp"

int main()
{
	clock_t t;
	clock_t ft_time;
	clock_t std_time;

	{
		std::vector<int>	vec;
		for (int i = 0; i < 1000; ++i)
			vec.push_back(i);
		ft::set<int>	ft(vec.begin(), vec.end());
		t = clock();
		for (int i = 0; i < 1000; ++i)
			ft::set<int>	set(ft);
		ft_time = clock() - t;

		std::set<int>	std(vec.begin(), vec.end());
		t = clock();
		for (int i = 0; i < 1000; ++i)
			std::set<int>	set(std);
		std_time = clock() - t;
		efficiency_output(ft_time, std_time);
	}
	return 0;
}