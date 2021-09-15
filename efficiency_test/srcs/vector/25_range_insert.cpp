#include "../common.hpp"

int main()
{
	clock_t t;
	clock_t ft_time;
	clock_t std_time;

	{
		std::vector<std::string>	range(100, "string");

		ft::vector<std::string>	itvec1(100, "string");
		t = clock();
		for (int i = 0; i < 100; ++i)
			itvec1.insert(itvec1.begin(), range.begin(), range.end());
		ft_time = clock() - t;
		std::vector<std::string>	itvec2(100, "string");
		t = clock();
		for (int i = 0; i < 100; ++i)
			itvec2.insert(itvec2.begin(), range.begin(), range.end());
		std_time = clock() - t;
		efficiency_output(ft_time, std_time);
	}
	return 0;
}