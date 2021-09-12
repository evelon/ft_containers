#include "set_common.hpp"

int	main()
{
	setChar	st;

	st.insert('a');
	st.insert('b');
	st.insert('c');
	st.insert('d');
	st.insert('e');

	setChar::iterator	itlow, itup;
	setChar::const_iterator	citlow, citup;

	itlow = st.lower_bound('b');
	itup = st.upper_bound('b');
	print_it(itlow, itup);

	itlow = st.lower_bound('a');
	itup = st.upper_bound('a');
	print_it(itlow, itup);

	itlow = st.lower_bound('e');
	itup = st.upper_bound('e');
	print_it(itlow, itup);

	itlow = st.lower_bound('a');
	itup = st.upper_bound('e');
	print_it(itlow, itup);

	itlow = st.lower_bound('b');
	itup = st.upper_bound('d');
	print_it(itlow, itup);

	itlow = st.lower_bound('0');
	itup = st.upper_bound('z');
	print_it(itlow, itup);


	citlow = st.lower_bound('b');
	citup = st.upper_bound('b');
	print_it(citlow, citup);

	citlow = st.lower_bound('a');
	citup = st.upper_bound('a');
	print_it(citlow, citup);

	citlow = st.lower_bound('e');
	citup = st.upper_bound('e');
	print_it(citlow, citup);

	citlow = st.lower_bound('a');
	citup = st.upper_bound('e');
	print_it(citlow, citup);

	citlow = st.lower_bound('b');
	citup = st.upper_bound('d');
	print_it(citlow, citup);

	citlow = st.lower_bound('0');
	citup = st.upper_bound('z');
	print_it(citlow, citup);

	return (0);
}