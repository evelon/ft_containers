#include "set_common.hpp"

int	main()
{
	setInt	st;

	st.insert(243);
	st.insert(234);

	setInt::key_compare	kcomp = st.key_comp();

	std::cout << kcomp(3, 4) << '\n';
	std::cout << kcomp(132, 2) << '\n';
	std::cout << kcomp(238902, 324) << '\n';
	std::cout << kcomp(3232, 1431) << '\n';

	std::cout << kcomp(*st.begin(), *st.begin()) << '\n';

	setInt::value_compare	vcomp = st.value_comp();

	setInt::iterator it = st.begin();
	setInt::reverse_iterator rit = st.rbegin();
	while (it != st.end())
	{
		std::cout << vcomp(*it, *rit) << '\n';
		++it;
		++rit;
	}

	std::cout << vcomp(2, 2) << '\n';
	std::cout << vcomp(213, 324) << '\n';
	std::cout << vcomp(3232, 787) << '\n';

	return (0);
}