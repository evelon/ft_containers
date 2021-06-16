#ifndef RELATIONAL_OPERATOR_IMPL_HPP
# define RELATIONAL_OPERATOR_IMPL_HPP

namespace	ft
{
	// operator "<" and operator "==" defines everything else

	template	<typename T>
	bool	operator!=(T const& l, T const& r)
		{ return (!(l == r)); }

	template	<typename T>
	bool	operator<=(T const& l, T const& r)
		{ return (!(r < l)); }

	template	<typename T>
	bool	operator>(T const& l, T const& r)
		{ return (r < l); }

	template	<typename T>
	bool	operator>=(T const& l, T const& r)
		{ return !(l < r); }

	template	<typename T, typename U>
	bool	operator!=(T const& l, U const& r)
		{ return (!(l == r)); }

	template	<typename T, typename U>
	bool	operator<=(T const& l, U const& r)
		{ return (!(r < l)); }

	template	<typename T, typename U>
	bool	operator>(T const& l, U const& r)
		{ return (r < l); }

	template	<typename T, typename U>
	bool	operator>=(T const& l, U const& r)
		{ return !(l < r); }
}

#endif