#include "../common.hpp"

int main()
{
	clock_t t;
	clock_t ft_time;
	clock_t std_time;

	{
		ft::map<int, std::string>	ftmap;
		for (int i = 0; i < 1000; ++i)
			ftmap[i] = "string";
		ft::map<int, std::string>::const_reverse_iterator	ftit;
		t = clock();
		for (int i = 0; i < 1000; ++i)
			ftit = ftmap.rend();
		ft_time = clock() - t;

		std::map<int, std::string>	stdmap;
		for (int i = 0; i < 1000; ++i)
			stdmap[i] = "string";
		std::map<int, std::string>::const_reverse_iterator	stdit;
		t = clock();
		for (int i = 0; i < 1000; ++i)
			stdit = stdmap.rend();
		std_time = clock() - t;
		efficiency_output(ft_time, std_time);
	}
	return 0;
}