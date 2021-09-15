#include "../common.hpp"

int main()
{
	clock_t t;
	clock_t ft_time;
	clock_t std_time;

	{
		ft::vector<std::string>	vec1(1000, "string");
		ft::vector<std::string>	vec2(0);
		t = clock();
		for (int i = 0; i < 1000; ++i)
		{
			vec1.empty();
			vec2.empty();
		}
		ft_time = clock() - t;
		std::vector<std::string>	vec3(1000, "string");
		std::vector<std::string>	vec4(0);
		t = clock();
		for (int i = 0; i < 1000; ++i)
		{
			vec3.empty();
			vec4.empty();
		}
		std_time = clock() - t;
		efficiency_output(ft_time, std_time);
	}
	return 0;
}