#include "list_common.hpp"

int	main()
{
	listInt	lst1(12);
	listInt	lst2(14);

	fill_int(lst1, 2, 2);
	fill_int(lst2, 14 * 2, -2);

	listInt::const_iterator	bit1 = lst1.begin();
	listInt::iterator	eit1 = --lst1.end();
	listInt::const_reverse_iterator	bit2 = ++lst2.rbegin();
	listInt::reverse_iterator	eit2 = lst2.rend();

	std::cout << "before member-swap\n";
	print_it(bit1, eit1);
	print_all(lst1);
	print_it(bit2, eit2);
	print_all(lst2);

	lst1.swap(lst2);

	std::cout << "\nafter member swap\n";
	print_it(bit1, eit1);
	print_all(lst1);
	print_it(bit2, eit2);
	print_all(lst2);

	std::cout << "\nresize\n";
	lst1.resize(4);
	lst1.resize(6);
	lst2.resize(28, 28);

	print_all(lst1);
	print_all(lst2);

	bit1 = lst1.begin();
	eit1 = --lst1.end();
	bit2 = ++lst2.rbegin();
	eit2 = lst2.rend();

	NS::swap(lst2, lst1);
	std::cout << "after non-member swap\n";

	print_it(bit1, eit1);
	print_all(lst1);
	print_it(bit2, eit2);
	print_all(lst2);

	std::cout << "clear and some swap";

	lst1.clear();
	lst2.swap(lst1);
	print_all(lst1);
	print_all(lst2);
	lst2.swap(lst1);
	print_all(lst1);
	print_all(lst2);
	lst2.clear();
	print_all(lst1);
	print_all(lst2);
	return (0);
}