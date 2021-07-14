#include "set_common.hpp"

int	main()
{
	std::list<int>	lst;
	lst.push_back(3);

	setInt	st(lst.begin(), lst.end());

	setInt::const_iterator	cit = st.begin();
	setInt::iterator	it(cit);

	(void)it;

	return (0);
}