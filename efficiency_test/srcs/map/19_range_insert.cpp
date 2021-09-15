#include "../common.hpp"

int main()
{
	clock_t t;
	clock_t ft_time;
	clock_t std_time;

	{
		std::vector<std::vector<ft::pair<int, std::string> > > ftranges;
		for (int i = 0; i < 100; ++i)
		{
			std::vector<ft::pair<int, std::string> >	vec;
			int a = i;
			int b = 100 - i;

			for (int j = (a < b ? a : b); j < (a < b ? b : a); ++j)
			{
				vec.push_back(ft::make_pair(j, "string"));
			}
			ftranges.push_back(vec);
		}

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
			for (int j = 0; j < 100; ++j)
				ftvec[i].insert(ftranges[j].begin(), ftranges[j].end());
		}
		ft_time = clock() - t;

		std::vector<std::vector<std::pair<int, std::string> > > stdranges;
		for (int i = 0; i < 100; ++i)
		{
			std::vector<std::pair<int, std::string> >	vec;
			int a = i;
			int b = 100 - i;

			for (int j = (a < b ? a : b); j < (a < b ? b : a); ++j)
			{
				vec.push_back(std::make_pair(j, "string"));
			}
			stdranges.push_back(vec);
		}

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
			for (int j = 0; j < 100; ++j)
				stdvec[i].insert(stdranges[j].begin(), stdranges[j].end());
		}
		std_time = clock() - t;

		efficiency_output(ft_time, std_time);
	}
	return 0;
}