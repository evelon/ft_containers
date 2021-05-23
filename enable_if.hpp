#ifndef ENABLE_IF_HPP
# define ENABLE_IF_HPP

namespace	ft
{
	// enable_if has a type "type" if bool "B" is true.
	template	<bool B, typename T = void>
	struct	enable_if
	{};

	template	<typename T>
	struct	enable_if<true, T>
	{ typedef T	type; };

	// disable_if has a type "type" if bool "B" is false.
	template	<bool B, typename T = void>
	struct	disable_if
	{ typedef T	type; };

	template	<typename T>
	struct	disable_if<true, T>
	{};

	// And operation
	template	<bool A, bool B>
	struct	_and
	{ static const bool	value = false; };

	template	<>
	struct	_and<true, true>
	{ static const bool	value = false; };

	// If a typename "N" is interal type, the member variable "value" is true.
	template	<typename N>
	struct	is_integral
	{ static const bool	value = false; };

	template	<>
	struct	is_integral<bool>
	{ static const bool	value = true; };

	template	<>
	struct	is_integral<char>
	{ static const bool	value = true; };

	template	<>
	struct	is_integral<signed char>
	{ static const bool	value = true; };

	template	<>
	struct	is_integral<unsigned char>
	{ static const bool	value = true; };

	template	<>
	struct	is_integral<wchar_t>
	{ static const bool	value = true; };

	template	<>
	struct	is_integral<short>
	{ static const bool	value = true; };

	template	<>
	struct	is_integral<unsigned short>
	{ static const bool	value = true; };

	template	<>
	struct	is_integral<int>
	{ static const bool	value = true; };

	template	<>
	struct	is_integral<unsigned int>
	{ static const bool	value = true; };

	template	<>
	struct	is_integral<long>
	{ static const bool	value = true; };

	template	<>
	struct	is_integral<unsigned long>
	{ static const bool	value = true; };

	template	<>
	struct	is_integral<long long>
	{ static const bool	value = true; };

	template	<>
	struct	is_integral<unsigned long long>
	{ static const bool	value = true; };

	template	<>
	struct	is_integral<__int128_t>
	{ static const bool	value = true; };

	template	<>
	struct	is_integral<__uint128_t>
	{ static const bool	value = true; };

	// If the second type is const of the first type, value is true.
	template	<typename T, typename U>
	struct	is_const_of
	{ static const bool	value = false; };

	template	<typename T>
	struct	is_const_of<T, const T>
	{ static const bool	value = true; };

	// value is true if a type is const.
	template	<typename T>
	struct	is_const
	{ static const bool	value = false; };

	template	<typename T>
	struct	is_const<const T>
	{ static const bool	value = true; };

	// value is true if a type is not const.
	template	<typename T>
	struct	is_not_const
	{ static const bool	value = true; };

	template	<typename T>
	struct	is_not_const<const T>
	{ static const bool	value = false; };


	// value is true if two types are same.
	template	<typename T, typename U>
	struct	is_same
	{ static const bool value = false; };

	template	<typename T>
	struct	is_same<T, T>
	{ static const bool value = true; };

	// value is true if two types are same, not taking into const
	template	<typename T, typename U>
	struct	is_const_same
	{ static const bool	value = false; };

	template	<typename T>
	struct	is_const_same<T, const T>
	{ static const bool	value = true; };

	template	<typename T>
	struct	is_const_same<const T, T>
	{ static const bool	value = true; };

	template	<typename T>
	struct	is_const_same<T, T>
	{ static const bool	value = true; };
}
#endif
