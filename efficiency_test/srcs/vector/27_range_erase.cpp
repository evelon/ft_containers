#include "../common.hpp"

int main()
{
	clock_t t;
	clock_t ft_time;
	clock_t std_time;

	{
		ft::vector<std::string>	vec1(10000, "string");
		t = clock();
		for (int i = 0; i < 100; ++i)
			vec1.erase(vec1.begin(), vec1.begin() + 100);
		ft_time = clock() - t;
		std::vector<std::string>	vec2(10000, "string");
		t = clock();
		for (int i = 0; i < 100; ++i)
			vec2.erase(vec2.begin(), vec2.begin() + 100);
		std_time = clock() - t;
		efficiency_output(ft_time, std_time);
	}
	return 0;
}