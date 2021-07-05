#include "vector_common.hpp"

int	main()
{
	vecInt	vec1(12);
	vecInt	vec2(14);

	fill_int(vec1, 2, 2);
	fill_int(vec2, 14 * 2, -2);

	vecInt::const_iterator	bit1 = vec1.begin();
	vecInt::iterator	eit1 = --vec1.end();
	vecInt::const_reverse_iterator	bit2 = ++vec2.rbegin();
	vecInt::reverse_iterator	eit2 = vec2.rend();

	std::cout << "before member-swap\n";
	print_it(bit1, eit1);
	print_all(vec1);
	print_it(bit2, eit2);
	print_all(vec2);

	vec1.swap(vec2);

	std::cout << "\nafter member swap\n";
	print_it(bit1, eit1);
	print_all(vec1);
	print_it(bit2, eit2);
	print_all(vec2);

	std::cout << "\nresize\n";
	vec1.resize(4);
	vec1.resize(6);
	vec2.resize(28, 28);

	print_all(vec1);
	print_all(vec2);

	bit1 = vec1.begin();
	eit1 = --vec1.end();
	bit2 = ++vec2.rbegin();
	eit2 = vec2.rend();

	NS::swap(vec2, vec1);
	std::cout << "after non-member swap\n";

	print_it(bit1, eit1);
	print_all(vec1);
	print_it(bit2, eit2);
	print_all(vec2);

	std::cout << "clear and some swap";

	vec1.clear();
	vec2.swap(vec1);
	print_all(vec1);
	print_all(vec2);
	vec2.swap(vec1);
	print_all(vec1);
	print_all(vec2);
	vec2.clear();
	print_all(vec1);
	print_all(vec2);
	return (0);
}