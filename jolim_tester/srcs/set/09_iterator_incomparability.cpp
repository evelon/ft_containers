#include "set_common.hpp"

int	main()
{
	std::list<int>		lsti(1);
	std::list<float>	lstf(1.1);
	setInt_o	seti(lsti.begin(), lsti.end());
	setFloat_o	setf(lstf.begin(), lstf.end());

	std::cout << (seti.begin() == *setf.begin()) << '\n';

	return (0);
}