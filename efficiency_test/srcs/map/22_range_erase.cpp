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
			for (int j = 0; j < 100; ++j)
				map[j] = "string";
			ftvec.push_back(map);
		}

		std::vector<ft::pair<ft::map<int, std::string>::iterator, ft::map<int, std::string>::iterator> > ftranges;
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

		std::vector<std::map<int, std::string> >	stdvec;
		for (int i = 0; i < 1000; ++i)
		{
			std::map<int, std::string>	map;
			for (int j = 0; j < 100; ++j)
				map[j] = "string";
			stdvec.push_back(map);
		}

		std::vector<std::pair<std::map<int, std::string>::iterator, std::map<int, std::string>::iterator> > stdranges;
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