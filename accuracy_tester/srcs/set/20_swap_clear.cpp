#include "set_common.hpp"

int	main()
{
	std::list<std::string>	lst1;
	lst1.push_back("beta");
	lst1.push_back("epsilon");
	lst1.push_back("gamma");
	lst1.push_back("delta");
	lst1.push_back("alpha");

	setStr	set1(lst1.begin(), lst1.end());

	std::list<std::string>	lst2;
	lst2.push_back("aaaaaaaaaaaaaaaa");
	lst2.push_back("bbbbbbbbb");
	lst2.push_back("ccccccccccccccccccccccccc");
	lst2.push_back("d");
	lst2.push_back("eeee");

	setStr	set2(lst2.begin(), lst2.end());

	setStr::const_iterator	bit1 = set1.begin();
	setStr::iterator	eit1 = --set1.end();
	setStr::const_reverse_iterator	bit2 = ++set2.rbegin();
	setStr::reverse_iterator	eit2 = set2.rend();

	std::cout << "before member-swap\n";
	print_it(bit1, eit1);
	print_all(set1);
	print_it(bit2, eit2);
	print_all(set2);

	set1.swap(set2);

	std::cout << "\nafter member swap\n";
	print_it(bit1, eit1);
	print_all(set1);
	print_it(bit2, eit2);
	print_all(set2);

	bit1 = set1.begin();
	eit1 = --set1.end();
	bit2 = ++set2.rbegin();
	eit2 = set2.rend();

	NS::swap(set2, set1);
	std::cout << "after non-member swap\n";

	print_it(bit1, eit1);
	print_all(set1);
	print_it(bit2, eit2);
	print_all(set2);

	std::cout << "clear and some swap";

	set1.clear();
	set2.swap(set1);
	print_all(set1);
	print_all(set2);
	set2.swap(set1);
	print_all(set1);
	print_all(set2);
	set2.clear();
	print_all(set1);
	print_all(set2);

	return (0);
}