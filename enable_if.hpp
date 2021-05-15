namespace ft
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
	struct	is_integral<char16_t>
	{ static const bool	value = true; };

	template	<>
	struct	is_integral<char32_t>
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
}