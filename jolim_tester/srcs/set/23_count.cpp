#include "set_common.hpp"

int	main()
{
	setInt	st;

	st.insert(1);
	st.insert(1);
	st.insert(1);
	st.insert(2);
	st.insert(2);
	st.insert(3);

	print_all(st);

	std::cout << st.count(0) << '\n';
	std::cout << st.count(1) << '\n';
	std::cout << st.count(2) << '\n';
	std::cout << st.count(3) << '\n';
	std::cout << st.count(4) << '\n';

	return (0);
}