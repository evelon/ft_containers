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

	// int	a;
	// std::cout << (a = rand() % 100) << std::endl;
	// tree.addValue(a);
	// for (ft::RedBlackTree<int>::iterator it = tree.begin(); it != tree.end(); ++it)
	// 	std::cout << *it << ' ';
	// std::cout << '\n';

	// std::cout << (a = rand() % 100) << std::endl;
	// tree.addValue(a);
	// for (ft::RedBlackTree<int>::iterator it = tree.begin(); it != tree.end(); ++it)
	// 	std::cout << *it << ' ';
	// std::cout << '\n';

	// std::cout << (a = rand() % 100) << std::endl;
	// tree.addValue(a);
	// for (ft::RedBlackTree<int>::iterator it = tree.begin(); it != tree.end(); ++it)
	// 	std::cout << *it << ' ';
	// std::cout << '\n';

	// std::cout << (a = rand() % 100) << std::endl;
	// tree.addValue(a);
	// for (ft::RedBlackTree<int>::iterator it = tree.begin(); it != tree.end(); ++it)
	// 	std::cout << *it << ' ';
	// std::cout << '\n';

	// std::cout << (a = rand() % 100) << std::endl;
	// tree.addValue(a);
	// for (ft::RedBlackTree<int>::iterator it = tree.begin(); it != tree.end(); ++it)
	// 	std::cout << *it << ' ';
	// std::cout << '\n';

	// std::cout << (a = rand() % 100) << std::endl;
	// tree.addValue(a);
	// for (ft::RedBlackTree<int>::iterator it = tree.begin(); it != tree.end(); ++it)
	// 	std::cout << *it << ' ';
	// std::cout << '\n';

	// std::cout << (a = rand() % 100) << std::endl;
	// tree.addValue(a);
	// for (ft::RedBlackTree<int>::iterator it = tree.begin(); it != tree.end(); ++it)
	// 	std::cout << *it << ' ';
	// std::cout << '\n';

	// std::cout << (a = rand() % 100) << std::endl;
	// tree.addValue(a);
	// for (ft::RedBlackTree<int>::iterator it = tree.begin(); it != tree.end(); ++it)
	// 	std::cout << *it << ' ';
	// std::cout << '\n';

	// std::cout << (a = rand() % 100) << std::endl << std::endl;
	// tree.addValue(a);

	// for (ft::RedBlackTree<int>::iterator it = tree.begin(); it != tree.end(); ++it)
	// 	std::cout << *it << ' ';
	// std::cout << '\n';

	// tree.addValue(30);
	// tree.addValue(7);
	// tree.addValue(20);
	// tree.addValue(77);
	// tree.addValue(83);
	// tree.addValue(45);
	// tree.addValue(94);

	tree.addValue(5);
	tree.addValue(3);
	tree.addValue(4);
	tree.addValue(1);


	int	prev = 0;
	for (ft::RedBlackTree<int>::iterator it = tree.begin();
		it != tree.end();
		++it)
	{
		std::cout << *it;
		if (*it < prev)
			std::cout << " WRONG!!" << std::endl;
		else
			std::cout << std::endl;
		prev = *it;
	}
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