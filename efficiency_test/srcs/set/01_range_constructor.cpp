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
		t = clock();
		for (int i = 0; i < 1000; ++i)
			ft::set<int>	ft(vec.begin(), vec.end());
		ft_time = clock() - t;

		t = clock();
		for (int i = 0; i < 1000; ++i)
			std::set<int>	std(vec.begin(), vec.end());
		std_time = clock() - t;
		efficiency_output(ft_time, std_time);
	}
	return 0;
}