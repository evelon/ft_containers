#include "../common.hpp"

int main()
{
	clock_t t;
	clock_t ft_time;
	clock_t std_time;

	{
		ft::map<int, std::string>	ftmap1;
		ft::map<int, std::string>	ftmap2;
		for (int i = 0; i < 100; ++i)
			ftmap1[i] = "string";
		t = clock();
		for (int i = 0; i < 1000; ++i)
			ftmap2 = ftmap1;
		ft_time = clock() - t;

		std::map<int, std::string>	stdmap1;
		std::map<int, std::string>	stdmap2;
		for (int i = 0; i < 100; ++i)
			stdmap1[i] = "string";
		t = clock();
		for (int i = 0; i < 1000; ++i)
			stdmap2 = stdmap1;
		std_time = clock() - t;
		efficiency_output(ft_time, std_time);
	}
	return 0;
}