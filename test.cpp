#include <list>
#include <vector>
#include <iostream>
#include <memory>
#include <type_traits>


int	main()
{
	int	arr[3] = {1,2,3};

	int*	a = arr + 3;

	for (int* i = arr; i < a + 1; i++)
		std::cout << *i << std::endl;
}