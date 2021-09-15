#include "../common.hpp"

int main()
{
	clock_t t;
	clock_t ft_time;
	clock_t std_time;

	{
		ft::vector<std::string>	itvec1(100, "string");
		ft::vector<std::string>::const_iterator fit;
		t = clock();
		for (int i = 0; i < 1000; ++i)
			fit = itvec1.begin();
		ft_time = clock() - t;
		std::vector<std::string>	itvec2(100, "string");
		std::vector<std::string>::const_iterator sit;
		t = clock();
		for (int i = 0; i < 1000; ++i)
			sit = itvec2.begin();
		std_time = clock() - t;
		efficiency_output(ft_time, std_time);
	}
	return 0;
}