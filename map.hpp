#ifndef MAP_HPP
# define MAP_HPP

# include "RedBlackTree.hpp"
# include "pair.hpp"

namespace	ft
{
	template	<
		typename Key,
		typename Val,
		class Compare = less<Key>,
		class Alloc = std::allocator<pair<const Key, Val> > >
	class	map;

	template	<typename Key, typename Val>
	struct	lexical_compare;

	template	<typename Key, typename Val, class Compare, class Alloc>
	bool	operator==(map<Key, Val, Compare, Alloc> const& lhs, map<Key, Val, Compare, Alloc> const& rhs);

	template	<typename Key, typename Val, class Compare, class Alloc>
	bool	operator<(map<Key, Val, Compare, Alloc> const& lhs, map<Key, Val, Compare, Alloc> const& rhs);

	template	<class Key, class T, class Compare, class Alloc>
	void	swap(map<Key,T,Compare,Alloc>& x, map<Key,T,Compare,Alloc>& y);

	template	<typename Pair>
	class	map_iterator;

	template	<typename Key, typename Val, class Compare, class Alloc>
	class	map
	{

	public:
		typedef Key											key_type;
		typedef Val											mapped_type;
		typedef pair<const key_type, mapped_type>			value_type;
		typedef Compare										key_compare;
		typedef Alloc										allocator_type;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef map_iterator<const value_type>				const_iterator;
		typedef map_iterator<value_type>					iterator;
		typedef reverse_iterator<const_iterator>			const_reverse_iterator;
		typedef reverse_iterator<iterator>					reverse_iterator;
		typedef ptrdiff_t									difference_type;
		typedef size_t										size_type;

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
		typedef RedBlackTree<value_type, value_compare, allocator_type>	tree_type;

		tree_type	tree_;

	public:
		explicit map(
			key_compare const& comp = key_compare(),
			allocator_type const& alloc = allocator_type()):
			tree_(value_compare(comp), alloc)
		{};
		template <class InputIterator>
		map(
			InputIterator first,
			InputIterator last,
			key_compare const& comp = key_compare(),
			allocator_type const& alloc = allocator_type()):
			tree_(value_compare(comp), alloc)
		{
			tree_.insert(first, last, true);
		};
		map(map const& x):
			tree_(x.tree_)
		{};
		~map(void) {};

		iterator	begin(void)
			{ return (iterator(tree_.begin())); };
		const_iterator	begin(void) const
			{ return (const_iterator(tree_.begin())); };
		iterator	end(void)
			{ return (iterator(tree_.end())); };
		const_iterator	end(void) const
			{ return (const_iterator(tree_.end())); };
		reverse_iterator	rbegin(void)
			{ return (reverse_iterator(iterator(tree_.rbegin()))); };
		const_reverse_iterator	rbegin(void) const
			{ return (const_reverse_iterator(iterator(tree_.rbegin()))); };
		reverse_iterator	rend(void)
			{ return (reverse_iterator(iterator(tree_.rend()))); };
		const_reverse_iterator	rend(void) const
			{ return (const_reverse_iterator(iterator(tree_.rend()))); };
		bool	empty(void) const
			{ return (tree_.empty()); };
		size_type	size(void) const
			{ return (tree_.size()); };
		size_type	max_size(void) const
			{ return (tree_.max_size()); };

		mapped_type&	operator[](key_type const& k)
			{ return ((*((tree_.insert(ft::make_pair(k, mapped_type()), true)).first)).second); };

		pair<iterator,bool>	insert(value_type const& val)
		{
			pair<TreeIterator<value_type>, bool>	temp = tree_.insert(val, true);
			return (ft::make_pair(iterator(temp.first), temp.second));
		};
		iterator	insert(iterator position, value_type const& val)
			{ return (tree_.insert(position, val, true)); };
		template <class InputIterator>
		void	insert(InputIterator first, InputIterator last)
			{ tree_.insert(first, last, true); };
		void	erase(iterator position)
			{ tree_.erase(position); };
		size_type	erase(const key_type& k)
			{ return (tree_.erase(ft::make_pair(k, mapped_type()))); };
		void	erase(iterator first, iterator last)
			{ tree_.erase(first, last); };
		void	swap(map& m)
			{ this->tree_.swap(m.tree_); };
		void	clear()
			{ tree_.clear(); };

		key_compare	key_comp() const
			{ return (key_compare()); };
		value_compare	value_comp() const
			{ return (value_compare(tree_.value_comp())); };
		iterator	find(key_type const& k)
			{ return (iterator(tree_.find(ft::make_pair(k, mapped_type())))); };
		const_iterator	find(key_type const& k) const
			{ return (const_iterator(tree_.find(ft::make_pair(k, mapped_type())))); };
		size_type	count(key_type const& k) const
			{ return (tree_.count(ft::make_pair(k, mapped_type()))); };
		iterator	lower_bound(key_type const& k)
			{ return (iterator(tree_.lower_bound(make_pair(k, mapped_type())))); };
		const_iterator	lower_bound(key_type const& k) const
			{ return (const_iterator(tree_.lower_bound(make_pair(k, mapped_type())))); };
		iterator	upper_bound(key_type const& k)
			{ return (iterator(tree_.upper_bound(make_pair(k, mapped_type())))); };
		const_iterator	upper_bound(key_type const& k) const
			{ return (const_iterator(tree_.upper_bound(make_pair(k, mapped_type())))); };
		pair<iterator,iterator>	equal_range(const key_type& k)
			{ return (pair<iterator, iterator>(lower_bound(k), upper_bound(k))); };
		pair<const_iterator,const_iterator>	equal_range(const key_type& k) const
			{ return (pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k))); };

		allocator_type get_allocator() const
			{ return (allocator_type()); };

		friend bool	operator==(map const& lhs, map const& rhs)
			{ return (lhs.tree_ == rhs.tree_); };

		friend bool	operator<(map const& lhs, map const& rhs)
		{
			return (operator< <map::value_type, map::value_compare, map::allocator_type, lexical_compare<Key, Val>, false>(lhs.tree_, rhs.tree_));
		};
	};

	template	<typename Key, typename Val>
	struct	lexical_compare : public binary_function<pair<const Key, Val>, pair<const Key, Val>, bool>
	{
		bool	operator()(pair<const Key, Val> const& x, pair<const Key, Val> const& y) const
		{
			return (x.first < y.first || (x.first == y.first && x.second < y.second));
		};
	};

	template	<class Key, class T, class Compare, class Alloc>
	void	swap(map<Key,T,Compare,Alloc>& x, map<Key,T,Compare,Alloc>& y)
	{
		map<Key, T, Compare, Alloc>	temp = x;
		x = y;
		y = temp;
	};

	template	<typename Pair>
	class	map_iterator : public TreeIterator<Pair>
	{
	private:
		typedef map_iterator<Pair>		iterator_;
		typedef TreeIterator<Pair>		parent_;

	public:
		typedef typename parent_::iterator_category		iterator_category;
		typedef typename parent_::value_type			value_type;
		typedef typename parent_::reference				reference;
		typedef typename parent_::pointer				pointer;
		typedef typename parent_::difference_type		difference_type;

	protected:
		template	<typename _Pair>
		void	is_compatible(map_iterator<_Pair> const&,
		typename enable_if<is_const_same<_Pair, Pair>::value>::type* = 0) const
		{};

		map_iterator(reverse_iterator<iterator_> const& rit):
			parent_(rit)
		{};

	public:
		map_iterator(parent_ const& p):
			parent_(p) {};
		map_iterator(void):
			parent_() {};
		map_iterator(iterator_ const& iter):
			parent_(iter) {};
		template	<typename _Pair>
		map_iterator(map_iterator<_Pair> const& iter):
			parent_(iter) {};
		virtual ~map_iterator(void) {};

		iterator_&	operator=(iterator_ const& iter)
		{
			*static_cast<parent_*>(this) = static_cast<parent_>(iter);
			return (*this);
		};
		reference	operator*(void)
			{ return (*(static_cast<parent_>(*this))); };
		reference	operator*(void) const
			{ return (*(static_cast<parent_>(*this))); };
		iterator_&	operator++(void)
		{
			++(*static_cast<parent_*>(this));
			return (*this);
		};
		iterator_	operator++(int)
		{
			iterator_	temp = *this;
			++*this;
			return (temp);
		};
		iterator_&	operator--(void)
		{
			--(*static_cast<parent_*>(this));
			return (*this);
		};
		iterator_	operator--(int)
		{
			iterator_	temp = *this;
			--*this;
			return (temp);
		};
		pointer		operator->(void) const
			{ return (&(*(static_cast<parent_>(*this)))); };

		template	<typename _Tp>
		bool	operator==(map_iterator<_Tp> const& rhs) const
		{
			return (*static_cast<const parent_*>(this) == *static_cast<const TreeIterator<_Tp>*>(&rhs));
		};
	};

	template	<typename Tp>
	bool		operator==(reverse_iterator<map_iterator<Tp> > const&, map_iterator<Tp> const&)
	{ typename disable_if<is_same<Tp, Tp>::value>::type* dummy; (void)dummy; }

	template	<typename Tp>
	bool		operator==(map_iterator<Tp> const&, reverse_iterator<map_iterator<Tp> > const&)
	{ typename disable_if<is_same<Tp, Tp>::value>::type* dummy; (void)dummy; }

}

#endif