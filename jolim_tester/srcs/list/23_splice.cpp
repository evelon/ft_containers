#include "list_common.hpp"

int	main()
{
	listFloat	flst1(12, 0.1);
	listFloat	flst2(14, 0.232);
	fill_type(flst1, 0.3, 0.6213);

	std::cout << "\nlist1\n";
	print_all(flst1);
	std::cout << "\nlist2\n";
	print_all(flst2);

	listFloat::const_iterator	bit = flst1.begin();
	listFloat::const_iterator	eit = flst1.end();
	listFloat::const_iterator	peit = --flst1.end();

	std::cout << "\nsplice list1 to list2\n";
	flst2.splice(++(++(++flst2.begin())), flst1);

	std::cout << "\nlist1\n";
	print_all(flst1);
	std::cout << "\nlist2\n";
	print_all(flst2);
	std::cout << "\niterator validity";
	print_it(bit, peit);

	std::cout << "\nsplice list2 to list1 by a iterator\n";
	flst1.splice(flst1.end(), flst2, peit);

	std::cout << "\nlist1\n";
	print_all(flst1);
	std::cout << "\nlist2\n";
	print_all(flst2);
	std::cout << "\niterator validity";
	std::cout << "Is it begin?: " << (peit == flst1.begin()) << '\n';

	std::cout << "\nsplice list2 to list1 by two iterators\n";
	bit = ++flst2.begin();
	peit = --(--(--flst2.end()));
	flst1.splice(eit, flst2, ++flst2.begin(), --(--flst2.end()));

	std::cout << "\nlist1\n";
	print_all(flst1);
	std::cout << "\nlist2\n";
	print_all(flst2);
	std::cout << "\niterator validity";
	print_it(bit, peit);
	exit(0);
	return (0);
}