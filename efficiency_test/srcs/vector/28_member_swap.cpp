#include "../common.hpp"

int main()
{
	clock_t t;
	clock_t ft_time;
	clock_t std_time;

	{
		ft::vector<std::string>	vec1(1000, "string");
		ft::vector<std::string>	vec2(1000, "test");
		t = clock();
		for (int i = 0; i < 100; ++i)
			vec1.swap(vec2);
		ft_time = clock() - t;
		std::vector<std::string>	vec3(1000, "string");
		std::vector<std::string>	vec4(1000, "test");
		t = clock();
		for (int i = 0; i < 100; ++i)
			vec3.swap(vec4);
		std_time = clock() - t;
		efficiency_output(ft_time, std_time);
	}
	return 0;
}