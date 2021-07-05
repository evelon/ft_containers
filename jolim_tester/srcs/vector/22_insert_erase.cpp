#include "vector_common.hpp"

int	main()
{
	vecInt	vec1(11);

	print_all(vec1);
	fill_int(vec1, 11, -1);
	print_all(vec1);
	vecInt	vec2;

	std::cout << "\n\nInsert test\n";

	vecInt::iterator	ret;
	ret = vec2.insert(vec2.begin(), 42);
	std::cout << *ret << '\n';
	print_all(vec2);
	ret = vec2.insert(vec2.end(), 21);
	std::cout << *ret << '\n';
	print_all(vec2);
	ret = vec2.insert(++vec2.begin(), 2);
	std::cout << *ret << '\n';
	print_all(vec2);
	ret = vec2.insert(--(--(--vec2.end())), 84);
	std::cout << *ret << '\n';
	print_all(vec2);
	vec2.insert(vec2.end(), 2, 12);
	print_all(vec2);

	vec2.insert(++(++vec2.begin()), vec1.begin(), vec1.end());
	print_all(vec2);

	std::string	str("abcd1234");
	vec1.insert(vec1.end(), str.begin(), str.end());
	vecInt::iterator	bit = vec1.begin();
	vecInt::iterator	eit = vec1.end();
	print_it(bit, eit);

	std::cout << "\n\nErase test\n";

	vecInt::iterator	it = --(--(--vec2.end()));
	ret = vec2.erase(it++);
	std::cout << *ret << '\n';
	print_it(vec2.begin(), it);
	bit = vec1.erase(++bit);
	std::cout << *bit << '\n';
	std::cout << vec1.size() << '\n' << vec2.size() << "\n\n";

	ret = vec2.erase(vec2.begin(), it);
	std::cout << *ret << '\n';
	ret = vec1.erase(++vec1.begin(), --vec1.end());
	std::cout << *ret << '\n';
	print_all(vec2);
	print_all(vec1);
	ret = vec1.erase(vec1.begin(), vec1.end());
	std::cout << "Is it end?: " << (ret == vec1.end()) << std::endl;
	vec2.erase(vec2.begin(), vec2.end());
	print_all(vec2);
	print_all(vec1);
	return (0);
}