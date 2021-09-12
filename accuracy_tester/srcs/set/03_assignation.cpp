#include "set_common.hpp"

int	main()
{
	std::list<int>	lst;
	lst.push_back(3);
	lst.push_back(1);
	lst.push_back(5);
	lst.push_back(2);
	lst.push_back(2);
	lst.push_back(4);

	setInt	set1(lst.begin(), lst.end());
	lst.push_front(0);
	setInt	set2(lst.begin(), --lst.end());
	setInt	set3;

	print_all(set1);
	print_all(set2);
	print_all(set3);

	set2 = set1;
	set1 = set3;
	set3 = set2;

	print_all(set1);
	print_all(set2);
	print_all(set3);

	return (0);
}