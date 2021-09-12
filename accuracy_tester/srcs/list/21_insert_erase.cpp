#include "list_common.hpp"

int	main()
{
	listInt	lst1(11);

	print_all(lst1);
	fill_int(lst1, 11, -1);
	print_all(lst1);
	listInt	lst2;

	std::cout << "\n\nInsert test\n";

	listInt::iterator	ret;
	ret = lst2.insert(lst2.begin(), 42);
	std::cout << *ret << '\n';
	print_all(lst2);
	ret = lst2.insert(lst2.end(), 21);
	std::cout << *ret << '\n';
	print_all(lst2);
	listInt::iterator	it = --(--lst2.end());
	ret = lst2.insert(++lst2.begin(), 2);
	std::cout << *ret << '\n';
	print_all(lst2);
	ret = lst2.insert(it, 84);
	std::cout << *ret << '\n';
	print_all(lst2);
	lst2.insert(lst2.end(), 2, 12);
	print_all(lst2);

	lst2.insert(++(++lst2.begin()), lst1.begin(), lst1.end());
	print_all(lst2);

	std::string	str("abcd1234");
	listInt::iterator	bit = lst1.begin();
	listInt::iterator	eit = lst1.end();
	lst1.insert(lst1.end(), str.begin(), str.end());
	print_it(bit, eit);

	std::cout << "\n\nErase test\n";

	ret = lst2.erase(it++);
	std::cout << *ret << '\n';
	print_it(lst2.begin(), it);
	bit = lst1.erase(++bit);
	std::cout << *bit << '\n';
	eit = lst1.erase(--eit);
	std::cout << "Is it end?: " << (eit == lst1.end()) << '\n';
	print_it(bit, eit);
	std::cout << lst1.size() << '\n' << lst2.size() << "\n\n";

	ret = lst2.erase(lst2.begin(), it);
	std::cout << *ret << '\n';
	ret = lst1.erase(++bit, --eit);
	std::cout << *ret << '\n';
	print_all(lst2);
	print_all(lst1);
	ret = lst1.erase(lst1.begin(), lst1.end());
	std::cout << "Is it end?: " << (ret == lst1.end()) << std::endl;
	lst2.erase(lst2.begin(), lst2.end());
	print_all(lst2);
	print_all(lst1);
	return (0);
}