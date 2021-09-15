#include "../common.hpp"

int main()
{
	clock_t t;
	clock_t ft_time;
	clock_t std_time;

	{
		ft::map<int, std::string>	map1;
		for (int i = 0; i < 100; ++i)
			map1[i] = "string";
		t = clock();
		for (int i = 0; i < 100; ++i)
			ft::map<int, std::string>	map(map1);
		ft_time = clock() - t;

		std::map<int, std::string>	map2;
		for (int i = 0; i < 100; ++i)
			map2[i] = "string";
		t = clock();
		for (int i = 0; i < 100; ++i)
			std::map<int, std::string>	map(map2);
		std_time = clock() - t;
		efficiency_output(ft_time, std_time);
	}
	return 0;
}