#include "../common.hpp"

int main()
{
	clock_t t;
	clock_t ft_time;
	clock_t std_time;

	{
		std::vector<ft::pair<int, std::string> >	vec1;
		for (int i = 0; i < 100; ++i)
			vec1.push_back(ft::make_pair(i, "string"));
		t = clock();
		for (int i = 0; i < 100; ++i)
			ft::map<int, std::string>	ft(vec1.begin(), vec1.end());
		ft_time = clock() - t;

		std::vector<std::pair<int, std::string> >	vec2;
		for (int i = 0; i < 100; ++i)
			vec2.push_back(std::make_pair(i, "string"));
		t = clock();
		for (int i = 0; i < 100; ++i)
			std::map<int, std::string>	std(vec2.begin(), vec2.end());
		std_time = clock() - t;
		efficiency_output(ft_time, std_time);
	}
	return 0;
}