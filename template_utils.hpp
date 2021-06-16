#ifndef TEMPLATE_UTILS_HPP
# define TEMPLATE_UTILS_HPP

# include <stddef.h>

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

	// Or operation
	template	<bool A, bool B>
	struct	_or
	{ static const bool	value = true; };

	template	<>
	struct	_or<false, false>
	{ static const bool	value = false; };

	template	<bool B>
	struct	_not
	{ static const bool value = true; };

	template	<>
	struct	_not<true>
	{ static const bool value = false; };

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

	// "type" will be "Then" if the "If" is true, else then "Else"
	template	<bool If, typename Then, typename Else>
	struct	conditional
	{ typedef Then	type; };

	template	<typename Then, typename Else>
	struct	conditional<false, Then, Else>
	{ typedef Else	type; };

	template	<size_t Num , size_t Base>
	struct	logarithm
	{ static const size_t	value = 1 + logarithm<Num / Base, Base>::value; };

	template	<size_t Base>
	struct	logarithm<Base, Base>
	{ static const size_t	value = 1; };

	template	<size_t Base>
	struct	logarithm<1, Base>
	{ static const size_t	value = 0; };

	template	<size_t Base>
	struct	logarithm<0, Base>
	{ static const size_t	value = 0; };

	// define a template binary function
	template	<typename Arg1, typename Arg2, typename Result>
	struct	binary_function
	{
		typedef Arg1	first_argument_type;
		typedef Arg2	second_argument_type;
		typedef Result	result_type;
	};

	// using an operator (), it returns the operation of the operator "<".
	template	<typename Tp = void>
	struct	less : public binary_function<Tp, Tp, bool>
	{
		bool	operator()(Tp const& x, Tp const& y) const
			{ return (x < y); };
	};

	// has type if N is B is true
	template	<typename N, bool B>
	struct	type_reflection
	{};

	template	<typename N>
	struct	type_reflection<N, true>
	{ typedef N	type; };
}
#endif
