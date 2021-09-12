#include "set_common.hpp"

int	main()
{
	std::list<int>	lst;
	lst.push_back(3);

	setInt	st(lst.begin(), lst.end());

	setInt::reverse_iterator	rit = st.rbegin();
	setInt::iterator			it(rit); // Error here. Should not be constructed

	return (0);
}