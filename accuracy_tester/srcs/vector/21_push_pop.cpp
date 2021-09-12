#include "vector_common.hpp"

int	main()
{
	vecStr	vec;

	vec.push_back("a string");
	std::cout << vec.front() << vec.back() << *vec.begin() << '\n';
	vec.push_back("a string!");
	std::cout << vec.front() << vec.back() << *vec.begin() << '\n';
	vec.push_back("a string~!?");
	print_all(vec);

	vec.pop_back();
	std::cout << vec.front() << vec.back() << *vec.begin() << '\n';
	vec.pop_back();
	std::cout << vec.front() << vec.back() << *vec.begin() << '\n';
	print_all(vec);
	while (vec.size())
	{
		vec.pop_back();
		print_all(vec);
	}
	return (0);
}