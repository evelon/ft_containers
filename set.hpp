#ifndef SET_HPP
# define SET_HPP

# include "RedBlackTree.hpp"
# include "pair.hpp"

namespace	ft
{
	template	<
		typename T,
		class Compare = less<T>,
		class Alloc = std::allocator<T> >
	class	set;

	template	<typename T, class Compare, class Alloc>
	bool	operator==(set<T, Compare, Alloc> const& lhs, set<T, Compare, Alloc> const& rhs);

	template	<typename T, class Compare, class Alloc>
	bool	operator<(set<T, Compare, Alloc> const& lhs, set<T, Compare, Alloc> const& rhs);

	template <typename T, class Compare, class Alloc>
	void	swap(set<T, Compare, Alloc>& x, set<T, Compare, Alloc>& y);

	template	<typename T>
	class	set_iterator;

	template	<typename T, class Compare, class Alloc>
	class	set
	{

	public:
		typedef T											key_type;
		typedef T											value_type;
		typedef Compare										key_compare;
		typedef Compare										value_compare;
		typedef Alloc										allocator_type;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef set_iterator<const value_type>				const_iterator;
		typedef set_iterator<const value_type>				iterator;
		typedef reverse_iterator<const_iterator>			const_reverse_iterator;
		typedef reverse_iterator<iterator>					reverse_iterator;
		typedef ptrdiff_t									difference_type;
		typedef size_t										size_type;

	private:
		typedef RedBlackTree<value_type, value_compare, allocator_type>	tree_type;

		tree_type	tree_;

	public:
		explicit set(
			key_compare const& comp = key_compare(),
			allocator_type const& alloc = allocator_type()):
			tree_(value_compare(comp), alloc)
		{};
		template <class InputIterator>
		set(
			InputIterator first,
			InputIterator last,
			key_compare const& comp = key_compare(),
			allocator_type const& alloc = allocator_type()):
			tree_(value_compare(comp), alloc)
		{
			tree_.insert(first, last, true);
		};
		set(set const& x):
			tree_(x.tree_)
		{};
		~set(void) {};

		iterator	begin(void)
			{ return (iterator(tree_.begin())); };
		const_iterator	begin(void) const
			{ return (const_iterator(tree_.begin())); };
		iterator	end(void)
			{ return (iterator(tree_.end())); };
		const_iterator	end(void) const
			{ return (const_iterator(tree_.end())); };
		reverse_iterator	rbegin(void)
			{ return (reverse_iterator(iterator(tree_.end()))); };
		const_reverse_iterator	rbegin(void) const
			{ return (const_reverse_iterator(iterator(tree_.end()))); };
		reverse_iterator	rend(void)
			{ return (reverse_iterator(iterator(tree_.begin()))); };
		const_reverse_iterator	rend(void) const
			{ return (const_reverse_iterator(iterator(tree_.begin()))); };
		bool	empty(void) const
			{ return (tree_.empty()); };
		size_type	size(void) const
			{ return (tree_.size()); };
		size_type	max_size(void) const
			{ return (tree_.max_size()); };

		pair<iterator,bool>	insert(value_type const& val)
		{
			pair<TreeIterator<value_type>, bool>	temp = tree_.insert(val, true);
			return (ft::make_pair(iterator(temp.first), temp.second));
		};
		iterator	insert(iterator position, value_type const& val)
			{ return (set_iterator<value_type>(tree_.insert(position, val, true))); };
		template <class InputIterator>
		void	insert(InputIterator first, InputIterator last)
			{ tree_.insert(first, last, true); };
		void	erase(iterator position)
			{ tree_.erase(position); };
		size_type	erase(const key_type& k)
			{ return (tree_.erase(k)); };
		void	erase(iterator first, iterator last)
			{ tree_.erase(first, last); };
		void	swap(set& m)
			{ this->tree_.swap(m.tree_); };
		void	clear()
			{ tree_.clear(); };

		key_compare	key_comp() const
			{ return (key_compare()); };
		value_compare	value_comp() const
			{ return (value_compare()); };
		iterator	find(key_type const& k)
			{ return (iterator(tree_.find(k))); };
		const_iterator	find(key_type const& k) const
			{ return (const_iterator(tree_.find(k))); };
		size_type	count(key_type const& k) const
			{ return (tree_.count(k)); };
		iterator	lower_bound(key_type const& k)
			{ return (iterator(tree_.lower_bound(k))); };
		const_iterator	lower_bound(key_type const& k) const
			{ return (const_iterator(tree_.lower_bound(k))); };
		iterator	upper_bound(key_type const& k)
			{ return (iterator(tree_.upper_bound(k))); };
		const_iterator	upper_bound(key_type const& k) const
			{ return (const_iterator(tree_.upper_bound(k))); };
		pair<iterator,iterator>	equal_range(const key_type& k)
			{ return (pair<iterator, iterator>(lower_bound(k), upper_bound(k))); };
		pair<const_iterator,const_iterator>	equal_range(const key_type& k) const
			{ return (pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k))); };

		allocator_type get_allocator() const
			{ return (allocator_type()); };

		friend bool	operator==(set const& lhs, set const& rhs)
			{ return (lhs.tree_ == rhs.tree_); };

		friend bool	operator<(set const& lhs, set const& rhs)
		{
			return (operator< <set::value_type, set::value_compare, set::allocator_type, value_compare, false>(lhs.tree_, rhs.tree_));
		};
	};

	template	<typename T, class Compare, class Alloc>
	void	swap(set<T, Compare, Alloc>& x, set<T, Compare, Alloc>& y)
	{
		set<T, Compare, Alloc>	temp = x;
		x = y;
		y = temp;
	};

	template	<typename T>
	class	set_iterator : public TreeIterator<T>
	{
	private:
		typedef set_iterator<T>		iterator_;
		typedef TreeIterator<T>		parent_;

	public:
		typedef typename parent_::iterator_category		iterator_category;
		typedef typename parent_::value_type			value_type;
		typedef typename parent_::reference				reference;
		typedef typename parent_::pointer				pointer;
		typedef typename parent_::difference_type		difference_type;

	protected:
		template	<typename _T>
		void	is_compatible(set_iterator<_T> const&,
		typename enable_if<is_const_same<_T, T>::value>::type* = 0) const
		{};

		set_iterator(reverse_iterator<iterator_> const& rit):
			parent_(rit)
		{};

	public:
		set_iterator(parent_ const& p):
			parent_(p) {};
		set_iterator(void):
			parent_() {};
		set_iterator(iterator_ const& iter):
			parent_(iter) {};
		template	<typename _T>
		set_iterator(set_iterator<_T> const& iter):
			parent_(iter) {};
		virtual ~set_iterator(void) {};

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
		bool	operator==(set_iterator<_Tp> const& rhs) const
		{
			return (*static_cast<const parent_*>(this) == *static_cast<const TreeIterator<_Tp>*>(&rhs));
		};
	};

	template	<typename Tp>
	bool		operator==(reverse_iterator<set_iterator<Tp> > const&, set_iterator<Tp> const&)
	{ typename disable_if<is_same<Tp, Tp>::value>::type* dummy; (void)dummy; }

	template	<typename Tp>
	bool		operator==(set_iterator<Tp> const&, reverse_iterator<set_iterator<Tp> > const&)
	{ typename disable_if<is_same<Tp, Tp>::value>::type* dummy; (void)dummy; }

}

#endif