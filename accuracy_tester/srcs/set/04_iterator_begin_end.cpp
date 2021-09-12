#include "set_common.hpp"

int	main()
{
	std::list<int>	lst;
	lst.push_back(3);
	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(2);
	lst.push_back(4);

	setInt	set4(lst.begin(), lst.end());

	lst.push_back(6);
	lst.push_front(5);
	lst.push_back(7);

	setInt	set7(lst.begin(), lst.end());

	setInt::iterator	it_7b = set7.begin();
	setInt::iterator	it_7e = set7.end();
	print_it(it_7b, it_7e);

	setInt::const_iterator	cit_7b = set7.begin();
	setInt::const_iterator	cit_7e = set7.end();
	print_it(cit_7b, cit_7e);

	setInt::reverse_iterator	rit_4b = set4.rbegin();
	setInt::reverse_iterator	rit_4e = set4.rend();
	print_it(rit_4b, rit_4e);

	setInt::const_reverse_iterator	crit_4b = set4.rbegin();
	setInt::const_reverse_iterator	crit_4e = set4.rend();
	print_it(crit_4b, crit_4e);

	print_it(it_7b, cit_7e); // iterator and const_iterator should be comparable
	print_it(rit_4b, crit_4e); // this also applys to reverse iterators
	print_it(cit_7b, it_7e);
	print_it(crit_4b, rit_4e);

	return (0);
}