#include "map.hpp"
#include "list.hpp"
#include "vector.hpp"
#include <map>
#include <iostream>
#include <set>
#include <random>
#include <algorithm>
#define NS ft

// class A
// {
// public:
// 	A(void)
// 	{ std::cout << "construct" << std::endl; };
// 	A(A const&)
// 	{ std::cout << "copy construct" << std::endl; };
// 	~A(void)
// 	{ std::cout << "destroy" << std::endl; };
// 	A&	operator=(A const&)
// 	{ return (*this); };
// 	bool	operator<(A const&)
// 	{ return (false); };
// };

int	main()
{
{
	srand(time(NULL));

	NS::vector<int>	vec;

	vec.push_back(rand() % 100);
	vec.push_back(rand() % 100);
	vec.push_back(rand() % 100);
	vec.push_back(rand() % 100);
	vec.push_back(rand() % 100);
	vec.push_back(rand() % 100);
	vec.push_back(rand() % 100);
	vec.push_back(rand() % 100);
	vec.push_back(rand() % 100);
	vec.push_back(rand() % 100);
	vec.push_back(rand() % 100);

	std::sort(vec.begin(), vec.end());

	for (NS::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		std::cout << *it << '\n';
	}
}
}