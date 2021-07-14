#include "set_common.hpp"

int	main()
{
	std::list<int>	lst;

	lst.push_back(4);
	lst.push_back(1);
	lst.push_back(5);
	lst.push_back(4);
	lst.push_back(3);

	setInt	st(lst.begin(), lst.end());
	std::cout << st.empty() << st.size() << '\n';

	setInt::size_type	size = st.max_size();
	(void)size;

	int	i = 0;
	while (!st.empty())
		st.erase(i++);

	std::cout << st.empty() << st.size() << '\n';

	return (0);
}