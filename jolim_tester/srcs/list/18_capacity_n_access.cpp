#include "list_common.hpp"

int	main()
{
	listInt	li;

	std::cout << li.empty() << li.size() << '\n';

	listInt::size_type	size = li.max_size();
	(void)size;

	li.resize(4);
	fill_int(li, 3, 4);
	std::cout << li.empty() << li.size() << '\n';

	std::cout << li.front() << '\n';
	std::cout << li.back() << '\n';

	while (!li.empty())
		li.pop_back();

	std::cout << li.empty() << li.size() << '\n';

	return (0);
}