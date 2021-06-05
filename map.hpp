#ifndef MAP_HPP
# define MAP_HPP

# include <memory>
# include "pair.hpp"
# include "reverse_iterator.hpp"

#include <map>

namespace	ft
{
	template	<typename Key,
		typename Val,
		class Compare = less<Key>,
		class Alloc = std::allocator<pair<const Key, Val> > >
	class	map;

	template	<typename Key, typename Val, class Compare, class Alloc>
	class	map
	{

	public:
		typedef Key									key_type;
		typedef Val									mapped_type;
		typedef pair<const key_type, mapped_type>	value_type;
		typedef Compare								key_compare;
		typedef Alloc								allocator_type;
		typedef allocator_type::reference			reference;
		typedef allocator_type::const_reference		const_reference;
		typedef allocator_type::pointer				pointer;
		typedef allocator_type::const_pointer		const_pointer;
		// typedef ~ iterator;
		// typedef ~ const_iterator;
		// typedef reverse_iterator<iterator>			reverse_iterator;
		// typedef reverse_iterator<const_iterator>	const_reverse_iterator;

		class	value_compare : public binary_function<value_type, value_type, bool>
		{
		private:
			friend class	map;

		protected:
			Compare	comp;
			value_compare(Compare c): comp(c) {};

		public:
			bool	operator()(value_type const& x, value_type const& y) const
			{ return comp(x.first, y.first); }
		};
	};
}

#endif