#include "list_common.hpp"

int	main()
{
	listStr	lst(1, "4");

	lst.push_back("abababab");
	lst.push_back("123123123123123123123");
	lst.push_back("1234123412341234123412341234123412341234124");

	std::cout << lst.begin()->c_str() << '\n';
	std::cout << (++(lst.begin()))->c_str() << '\n';

	listStr::const_iterator	cit = --lst.end();
	listStr::const_reverse_iterator	crit = lst.rbegin();

	std::cout << (cit->capacity() == (crit++)->capacity()) << '\n';
	std::cout << ((*(--cit)).capacity() == (*crit).capacity()) << '\n';
	std::cout << (cit->get_allocator() == (*crit).get_allocator()) << '\n';
	std::cout << *cit << *crit << '\n';

	return (0);
}
