#include "../common.hpp"

int main()
{
	clock_t t;
	clock_t ft_time;
	clock_t std_time;
	size_t	size;

	{
		ft::vector<std::string>	vec1(1000, "string");
		t = clock();
		for (int i = 0; i < 1000; ++i)
			size = vec1.size();
		ft_time = clock() - t;
		std::vector<std::string>	vec2(1000, "string");
		t = clock();
		for (int i = 0; i < 1000; ++i)
			size = vec2.size();
		std_time = clock() - t;
		efficiency_output(ft_time, std_time);
	}
	return 0;
}