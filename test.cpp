#include "RedBlackTree.hpp"
#include "list.hpp"
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
	// NS::set<int>	intset;
	// intset.insert(rand()%100);
	// intset.insert(rand()%100);
	// intset.insert(rand()%100);
	// intset.insert(rand()%100);
	// intset.insert(rand()%100);
	// intset.insert(rand()%100);

	// for (NS::set<int>::iterator it = intset.begin(); it != intset.end(); ++it)
	// 	std::cout << *it << std::endl;
	// NS::set<int>::reverse_iterator	it = intset.rend();
	// std::cout << *(--it) << std::endl;

	int	arr[] = {rand() % 50, rand() % 50, rand() % 50, rand() % 50, rand() % 50, rand() % 50};
	ft::list<int>			lst;
	for (size_t i = 0; i < 6; ++i)
		lst.push_back(arr[i]);
	ft::RedBlackTree<int>	tree;

	// int	a;
	// std::cout << (a = rand() % 50) << std::endl;
	// tree.insert(a, false);
	// for (ft::RedBlackTree<int>::iterator it = tree.begin(); it != tree.end(); ++it)
	// 	std::cout << *it << ' ';
	// std::cout << '\n';


	tree.insert(lst.begin(), lst.end(), true);

	tree.insert(30, true);
	tree.insert(7, true);
	tree.insert(20, true);
	tree.insert(77, true);
	tree.insert(83, true);
	tree.insert(45, true);
	tree.insert(94, true);

	tree.insert(5, true);
	tree.insert(3, true);
	tree.insert(4, true);
	tree.insert(1, true);

	std::cout << std::endl;

	int	prev = 0;
	int count = 0;
	for (ft::RedBlackTree<int>::iterator it = tree.begin();
		it != tree.end();
		++it)
	{
		std::cout << *it;
		++count;
		if (*it < prev)
			std::cout << " WRONG!!" << std::endl;
		else
			std::cout << std::endl;
		prev = *it;
	}
	std::cout << '\n' << count << ' ' << tree.size() << '\n';

	std::cout << tree.erase(arr[0]);
	std::cout << tree.erase(arr[1]);
	std::cout << tree.erase(arr[2]);
	std::cout << tree.erase(arr[3]);
	std::cout << tree.erase(arr[4]);
	std::cout << tree.erase(arr[5]) << std::endl;

	prev = 0;
	count = 0;
	for (ft::RedBlackTree<int>::iterator it = tree.begin();
		it != tree.end();
		++it)
	{
		std::cout << *it;
		++count;
		if (*it < prev)
			std::cout << " WRONG!!" << std::endl;
		else
			std::cout << std::endl;
		prev = *it;
	}
	std::cout << '\n' << count << ' ' << tree.size();
	// ft::RedBlackTree<int>::iterator it = tree.begin();
	// std::cout << *it << std::endl;
	// ++it;
	// std::cout << *it << std::endl;
	// ++it;
	// std::cout << *it << std::endl;
	// ++it;
	// std::cout << *it << std::endl;
	// ++it;
	// std::cout << *it << std::endl;
}
	// system("leaks a.out >> leaks");
}