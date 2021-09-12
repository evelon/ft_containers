#include "set_common.hpp"

int	main()
{
	test::enable_if<test::is_same<setA::key_type, A>::value>::type*	a1;
	(void)a1;
	test::enable_if<test::is_same<setA::value_type, A>::value>::type* a2;
	(void)a2;
	test::enable_if<test::is_same<setA::allocator_type, std::allocator<A> >::value>::type* a3;
	(void)a3;
	test::enable_if<test::is_same<setA::reference, setA::allocator_type::reference>::value>::type*	a4;
	(void)a4;
	test::enable_if<test::is_same<setA::const_reference, setA::allocator_type::const_reference>::value>::type*	a5;
	(void)a5;
	test::enable_if<test::is_same<setA::pointer, setA::allocator_type::pointer>::value>::type*	a6;
	(void)a6;
	test::enable_if<test::is_same<setA::const_pointer, setA::allocator_type::const_pointer>::value>::type*	a7;
	(void)a7;
	setA::iterator	it;
	(void)it;
	setA::const_iterator	cit;
	(void)cit;
	setA::reverse_iterator	rit;
	(void)rit;
	setA::const_reverse_iterator	crit;
	(void)crit;
	setA::difference_type	diff;
	(void)diff;
	setA::size_type	sz;
	(void)sz;

	test::enable_if<test::is_same<setA::iterator, setA::const_iterator>::value>::type*	dummy1;
	(void)dummy1;
	test::enable_if<test::is_same<setA::reverse_iterator, setA::const_reverse_iterator>::value>::type*	dummy2;
	(void)dummy2;

	return (0);
}