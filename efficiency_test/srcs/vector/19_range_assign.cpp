#include "../common.hpp"

int main()
{
	clock_t t;
	clock_t ft_time;
	clock_t std_time;

	{
		std::vector<std::string>	range(1000, "string");

		ft::vector<std::string>	itvec1(1000, "string");
		t = clock();
		for (int i = 0; i < 1000; ++i)
			itvec1.assign(range.begin(), range.end());
		ft_time = clock() - t;
		std::vector<std::string>	itvec2(1000, "string");
		t = clock();
		for (int i = 0; i < 1000; ++i)
			itvec2.assign(range.begin(), range.end());
		std_time = clock() - t;
		efficiency_output(ft_time, std_time);
	}
	return 0;
}