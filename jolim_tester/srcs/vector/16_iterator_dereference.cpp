#include "vector_common.hpp"

int	main()
{
	vecStr	vec(1, "4");

	vec.push_back("abababab");
	vec.push_back("123123123123123123123");
	vec.push_back("1234123412341234123412341234123412341234124");

	std::cout << vec.begin()->c_str() << '\n';
	std::cout << (++(vec.begin()))->c_str() << '\n';

	vecStr::const_iterator	cit = --vec.end();
	vecStr::const_reverse_iterator	crit = vec.rbegin();

	std::cout << (cit->capacity() == (crit++)->capacity()) << '\n';
	std::cout << ((*(--cit)).capacity() == (*crit).capacity()) << '\n';
	std::cout << (cit->get_allocator() == (*crit).get_allocator()) << '\n';
	std::cout << *cit << *crit << '\n';

	return (0);
}
