#include "map_common.hpp"

int	main()
{
	test::enable_if<test::is_same<mapAB::key_type, A>::value>::type*	a1;
	(void)a1;
	test::enable_if<test::is_same<mapAB::mapped_type, B>::value>::type*	a2;
	(void)a2;
	test::enable_if<test::is_same<mapAB::value_type, NS::pair<const A, B> >::value>::type* a3;
	(void)a3;
	test::enable_if<test::is_same<mapAB::allocator_type, std::allocator<NS::pair<const A, B> > >::value>::type* a4;
	(void)a4;
	test::enable_if<test::is_same<mapAB::reference, mapAB::allocator_type::reference>::value>::type*	a5;
	(void)a5;
	test::enable_if<test::is_same<mapAB::const_reference, mapAB::allocator_type::const_reference>::value>::type*	a6;
	(void)a6;
	test::enable_if<test::is_same<mapAB::pointer, mapAB::allocator_type::pointer>::value>::type*	a7;
	(void)a7;
	test::enable_if<test::is_same<mapAB::const_pointer, mapAB::allocator_type::const_pointer>::value>::type*	a8;
	(void)a8;
	mapAB::iterator	it;
	(void)it;
	mapAB::const_iterator	cit;
	(void)cit;
	mapAB::reverse_iterator	rit;
	(void)rit;
	mapAB::const_reverse_iterator	crit;
	(void)crit;
	mapAB::difference_type	diff;
	(void)diff;
	mapAB::size_type	sz;
	(void)sz;

	return (0);
}