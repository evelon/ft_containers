#ifndef COMMON_HPP
# define COMMON_HPP

# include <iostream>
# include <string>

# define FT 0
# define STD 1

# ifndef NAMESPACE
#  define NAMESPACE FT
# endif

# if NAMESPACE == FT
#  define NS ft
# else
#  define NS std
# endif

template	<class It, class _It>
void	print_it(It first, _It last)
{
	for (It it = first; it != last; ++it)
		std::cout << *it << '\n';
}

template	<class Container>
void	print_all(Container cont)
{
	print_it(cont.begin(), cont.end());
}

template	<class Container>
void	fill_int(Container& cont, int first, int diff)
{
	for (typename Container::iterator it = cont.begin(); it != cont.end(); ++it)
	{
		*it = first;
		first += diff;
	}
}

class	A {};

namespace	test
{
	template	<bool B, typename T = void>
	struct	enable_if
	{};

	template	<typename T>
	struct	enable_if<true, T>
	{ typedef T	type; };

	template	<typename T, typename U>
	struct	is_same
	{ static const bool value = false; };

	template	<typename T>
	struct	is_same<T, T>
	{ static const bool value = true; };
}

#endif