#include "../common.hpp"

int main()
{
	clock_t t;
	clock_t ft_time;
	clock_t std_time;

	{
		ft::vector<std::string>	vec1;
		t = clock();
		for (int i = 0; i < 1000; ++i)
			vec1.insert(vec1.begin(), "string");
		ft_time = clock() - t;
		std::vector<std::string>	vec2;
		t = clock();
		for (int i = 0; i < 1000; ++i)
			vec2.insert(vec2.begin(), "string");
		std_time = clock() - t;
		efficiency_output(ft_time, std_time);
	}
	return 0;
}