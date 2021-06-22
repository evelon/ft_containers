#include "list_common.hpp"

int	main()
{
	listInt	i4(4);
	listInt	i7(7);

	fill_int(i4, 0, 4);
	fill_int(i7, 7, 3);

	listInt::iterator	it_7b = i7.begin();
	listInt::iterator	it_7e = i7.end();
	print_it(it_7b, it_7e);

	listInt::const_iterator	cit_7b = i7.begin();
	listInt::const_iterator	cit_7e = i7.end();
	print_it(cit_7b, cit_7e);

	listInt::reverse_iterator	rit_4b = i4.rbegin();
	listInt::reverse_iterator	rit_4e = i4.rend();
	print_it(rit_4b, rit_4e);

	listInt::const_reverse_iterator	crit_4b = i4.rbegin();
	listInt::const_reverse_iterator	crit_4e = i4.rend();
	print_it(crit_4b, crit_4e);

	print_it(it_7b, cit_7e); // iterator and const_iterator should be comparable
	print_it(rit_4b, crit_4e); // this also applys to reverse iterators
	print_it(cit_7b, it_7e);
	print_it(crit_4b, rit_4e);


}