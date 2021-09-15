#include "../common.hpp"

int main()
{
	clock_t t;
	clock_t ft_time;
	clock_t std_time;

	{
		t = clock();
		for (int i = 0; i < 100; ++i)
		{
			ft::map<int, std::string>	ftmap;
			for (int j = 0; j < 1000; ++j)
				ftmap[j] = "string";
		}
		ft_time = clock() - t;

		t = clock();
		for (int i = 0; i < 100; ++i)
		{
			std::map<int, std::string>	stdmap;
			for (int j = 0; j < 1000; ++j)
				stdmap[j] = "string";
		}
		std_time = clock() - t;

		efficiency_output(ft_time, std_time);
	}
	return 0;
}