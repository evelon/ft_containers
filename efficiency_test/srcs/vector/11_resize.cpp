#include "../common.hpp"

int main()
{
	clock_t t;
	clock_t ft_time;
	clock_t std_time;

	{
		std::vector<ft::vector<std::string>	>	vecs1(100, ft::vector<std::string>(10, "string"));
		t = clock();
		for (size_t i = 0; i < vecs1.size(); ++i)
			vecs1[i].resize(100, "ftstd");
		ft_time = clock() - t;
		std::vector<std::vector<std::string> >	vecs2(100, std::vector<std::string>(10, "string"));
		t = clock();
		for (size_t i = 0; i < vecs2.size(); ++i)
			vecs2[i].resize(100, "ftstd");
		std_time = clock() - t;
		efficiency_output(ft_time, std_time);
	}
	return 0;
}