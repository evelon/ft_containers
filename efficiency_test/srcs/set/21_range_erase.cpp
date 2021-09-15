#include "../common.hpp"

int main()
{
	clock_t t;
	clock_t ft_time;
	clock_t std_time;

	{
		std::vector<ft::set<int> >	ftvec;
		for (int i = 0; i < 1000; ++i)
		{
			ft::set<int>	set;
			for (int j = 0; j < 100; ++j)
				set.insert(j);
			ftvec.push_back(set);
		}

		std::vector<ft::pair<ft::set<int>::iterator, ft::set<int>::iterator> > ftranges;
		for (int i = 0; i < 1000; ++i)
		{
			int a = i;
			int b = 100 - i;
			ftranges.push_back(ft::make_pair(ftvec[i].find(a < b ? a : b), ftvec[i].find(a < b ? b : a)));
		}

		t = clock();
		for (int i = 0; i < 100; ++i)
			ftvec[i].erase(ftranges[i].first, ftranges[i].second);
		ft_time = clock() - t;

		std::vector<std::set<int> >	stdvec;
		for (int i = 0; i < 1000; ++i)
		{
			std::set<int>	set;
			for (int j = 0; j < 100; ++j)
				set.insert(j);
			stdvec.push_back(set);
		}

		std::vector<std::pair<std::set<int>::iterator, std::set<int>::iterator> > stdranges;
		for (int i = 0; i < 1000; ++i)
		{
			int a = i;
			int b = 100 - i;
			stdranges.push_back(std::make_pair(stdvec[i].find(a < b ? a : b), stdvec[i].find(a < b ? b : a)));
		}

		t = clock();
		for (int i = 0; i < 100; ++i)
			stdvec[i].erase(stdranges[i].first, stdranges[i].second);
		std_time = clock() - t;

		efficiency_output(ft_time, std_time);
	}
	return 0;
}