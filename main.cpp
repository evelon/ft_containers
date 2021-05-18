#include "list.hpp"

#include <iostream>

void	size_check(ft::list<int> lst)
{
	int	i = 0;
	for (ft::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
		i++;
	std::cout << "size: " << lst.size() << "?=" << i << std::endl;
}

void	print_lst(ft::list<int> lst)
{
	for (ft::list<int>::reverse_iterator rit = lst.rbegin(); rit != lst.rend(); ++rit)
		std::cout << *rit << std::endl;
	std::cout << std::endl;
}

bool	reverse(int a, int b)
{
	return (a > b);
}

int	main()
{

	ft::list<int>		lst;

	for (int i = 0; i < 7; i++)
		lst.push_back(i * 2);

	ft::list<int>::iterator	ite = --lst.begin();
	ft::list<int>::iterator	it = lst.begin();

	int j;
	for (j = 0; it != ite; j++)
	{
		std::cout << *ite << std::endl;
		ite--;
	}
	std::cout << j << std::endl;

	// ft::list<int>	lst;

	// for (int i = 0; i < 5; i++)
	// 	lst.push_back(i);

	// // size_check(lst);
	// // ft::list<int>::iterator bit = lst.begin();
	// // ft::list<int>::iterator eit = lst.end();

	// lst.resize(7, 12);

	// // size_check(lst);

	// ft::list<int>	lst2(4, 35);


	// size_check(lst);

	// for (ft::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
	// 	std::cout << *it << std::endl;
	// std::cout << std::endl;
	// // size_check(lst);
	// lst.swap(lst2);
	// ft::list<int>::iterator	it = lst.begin();

	// std::cout << *it << std::endl << std::endl;;
	// print_lst(lst);
	// print_lst(lst2);

	// std::cout << "out: " << &*(++lst.begin()) << std::endl;
	// ft::list<int>::iterator	ite = lst.begin();
	// 	ite++;
	// 	ite++;
	// lst.splice(ite, lst2);
	// lst.sort();
	// print_lst(lst);
	// size_check(lst);
	// print_lst(lst2);
	// size_check(lst2);

	// std::cout << (lst == lst2);

	// // ft::list<int>::const_iterator cit = ite;
	// system("leaks a.out > leaks");
	// return (0);
}
