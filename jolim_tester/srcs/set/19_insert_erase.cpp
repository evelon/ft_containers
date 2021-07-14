#include "set_common.hpp"

int	main()
{
	setInt	set1;

	std::cout << "\n\nInsert test\n";

	NS::pair<setInt::iterator, bool>	ret;
	setInt::iterator					it;
	ret = set1.insert(1);
	it = ret.first;
	std::cout << "inserted?: " << ret.second << '\n';
	std::cout << *it << '\n';

	ret = set1.insert(1);
	it = ret.first;
	std::cout << "inserted?: " << ret.second << '\n';
	std::cout << *it << '\n';

	it = set1.insert(set1.begin(), 2);
	std::cout << *it << '\n';

	it = set1.insert(set1.begin(), 2);
	std::cout << *it << '\n';

	std::list<int>	lst;
	lst.push_back(3);
	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(2);
	lst.push_back(4);

	set1.insert(lst.begin(), lst.end());

	print_all(set1);

	std::cout << "\n\nErase test\n";

	setInt	set2(set1);

	it = set1.begin();
	set1.erase(it);
	print_all(set1);

	set1.erase(3);
	print_all(set1);

	set1.erase(set1.begin(), set1.end());
	print_all(set1);

	set2.erase(++set2.begin(), --set2.end());
	print_all(set2);

	return (0);
}