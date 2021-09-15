#include "../common.hpp"

int main()
{
	clock_t t;
	clock_t ft_time;
	clock_t std_time;

	{
		ft::map<int, std::string>	map1;
		t = clock();
		for (int i = 0; i < 1000; ++i)
			map1.get_allocator();
		ft_time = clock() - t;
		std::map<int, std::string>	map2;
		t = clock();
		for (int i = 0; i < 1000; ++i)
			map2.get_allocator();
		std_time = clock() - t;
		efficiency_output(ft_time, std_time);
	}
	return 0;
}