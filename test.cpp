#include "RedBlackTree.hpp"
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

	ft::RedBlackTree<int>	tree;
	int	a;
	std::cout << (a = rand() % 100) << std::endl;
	tree.addValue(a);
	std::cout << (a = rand() % 100) << std::endl;
	tree.addValue(a);
	std::cout << (a = rand() % 100) << std::endl;
	tree.addValue(a);
	std::cout << (a = rand() % 100) << std::endl;
	tree.addValue(a);
	std::cout << (a = rand() % 100) << std::endl;
	tree.addValue(a);

	// for (ft::RedBlackTree<int>::iterator it = tree.begin(); it != tree.end(); it++)
	// 	std::cout << *it << std::endl;
	ft::RedBlackTree<int>::iterator it = tree.begin();
	std::cout << *it << std::endl;
	++it;
	std::cout << *it << std::endl;
	++it;
	std::cout << *it << std::endl;
	++it;
	std::cout << *it << std::endl;
	++it;
	std::cout << *it << std::endl;
	++it;
}