#include "list_common.hpp"
#include <random>

bool	is_same(int a, int b)
{
	return (a == b);
}

bool	is_consecutive(int a, int b)
{
	return (a - 1 == b || a == b - 1);
}

bool	is_evenly_common(int a, int b)
{
	return (a % 2 == b % 2);
}

bool	more(int a, int b)
{
	return (a > b);
}

bool	ignore_first_digit(int a, int b)
{
	return ((a / 10) < (b / 10));
}

int	main()
{
	int	array1[] = {0, 0, 0, 1, 1, 2, 2, 2, 2, 3, 3, 4, 4, 4, 4, 5, 5, 6, 6, 6, 7};
	listInt	lst1(array1, array1 + 21);

	std::cout << "before\n";
	print_all(lst1);

	std::cout << "\nunique\n";
	lst1.unique();
	print_all(lst1);

	std::cout << "\nunique predicate\n";
	lst1.unique(is_consecutive);
	print_all(lst1);

	std::cout << "new list\n";
	int	array2[] = {0, 2, 5, 4, 4, 4, 1, 5, 7, 3, 3, 4, 6, 4, 2, 5, 3, 2, 1};
	lst1.assign(array2, array2 + 19);

	std::cout << "\nunique\n";
	lst1.unique();
	print_all(lst1);

	std::cout << "\nunique predicate\n";
	lst1.unique(is_consecutive);
	print_all(lst1);

	std::cout << "\nrebuild two list and sort\n";
	lst1.assign(array1, array1 + 21);
	listInt	lst2(array2, array2 + 19);
	lst1.sort();
	lst2.sort();
	print_all(lst1);
	print_all(lst2);

	std::cout << "\nmerge\n";

	lst1.merge(lst2);
	print_all(lst1);
	print_all(lst2);

	std::cout << "\nrebuild two list and sort reverse\n";
	lst2.assign(array1, array1 + 21);
	lst1.assign(array2, array2 + 19);
	lst2.sort(more);
	lst1.sort(more);
	print_all(lst2);
	print_all(lst1);

	lst1.merge(lst2);
	print_all(lst1);
	print_all(lst2);
	lst1.unique(is_consecutive);
	lst2.unique();
	print_all(lst1);
	print_all(lst2);

	std::cout << "\nrebuild two list, merge and sort\n";
	lst1.assign(array1, array1 + 21);
	lst2.assign(array2, array2 + 19);
	int	count = 0;
	for (listInt::iterator	it = lst1.begin(); it != lst1.end(); ++it)
		*it = count++ % 10 * *it;
	for (listInt::iterator	it = lst2.begin(); it != lst2.end(); ++it)
		*it = count++ % 10 * *it;
	print_all(lst1);
	print_all(lst2);
	lst2.merge(lst1);
	print_all(lst2);
	lst2.sort(ignore_first_digit); // can differ
	print_all(lst2);

	return (0);
}