#include "map.hpp"
#include "list.hpp"
#include <map>
#include <iostream>
#include <set>
#include <random>
#define NS std

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


	int	arr[] = {rand() % 26 + 'a', rand() % 26 + 'a', rand() % 26 + 'a', rand() % 26 + 'a', rand() % 26 + 'a', rand() % 26 + 'a'};
	ft::list<ft::pair<char, int> >	lst;
	for (size_t i = 0; i < 6; ++i)
		lst.push_back(ft::make_pair(arr[i], rand() % 50));
	ft::map<char, int>	map;


	map.insert(lst.begin(), lst.end());

	map.insert(ft::make_pair(rand() % 26 + 'a', rand() % 50));
	map.insert(ft::make_pair(rand() % 26 + 'a', rand() % 50));
	map.insert(ft::make_pair(rand() % 26 + 'a', rand() % 50));
	map.insert(ft::make_pair(rand() % 26 + 'a', rand() % 50));
	map.insert(ft::make_pair(rand() % 26 + 'a', rand() % 50));
	map.insert(ft::make_pair(rand() % 26 + 'a', rand() % 50));
	map.insert(ft::make_pair(rand() % 26 + 'a', rand() % 50));
	map.insert(ft::make_pair(rand() % 26 + 'a', rand() % 50));
	map.insert(ft::make_pair(rand() % 26 + 'a', rand() % 50));
	map.insert(ft::make_pair(rand() % 26 + 'a', rand() % 50));
	map.insert(ft::make_pair(rand() % 26 + 'a', rand() % 50));
	map.insert(ft::make_pair(rand() % 26 + 'a', rand() % 50));

	std::cout << std::endl;

	char	prev = 0;
	int		count = 0;
	for (ft::map<char, int>::iterator it = map.begin();
		it != map.end();
		++it)
	{
		std::cout << (*it).first << ": " << (*it).second;
		++count;
		if ((*it).first < prev)
			std::cout << " WRONG!!" << std::endl;
		else
			std::cout << std::endl;
		prev = (*it).first;
		if (count == 18)
			break ;
	}


	std::cout << '\n' << count << ' ' << map.size() << '\n';

	std::cout << map.erase(arr[0]);
	std::cout << map.erase(arr[1]);
	std::cout << map.erase(arr[2]);
	std::cout << map.erase(arr[3]);
	std::cout << map.erase(arr[4]);
	std::cout << map.erase(arr[5]) << std::endl;

	prev = 0;
	count = 0;
	for (ft::map<char, int>::iterator it = map.begin();
		it != map.end();
		++it)
	{
		std::cout << (*it).first << ": " << (*it).second;
		++count;
		if ((*it).first < prev)
			std::cout << " WRONG!!" << std::endl;
		else
			std::cout << std::endl;
		prev = (*it).first;
	}
	std::cout << '\n' << count << ' ' << map.size();

}

}