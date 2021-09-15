#include "../common.hpp"

int main()
{
	clock_t t;
	clock_t ft_time;
	clock_t std_time;

	{
		std::vector<std::vector<int> > ftranges;
		for (int i = 0; i < 100; ++i)
		{
			std::vector<int>	vec;
			int a = i;
			int b = 100 - i;

			for (int j = (a < b ? a : b); j < (a < b ? b : a); ++j)
				vec.push_back(j);
			ftranges.push_back(vec);
		}

		std::vector<ft::set<int> >	ftmap;
		for (int i = 0; i < 100; ++i)
		{
			ft::set<int>	set;
			for (int j = 0; j < 50; ++j)
				set.insert(2 * j);
			ftmap.push_back(set);
		}
		t = clock();
		for (int i = 0; i < 100; ++i)
		{
			for (int j = 0; j < 100; ++j)
				ftmap[i].insert(ftranges[j].begin(), ftranges[j].end());
		}
		ft_time = clock() - t;

		std::vector<std::vector<int> > stdranges;
		for (int i = 0; i < 100; ++i)
		{
			std::vector<int>	vec;
			int a = i;
			int b = 100 - i;

			for (int j = (a < b ? a : b); j < (a < b ? b : a); ++j)
				vec.push_back(j);
			stdranges.push_back(vec);
		}

		std::vector<std::set<int> >	stdmap;
		for (int i = 0; i < 100; ++i)
		{
			std::set<int>	set;
			for (int j = 0; j < 50; ++j)
				set.insert(2 * j);
			stdmap.push_back(set);
		}
		t = clock();
		for (int i = 0; i < 100; ++i)
		{
			for (int j = 0; j < 100; ++j)
				stdmap[i].insert(stdranges[j].begin(), stdranges[j].end());
		}
		std_time = clock() - t;

		efficiency_output(ft_time, std_time);
	}
	return 0;
}