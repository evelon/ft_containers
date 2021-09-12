#include "set_common.hpp"

typedef	NS::pair<setChar::iterator, setChar::iterator>	iter_pair;
typedef	NS::pair<setChar::const_iterator, setChar::const_iterator>	citer_pair;

int	main()
{
	setChar	st;

	st.insert('a');
	st.insert('b');
	st.insert('c');
	st.insert('d');
	st.insert('e');

	const setChar	cst(st);

	iter_pair	it_pair;
	citer_pair	cit_pair;

	it_pair = st.equal_range('a');
	print_it(it_pair.first, ++it_pair.second);
	cit_pair = st.equal_range('b');
	print_it(cit_pair.first, ++cit_pair.second);

	cit_pair = st.equal_range('a');
	print_it(cit_pair.first, ++cit_pair.second);
	cit_pair = cst.equal_range('c');
	print_it(cit_pair.first, ++cit_pair.second);

	return (0);
}