#include <ctime>
#include <vector>
#include "vector.hpp"

int main(char* argv[], int argc)
{
	bool	vector = false;
	bool	map = false;
	bool	stack = false;
	bool	set = false;
	clock_t t;
	clock_t ft_time;
	clock_t std_time;

	if (argc == 1)
	{
		vector = true;
		map = true;
		stack = true;
		set = true;
	}
	else
	{
		for (int i = 1; i < argc + 1; ++i)
		{
			if (!std::string(argv[i]).compare("vector"))
				vector = true;
			if (!std::string(argv[i]).compare("map"))
				map = true;
			if (!std::string(argv[i]).compare("stack"))
				stack = true;
			if (!std::string(argv[i]).compare("set"))
				set = true;
		}
	}

	if (vector)
	{
		t = clock();

	}


	return 0;
}
