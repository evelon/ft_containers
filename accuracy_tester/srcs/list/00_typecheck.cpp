#include "list_common.hpp"
#include <memory>

int	main()
{
	test::enable_if<test::is_same<listA::value_type, A>::value>::type*	a1;
	(void)a1;
	test::enable_if<test::is_same<listA::allocator_type, std::allocator<A> >::value>::type*	a2;
	(void)a2;
	test::enable_if<test::is_same<listA::reference, listA::allocator_type::reference>::value>::type*	a3;
	(void)a3;
	test::enable_if<test::is_same<listA::const_reference, listA::allocator_type::const_reference>::value>::type*	a4;
	(void)a4;
	test::enable_if<test::is_same<listA::pointer, listA::allocator_type::pointer>::value>::type*	a5;
	(void)a5;
	test::enable_if<test::is_same<listA::const_pointer, listA::allocator_type::const_pointer>::value>::type*	a6;
	(void)a6;
	listA::iterator	it;
	(void)it;
	listA::const_iterator	cit;
	(void)cit;
	listA::reverse_iterator	rit;
	(void)rit;
	listA::const_reverse_iterator	crit;
	(void)crit;
	listA::difference_type	dif;
	dif = -1;
	std::cout << (dif > -1) << std::endl;
	listA::size_type	size;
	size = -1;
	std::cout << (size > 0) << std::endl;
	return (0);
}