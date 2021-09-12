#include "list_common.hpp"

int	main()
{
	listStr	lst;

	lst.push_back("a string");
	listStr::iterator	it = lst.begin();
	std::cout << lst.front() << lst.back() << *it << '\n';
	lst.push_back("a string!");
	std::cout << lst.front() << lst.back() << *it << '\n';
	lst.push_front("a string~!");
	std::cout << lst.front() << lst.back() << *it << '\n';
	lst.push_back("a string~!?");
	print_all(lst);

	lst.pop_front();
	std::cout << lst.front() << lst.back() << *it << '\n';
	lst.pop_back();
	std::cout << lst.front() << lst.back() << *it << '\n';
	lst.pop_back();
	std::cout << lst.front() << lst.back() << *it << '\n';
	lst.push_front("strings");
	std::cout << lst.front() << lst.back() << *it << '\n';
	print_all(lst);
	while (lst.size())
		lst.pop_back();
	return (0);
}