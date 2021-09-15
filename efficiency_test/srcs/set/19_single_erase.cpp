#include "../common.hpp"

int main()
{
	clock_t t;
	clock_t ft_time;
	clock_t std_time;

	{
		std::vector<ft::set<int>::iterator> ftitvec;
		std::vector<ft::set<int> >	ftvec;
		for (int i = 0; i < 100; ++i)
		{
			ft::set<int>	set;
			for (int j = 0; j < 100; ++j)
				set.insert(j);
			ftvec.push_back(set);
		}
		for (int i = 0; i < 100; ++i)
			ftitvec.push_back(ftvec[i].find(i));
		t = clock();
		for (int i = 0; i < 100; ++i)
			ftvec[i].erase(ftitvec[i]);
		ft_time = clock() - t;

		std::vector<std::set<int>::iterator> stditvec;
		std::vector<std::set<int> >	stdvec;
		for (int i = 0; i < 100; ++i)
		{
			std::set<int>	set;
			for (int j = 0; j < 100; ++j)
				set.insert(j);
			stdvec.push_back(set);
		}
		for (int i = 0; i < 100; ++i)
			stditvec.push_back(stdvec[i].find(i));
		t = clock();
		for (int i = 0; i < 100; ++i)
			stdvec[i].erase(stditvec[i]);
		std_time = clock() - t;

		efficiency_output(ft_time, std_time);
	}
	return 0;
}