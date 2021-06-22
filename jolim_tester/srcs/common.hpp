#ifndef COMMON_HPP
# define COMMON_HPP

# ifndef NS
#  define NS ft
# endif

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