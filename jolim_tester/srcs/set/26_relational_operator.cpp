#include "set_common.hpp"

int	main()
{
	setInt	set1;
	compare_all(set1, set1);

	setInt	set2;
	compare_all(set2, set2);

	set1.insert(1);
	compare_all(set1, set2);

	set2.insert(1);
	compare_all(set1, set2);

	set1.insert(2);
	compare_all(set1, set2);

	set2.insert(2);
	compare_all(set1, set2);

	set1.insert(3);
	set2.insert(4);
	compare_all(set1, set2);

	return (0);
}