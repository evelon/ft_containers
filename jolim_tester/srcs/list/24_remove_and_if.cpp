#include "list_common.hpp"

bool	is_negative(int n)
{
	return (n < 0);
}

bool	is_positive(int n)
{
	return (n > 0);
}

bool	is_even(int n)
{
	return (!(n % 2));
}

int	main()
{
	int array[] = {8, 13, 23, 0, -23, 144, 0, 22, 34, 96, -56, 34, 2};

	listInt	lst1(array, array + 13);

	std::cout << "before\n";
	print_all(lst1);

	std::cout << "\nremove\n";
	lst1.remove(144);
	print_all(lst1);
	lst1.remove(2);
	print_all(lst1);
	lst1.remove(8);
	print_all(lst1);

	std::cout << "\nremove_if\n";
	lst1.remove_if(is_negative);
	print_all(lst1);
	lst1.remove_if(is_even);
	print_all(lst1);
	lst1.remove_if(is_positive);
	print_all(lst1);

	return (0);
}