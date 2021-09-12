#include "set_common.hpp"
#include <memory>
#include <list>

int	main()
{
	std::list<int>	std_list1(3);
	std::list<int>	std_list2;
	std_list2.push_back(1);
	std_list2.push_back(2);
	std_list2.push_back(3);

	setInt	a1;
	setInt	a2((setInt::key_compare()), (std::allocator<int>()));
	setInt	a3((setInt::value_compare()), (std::allocator<int>()));
	setInt	a4(++(++std_list1.begin()), --(std_list1.end()), (setInt::key_compare()), (std::allocator<int>()));
	setInt	a5(++(++std_list2.begin()), --(std_list2.end()), (setInt::key_compare()));
	setInt	a6(std_list2.begin(), std_list2.end());
	setInt	b1(a1);
	setInt	b2(a2);
	setInt	b3(a3);
	setInt	b4(a4);
	setInt	b5(a5);
	setInt	b6(a6);
	setInt	c1(b1);
	setInt	c2(b2);
	setInt	c3(b3);
	setInt	c4(b4);
	setInt	c5(b5);
	setInt	c6(b6);

	print_all(c1);
	print_all(c2);
	print_all(c3);
	print_all(c4);
	print_all(c5);
	print_all(c6);

	return (0);
}