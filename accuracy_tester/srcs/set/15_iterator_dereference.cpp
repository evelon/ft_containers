#include "set_common.hpp"

int	main()
{
	std::list<std::string>	lst;

	lst.push_back("dddd");
	lst.push_back("a");
	lst.push_back("eeeeeeeeeeeeeeeeeeeeeeeee");
	lst.push_back("bbbb");
	lst.push_back("ccccccccc");

	setStr	st(lst.begin(), lst.end());

	std::cout << st.begin()->c_str() << '\n';
	std::cout << (++(st.begin()))->c_str() << '\n';

	setStr::const_iterator	cit = --st.end();
	setStr::const_reverse_iterator	crit = st.rbegin();

	std::cout << (cit->capacity() == (crit++)->capacity()) << '\n';
	std::cout << ((*(--cit)).capacity() == (*crit).capacity()) << '\n';
	std::cout << (cit->get_allocator() == (*crit).get_allocator()) << '\n';
	std::cout << *cit << *crit << '\n';

	return (0);
}
