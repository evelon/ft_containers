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

	ft::list<int>			lst;
	lst.push_back(rand() % 15);
	lst.push_back(rand() % 15);
	lst.push_back(rand() % 15);
	lst.push_back(rand() % 15);
	lst.push_back(rand() % 15);
	lst.push_back(rand() % 15);
	lst.push_back(rand() % 15);
	lst.push_back(rand() % 15);
	ft::RedBlackTree<int>	tree;

	int	a;
	// std::cout << (a = rand() % 15) << std::endl;
	// tree.insert(a, false);
	// for (ft::RedBlackTree<int>::iterator it = tree.begin(); it != tree.end(); ++it)
	// 	std::cout << *it << ' ';
	// std::cout << '\n';



	std::cout << (a = rand() % 15) << std::endl;
	tree.insert(a, true);
	std::cout << (a = rand() % 15) << std::endl;
	tree.insert(a, true);
	std::cout << (a = rand() % 15) << std::endl;
	tree.insert(a, true);
	std::cout << (a = rand() % 15) << std::endl;
	tree.insert(a, true);
	std::cout << (a = rand() % 15) << std::endl;
	tree.insert(a, true);

	tree.insert(lst.begin(), lst.end(), true);

	// tree.insert(30);
	// tree.insert(7);
	// tree.insert(20);
	// tree.insert(77);
	// tree.insert(83);
	// tree.insert(45);
	// tree.insert(94);

	// tree.insert(5);
	// tree.insert(3);
	// tree.insert(4);
	// tree.insert(1);

	std::cout << std::endl;

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
	std::cout << '\n' << tree.size();
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
	system("leaks a.out >> leaks");
}