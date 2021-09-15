#include "../common.hpp"

int main()
{
	clock_t t;
	clock_t ft_time;
	clock_t std_time;

	{
		std::vector<std::string>	itvec(100, "string");
		t = clock();
		for (int i = 0; i < 1000; ++i)
			ft::vector<std::string>		ft(itvec.begin(), itvec.end());
		ft_time = clock() - t;
		t = clock();
		for (int i = 0; i < 1000; ++i)
			std::vector<std::string>	std(itvec.begin(), itvec.end());
		std_time = clock() - t;
		efficiency_output(ft_time, std_time);
	}
	return 0;
}
