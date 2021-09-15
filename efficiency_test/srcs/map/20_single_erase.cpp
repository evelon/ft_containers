#include "../common.hpp"

int main()
{
	clock_t t;
	clock_t ft_time;
	clock_t std_time;

	{
		std::vector<ft::map<int, std::string>::iterator> ftitvec;
		std::vector<ft::map<int, std::string> >	ftvec;
		for (int i = 0; i < 100; ++i)
		{
			ft::map<int, std::string>	map;
			for (int j = 0; j < 100; ++j)
				map[j] = "string";
			ftvec.push_back(map);
		}
		for (int i = 0; i < 100; ++i)
			ftitvec.push_back(ftvec[i].find(i));
		t = clock();
		for (int i = 0; i < 100; ++i)
			ftvec[i].erase(ftitvec[i]);
		ft_time = clock() - t;

		std::vector<std::map<int, std::string>::iterator> stditvec;
		std::vector<std::map<int, std::string> >	stdvec;
		for (int i = 0; i < 100; ++i)
		{
			std::map<int, std::string>	map;
			for (int j = 0; j < 100; ++j)
				map[j] = "string";
			stdvec.push_back(map);
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