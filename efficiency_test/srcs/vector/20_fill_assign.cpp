#include "../common.hpp"

int main()
{
	clock_t t;
	clock_t ft_time;
	clock_t std_time;

	{
		ft::vector<std::string>	itvec1(1000, "string");
		t = clock();
		for (int i = 0; i < 1000; ++i)
			itvec1.assign(1000, "string");
		ft_time = clock() - t;
		std::vector<std::string>	itvec2(1000, "string");
		t = clock();
		for (int i = 0; i < 1000; ++i)
			itvec2.assign(1000, "string");
		std_time = clock() - t;
		efficiency_output(ft_time, std_time);
	}
	return 0;
}