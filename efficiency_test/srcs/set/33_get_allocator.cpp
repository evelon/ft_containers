#include "../common.hpp"

int main()
{
	clock_t t;
	clock_t ft_time;
	clock_t std_time;

	{
		ft::set<int>	set1;
		t = clock();
		for (int i = 0; i < 1000; ++i)
			set1.get_allocator();
		ft_time = clock() - t;
		std::set<int>	set2;
		t = clock();
		for (int i = 0; i < 1000; ++i)
			set2.get_allocator();
		std_time = clock() - t;
		efficiency_output(ft_time, std_time);
	}
	return 0;
}