#include "../common.hpp"

int main()
{
	clock_t t;
	clock_t ft_time;
	clock_t std_time;

	{
		std::vector<ft::map<int, std::string> >	ftvec;
		for (int i = 0; i < 100; ++i)
		{
			ft::map<int, std::string>	map;
			for (int j = 0; j < 50; ++j)
				map[2 * j] = "string";
			ftvec.push_back(map);
		}
		t = clock();
		for (int i = 0; i < 100; ++i)
		{
			ft::map<int, std::string>::iterator	it = ftvec[i].begin();
			for (int j = 0; j < 100; ++j)
				it = ftvec[i].insert(it, ft::make_pair(j, "string"));
		}
		ft_time = clock() - t;

		std::vector<std::map<int, std::string> >	stdvec;
		for (int i = 0; i < 100; ++i)
		{
			std::map<int, std::string>	map;
			for (int j = 0; j < 50; ++j)
				map[2 * j] = "string";
			stdvec.push_back(map);
		}
		t = clock();
		for (int i = 0; i < 100; ++i)
		{
			std::map<int, std::string>::iterator	it = stdvec[i].begin();
			for (int j = 0; j < 100; ++j)
				it = stdvec[i].insert(it, std::make_pair(j, "string"));
		}
		std_time = clock() - t;

		efficiency_output(ft_time, std_time);
	}
	return 0;
}