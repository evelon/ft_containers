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
			for (int j = 0; j < 50; ++j)
				set.insert(2 * j);
			ftvec.push_back(set);
		}
		ft::set<int>::iterator	ftit;
		t = clock();
		for (int i = 0; i < 1000; ++i)
			ftit = ftvec[i].find(i % 100);
		ft_time = clock() - t;

		std::vector<std::set<int> >	stdvec;
		for (int i = 0; i < 1000; ++i)
		{
			std::set<int>	set;
			for (int j = 0; j < 50; ++j)
				set.insert(2 * j);
			stdvec.push_back(set);
		}
		std::set<int>::iterator	stdit;
		t = clock();
		for (int i = 0; i < 1000; ++i)
			stdit = stdvec[i].find(i % 100);
		std_time = clock() - t;

		efficiency_output(ft_time, std_time);
	}
	return 0;
}