#include "../common.hpp"

int main()
{
	clock_t t;
	clock_t ft_time;
	clock_t std_time;

	{
		ft::map<int, std::string>	ftmap;
		for (int i = 0; i < 100; ++i)
			ftmap[i] = "string";
		t = clock();
		for (int i = 0; i < 1000; ++i)
			ftmap.max_size();
		ft_time = clock() - t;

		std::map<int, std::string>	stdmap;
		for (int i = 0; i < 100; ++i)
			stdmap[i] = "string";
		t = clock();
		for (int i = 0; i < 1000; ++i)
			stdmap.max_size();
		std_time = clock() - t;

		efficiency_output(ft_time, std_time);
	}
	return 0;
}