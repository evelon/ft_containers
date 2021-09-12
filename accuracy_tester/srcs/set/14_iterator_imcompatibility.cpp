#include "set_common.hpp"

int	main()
{
	std::list<int>	lst;
	lst.push_back(3);

	setInt	st(lst.begin(), lst.end());

	setInt::const_reverse_iterator	crit = st.rbegin();
	setInt::iterator	it(crit); // Error here. should not be constructed.

	return (0);
}