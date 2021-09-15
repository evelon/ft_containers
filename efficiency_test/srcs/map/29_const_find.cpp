#include "../common.hpp"

int main()
{
	clock_t t;
	clock_t ft_time;
	clock_t std_time;

	{
		std::vector<ft::map<int, std::string> >	ftvec;
		for (int i = 0; i < 1000; ++i)
		{
			ft::map<int, std::string>	map;
			for (int j = 0; j < 50; ++j)
				map[2 * j] = "string";
			ftvec.push_back(map);
		}
		ft::map<int, std::string>::const_iterator	ftit;
		t = clock();
		for (int i = 0; i < 1000; ++i)
			ftit = ftvec[i].find(i % 100);
		ft_time = clock() - t;

		std::vector<std::map<int, std::string> >	stdvec;
		for (int i = 0; i < 1000; ++i)
		{
			std::map<int, std::string>	map;
			for (int j = 0; j < 50; ++j)
				map[2 * j] = "string";
			stdvec.push_back(map);
		}
		std::map<int, std::string>::const_iterator	stdit;
		t = clock();
		for (int i = 0; i < 1000; ++i)
			stdit = stdvec[i].find(i % 100);
		std_time = clock() - t;

		efficiency_output(ft_time, std_time);
	}
	return 0;
}