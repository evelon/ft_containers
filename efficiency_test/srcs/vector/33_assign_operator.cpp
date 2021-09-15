#include "../common.hpp"

int main()
{
	clock_t t;
	clock_t ft_time;
	clock_t std_time;

	{
		ft::vector<std::string>	ftvec1(100, "string");
		ft::vector<std::string>	ftvec2;
		t = clock();
		for (int i = 0; i < 1000; ++i)
			ftvec2 = ftvec1;
		ft_time = clock() - t;
		std::vector<std::string>	stdvec1(100, "string");
		std::vector<std::string>	stdvec2;
		t = clock();
		for (int i = 0; i < 1000; ++i)
			stdvec2 = stdvec1;
		std_time = clock() - t;
		efficiency_output(ft_time, std_time);
	}
	return 0;
}