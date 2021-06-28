#include "vector_common.hpp"

int	main()
{
	vecInt	i4(4);
	vecInt	i7(7);

	fill_int(i4, 0, 4);
	fill_int(i7, 7, 3);

	vecInt::iterator	it_7b = i7.begin();
	vecInt::iterator	it_7e = i7.end();
	print_it(it_7b, it_7e);

	vecInt::const_iterator	cit_7b = i7.begin();
	vecInt::const_iterator	cit_7e = i7.end();
	print_it(cit_7b, cit_7e);

	vecInt::reverse_iterator	rit_4b = i4.rbegin();
	vecInt::reverse_iterator	rit_4e = i4.rend();
	print_it(rit_4b, rit_4e);

	vecInt::const_reverse_iterator	crit_4b = i4.rbegin();
	vecInt::const_reverse_iterator	crit_4e = i4.rend();
	print_it(crit_4b, crit_4e);

	print_it(it_7b, cit_7e); // iterator and const_iterator should be comparable
	print_it(rit_4b, crit_4e); // this also applys to reverse iterators
	print_it(cit_7b, it_7e);
	print_it(crit_4b, rit_4e);

	return (0);
}