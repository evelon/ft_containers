#include "../common.hpp"

int main()
{
	clock_t t;
	clock_t ft_time;
	clock_t std_time;

	{
		t = clock();
		for (int i = 0; i < 1000; ++i)
			ft::vector<ft::vector<ft::vector<ft::vector<ft::vector<std::string> > > > >		ft;
		ft_time = clock() - t;
		t = clock();
		for (int i = 0; i < 1000; ++i)
			std::vector<std::vector<std::vector<std::vector<std::vector<std::string> > > > >		std;
		std_time = clock() - t;
		efficiency_output(ft_time, std_time);
	}
	return 0;
}