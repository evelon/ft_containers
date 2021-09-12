#include "vector_common.hpp"
#include <memory>

int	main()
{
	test::enable_if<test::is_same<vecA::value_type, A>::value>::type*	a1;
	(void)a1;
	test::enable_if<test::is_same<vecA::allocator_type, std::allocator<A> >::value>::type*	a2;
	(void)a2;
	test::enable_if<test::is_same<vecA::reference, vecA::allocator_type::reference>::value>::type*	a3;
	(void)a3;
	test::enable_if<test::is_same<vecA::const_reference, vecA::allocator_type::const_reference>::value>::type*	a4;
	(void)a4;
	test::enable_if<test::is_same<vecA::pointer, vecA::allocator_type::pointer>::value>::type*	a5;
	(void)a5;
	test::enable_if<test::is_same<vecA::const_pointer, vecA::allocator_type::const_pointer>::value>::type*	a6;
	(void)a6;
	vecA::iterator	it;
	(void)it;
	vecA::const_iterator	cit;
	(void)cit;
	vecA::reverse_iterator	rit;
	(void)rit;
	vecA::const_reverse_iterator	crit;
	(void)crit;
	vecA::difference_type	dif;
	dif = -1;
	std::cout << (dif > -1) << std::endl;
	vecA::size_type	size;
	size = -1;
	std::cout << (size > 0) << std::endl;
	return (0);
}