#ifndef MAP_HPP
# define MAP_HPP

# include "RedBlackTree.hpp"

namespace	ft
{
	template	<typename Key,
		typename Val,
		class Compare = less<Key>,
		class Alloc = std::allocator<pair<const Key, Val> > >
	class	map;

	template	<typename Key, typename Val, class Compare, class Alloc>
	bool	operator==(map<Key, Val, Compare, Alloc> const& lhs, map<Key, Val, Compare, Alloc> const& rhs);

	template	<typename Key, typename Val, class Compare, class Alloc>
	bool	operator<(map<Key, Val, Compare, Alloc> const& lhs, map<Key, Val, Compare, Alloc> const& rhs);

	template	<typename Key, typename Val>
	class	map_iterator;

	template	<typename Key, typename Val, class Compare, class Alloc>
	class	map
	{

	public:
		typedef Key												key_type;
		typedef Val												mapped_type;
		typedef pair<const key_type, mapped_type>				value_type;
		typedef Compare											key_compare;
		typedef Alloc											allocator_type;
		typedef typename allocator_type::reference				reference;
		typedef typename allocator_type::const_reference		const_reference;
		typedef typename allocator_type::pointer				pointer;
		typedef typename allocator_type::const_pointer			const_pointer;
		typedef map_iterator<const key_type, const value_type>	const_iterator;
		typedef map_iterator<key_type, value_type>				iterator;
		typedef reverse_iterator<const_iterator>				const_reverse_iterator;
		typedef reverse_iterator<iterator>						reverse_iterator;
		typedef ptrdiff_t										difference_type;
		typedef size_t											size_type;

		class	value_compare : public binary_function<value_type, value_type, bool>
		{
		private:
			friend class	map;

		protected:
			Compare	comp;
			value_compare(Compare c): comp(c) {};

		public:
			bool	operator()(value_type const& x, value_type const& y) const
			{ return (comp(x.first, y.first)); };
		};

		private:
			RedBlackTree<value_type, key_compare, allocator_type>	tree;

		explicit map(
			const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type())
		{

		};
	};
}

#endif