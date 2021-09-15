#include "map_common.hpp"

template	<typename T>
struct	LengthCompare
{
	bool	operator()(const T& a, const T& b) const
	{ return (a.length() < b.length()); };
};

typedef	NS::map<std::string, int, LengthCompare<std::string> > mapStrLen;

int	main()
{
	mapStrLen	map1;

	map1["a"] = 1;
	map1["ab"] = 2;
	map1["abc"] = 3;
	map1["chz"] = 4;
	map1["abcd"] = 4;

	print_map(map1);

	mapStrLen::key_compare	keycomp = map1.key_comp();

	std::cout << (keycomp("abc", "a") ? "true\n" : "false\n");
	std::cout << (keycomp("abc", "bsd") ? "true\n" : "false\n");
	std::cout << (keycomp("abc", "a12e3") ? "true\n" : "false\n");
	std::cout << (keycomp("", "") ? "true\n" : "false\n");

	mapStrLen::value_compare	valuecomp = map1.value_comp();

	test::enable_if<test::is_same<mapStrLen::value_compare::result_type, bool>::value>::type*	a1;
	(void)a1;
	test::enable_if<test::is_same<mapStrLen::value_compare::first_argument_type, mapStrLen::value_type>::value>::type*	a2;
	(void)a2;
	test::enable_if<test::is_same<mapStrLen::value_compare::second_argument_type, mapStrLen::value_type>::value>::type*	a3;
	(void)a3;

	std::cout << (valuecomp(NS::make_pair("abc", 3), NS::make_pair("1", 5)) ? "true\n" : "false\n");
	std::cout << (valuecomp(NS::make_pair("abc", -1), NS::make_pair("22", 2434)) ? "true\n" : "false\n");
	std::cout << (valuecomp(NS::make_pair("abc", 234), NS::make_pair("424", 12145)) ? "true\n" : "false\n");
	std::cout << (valuecomp(NS::make_pair("abc", -686), NS::make_pair("2323", -2343)) ? "true\n" : "false\n");
	std::cout << (valuecomp(NS::make_pair("abc", 41414123), NS::make_pair("23223", -23452)) ? "true\n" : "false\n");

	return (0);
}