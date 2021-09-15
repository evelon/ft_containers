#include "../common.hpp"

int main()
{
	clock_t t;
	clock_t ft_time;
	clock_t std_time;

	{
		std::vector<int>	vec;
		for (int i = 0; i < 100; ++i)
			vec.push_back(i);

		ft::set<int>	ftset(vec.begin(), vec.end());
		std::vector<ft::set<int> >	ftvec;
		for (int i = 0; i < 100; ++i)
		{
			ft::set<int>	set(ftset);
			ftvec.push_back(set);
		}
		t = clock();
		ftvec.clear();
		ft_time = clock() - t;

		std::set<int>	stdset(vec.begin(), vec.end());
		std::vector<std::set<int> >	stdvec;
		for (int i = 0; i < 100; ++i)
		{
			std::set<int>	set(stdset);
			stdvec.push_back(set);
		}
		t = clock();
		stdvec.clear();
		std_time = clock() - t;
		efficiency_output(ft_time, std_time);
	}
	return 0;
}