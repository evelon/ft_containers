#include "set_common.hpp"

int	main()
{
	std::list<int>	lst;
	lst.push_back(3);

	setInt	st(lst.begin(), lst.end());

	setInt::const_reverse_iterator	crit = st.rbegin();
	setInt::reverse_iterator	rit(crit);

	(void)rit;

	return (0);
}