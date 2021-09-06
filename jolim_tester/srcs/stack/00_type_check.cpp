#include "stack_common.hpp"

int	main()
{
	test::enable_if<test::is_same<NS::stack<int, NS::vector<int> >::value_type, int>::value>::type*	a1;
	(void)a1;
	test::enable_if<test::is_same<NS::stack<int, NS::vector<int> >::container_type, NS::vector<int> >::value>::type*	a2;
	(void)a2;
	test::enable_if<test::is_same<NS::stack<int, NS::vector<int> >::size_type, size_t>::value>::type*	a3;
	(void)a3;
}