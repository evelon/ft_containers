#include "../common.hpp"

int main()
{
	clock_t t;
	clock_t ft_time;
	clock_t std_time;

	{
		ft::vector<std::string>	vec1(1000, "string");
		t = clock();
		for (int i = 0; i < 1000; ++i)
			vec1.erase(vec1.begin());
		ft_time = clock() - t;
		std::vector<std::string>	vec2(1000, "string");
		t = clock();
		for (int i = 0; i < 1000; ++i)
			vec2.erase(vec2.begin());
		std_time = clock() - t;
		efficiency_output(ft_time, std_time);
	}
	return 0;
}