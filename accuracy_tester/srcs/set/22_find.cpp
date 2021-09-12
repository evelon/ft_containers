#include "set_common.hpp"

int	main()
{
	setInt	st;

	st.insert(238);
	st.insert(765);
	st.insert(432);
	st.insert(345);
	st.insert(837);
	st.insert(678);
	st.insert(909);
	st.insert(876);
	st.insert(532);

	print_all(st);

	print_it(st.find(345), st.find(532));
	print_it(st.find(238), st.find(0));

	setInt::iterator	it0 = st.begin();
	setInt::iterator	it1 = st.find(345);
	setInt::iterator	it2 = st.find(837);
	setInt::iterator	eit = st.find(0);

	print_it(it0, it1);
	print_it(it1, it2);
	print_it(it2, eit);

	setInt::const_iterator	cit0 = st.begin();
	setInt::const_iterator	cit1 = st.find(345);
	setInt::const_iterator	cit2 = st.find(837);
	setInt::const_iterator	ecit = st.find(0);

	print_it(cit0, cit1);
	print_it(cit1, cit2);
	print_it(cit2, ecit);

	return (0);
}