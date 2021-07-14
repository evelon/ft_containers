#include "set_common.hpp"

int	main()
{
	std::list<int>	lst;

	lst.push_back(3);
	lst.push_back(2);
	lst.push_back(1);
	lst.push_back(0);

	setInt		st(lst.begin(), lst.end());

	setInt::iterator		it = st.begin();
	setInt::const_iterator	cit = st.begin();

	*it = 0; // Error here;
	*cit = 0; // Error here;
}