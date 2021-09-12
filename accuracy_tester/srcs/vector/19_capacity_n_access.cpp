#include "vector_common.hpp"
int	main()
{
	vecInt	vec;

	std::cout << vec.empty() << vec.size() << '\n';

	vecInt::size_type	size = vec.max_size();
	(void)size;

	vec.resize(4);
	fill_int(vec, 3, 4);
	std::cout << vec.empty() << vec.size() << '\n';

	std::cout << vec.front() << '\n';
	std::cout << vec.back() << '\n';

	vec.reserve(vec.size() + 1);
	try
	{
		for (vecInt::size_type i = 0; i < vec.size(); ++i)
			vec[i] = i * 2;
		print_all(vec);
		vec[vec.size()];
		std::cout << "this should be printed\n";
		for (vecInt::size_type i = 0; i < vec.size(); ++i)
			vec.at(i) = i;
		print_all(vec);
		vec[vec.size()];
		std::cout << "this should not be printed\n";
	}
	catch(const std::out_of_range& e)
	{
		std::cerr << "out_of_range exception is thrown.\n";
	}
	try
	{
		std::cout << vec.at(-1) << '\n';
		std::cout << "this should not be printed\n";
	}
	catch(const std::out_of_range& e)
	{
		std::cerr << "out_of_range exception is thrown.\n";
	}

	while (!vec.empty())
	{
		std::cout << vec.front() << '\n';
		std::cout << vec.back() << '\n';
		vec.pop_back();
	}

	std::cout << vec.empty() << vec.size() << '\n';

	std::cout << (vec.size() < vec.capacity()) << '\n';

	vec.resize(vec.capacity());
	std::cout << (vec.size() == vec.capacity()) << '\n';

	vec.push_back(0);

	std::cout << (vec.size() < vec.capacity()) << '\n';

	vecInt::size_type	prev_cap = vec.capacity();
	vec.reserve(vec.capacity() - 1);

	std::cout << (prev_cap == vec.capacity()) << '\n';

	vec.reserve(vec.capacity() + 1);

	std::cout << (prev_cap < vec.capacity()) << '\n';

	try
	{
		vec.reserve(vec.max_size() + 1);
		std::cout << "this should not be printed\n";
	}
	catch(const std::length_error& e)
	{
		std::cerr << "length_error is thrown\n";
	}

	return (0);
}
