#include "../common.hpp"

int main()
{
	clock_t t;
	clock_t ft_time;
	clock_t std_time;

	{
		t = clock();
		ft::vector<std::string>	itvec1(100, "string");
		for (int i = 0; i < 1000; ++i)
			ft::vector<std::string>		ft(itvec1);
		ft_time = clock() - t;
		t = clock();
		std::vector<std::string>	itvec2(100, "string");
		for (int i = 0; i < 1000; ++i)
			std::vector<std::string>	std(itvec2);
		std_time = clock() - t;
		efficiency_output(ft_time, std_time);
	}
	return 0;
}