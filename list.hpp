#ifndef LIST_HPP
# define LIST_HPP

# include <memory>
# include "enable_if.hpp"
# include "DoublyLinkedNode.hpp"
# include "list_iterator.hpp"
# include "list_reverse_iterator.hpp"

namespace ft
{
	template	<typename Tp, class Alloc = std::allocator<Tp> >
	class	list;

	template	<typename Tp, class Alloc>
	class	list
	{
	private:
		typedef DoublyLinkedNode<Tp, Alloc>						node;
		typedef typename Alloc::template rebind<node>::other	node_allocator_type;

	public:
		typedef Tp										Value_type;
		typedef Alloc									allocator_type;
		typedef typename Alloc::reference				reference;
		typedef typename Alloc::const_reference			const_reference;
		typedef typename Alloc::pointer					pointer;
		typedef typename Alloc::const_pointer			const_pointer;
		typedef list_iterator<Tp, node>					iterator;
		typedef list_iterator<const Tp, node>			const_iterator;
		typedef list_reverse_iterator<Tp, node>			reverse_iterator;
		typedef list_reverse_iterator<const Tp, node>	const_reverse_iterator;
		typedef ptrdiff_t								difference_type;
		typedef size_t									size_type;

	private:
		node*				blank_node;
		allocator_type		allocator;
		node_allocator_type	node_allocator;
		size_type			size;

		list(void);

	public:
		// Default constructor. Construct list with an allocator instance "alloc"
		explicit list(const allocator_type& alloc = allocator_type()):
			allocator(alloc), node_allocator(alloc::rebind<node>::other()), size(0)
		{
			blank_node = node_allocator.allocate(1);
			blank_node = node_allocator.construct(node());
		};
		// Fill constructor. Construct list with "n" number of values of "val", with an allocator instance "alloc"
		explicit list(
			size_type n,
			const value_type& val = value_type(),
			const allocator_type& alloc = allocator_type()):
			allocator(alloc), size(n)
		{
			for (int i = 0; i < n; i++)
			{

			}
		};
		// Range constructor. Construct list in range from "first" to "last", with an allocator instance "alloc"
		template	<class InputIterator>
		list(
			InputIterator first,
			InputIterator last,
			const allocator_type& alloc = allocator_type())
		{};
		// Copy constructor. Construct list by copying the list "lst".
		list(const list& lst)
		{};

		// List destructor
		~list(void)
		{};

		// Assign content
		list&	operator=(const list& lst);

		// Returns an iterator pointing to the first element in the list container.
		iterator		begin(void)
		{
			return (iterator(blank_node->next));
		};
		// Returns an const iterator pointing to the first element in the list container.
		const_iterator	begin(void) const
		{
			return (iterator(blank_node->next));
		};

		// Returns an iterator referring to the past-the-end element in the list container.
		iterator		end(void);
		// Returns an const iterator referring to the past-the-end element in the list container.
		const_iterator	begin(void) const;

		// Returns a reverse iterator pointing to the last element in the container.
		reverse_iterator		rbegin(void);
		// Returns a const reverse iterator pointing to the last element in the container.
		const_reverse_iterator	rbegin(void);

		// Returns a reverse iterator pointing to the element preceding the first element in the list container.
		reverse_iterator		rend(void);
		// Returns a const reverse iterator pointing to the element preceding the first element in the list container.
		const_reverse_iterator	rend(void) const;

		// Returns whether the list container is empty.
		bool			empty(void) const;
		// Returns the number of elements in the list container.
		size_type		size(void) const;
		// Returns the maximum number of elements that the list container can hold.
		size_type		max_size(void) const;

		// Returns a reference to the first element in the list container.
		reference		front(void);
		// Returns a const reference to the first element in the list container.
		const_reference	front(void) const;

		// Returns a reference to the last element in the list container.
		reference		back(void);
		// Returns a const reference to the last element in the list container.
		const_reference	back(void) const;

		// Range assign. Assigns new contents to the list container, replacing its current contents, and modifying its size accordingly. The new contents are elements constructed from each of the elements in the range between "first" and "last", in the same order.
		template	<class InputIterator>
		void	assign(InputIterator first, InputIterator last);
		// Fill assign. Assigns new contents to the list container, replacing its current contents, and modifying its size accordingly. The new contents are "n" elements, each initialized to a copy of "val".
		template	<typename N, typename ft::enable_if<ft::is_integral<N>::value>::type>
		void	assign(size_type n, const value_type& val);

		// Inserts a new element at the beginning of the list, right before its current first element, effectively increasing its size by one.
		void	push_front(const value_type& val)
		{ blank_node};
		// Removes the first element in the list container, effectively reducing its size by one.
		void	pop_front(void);
		// Adds a new element at the end of the list container, after its current last element, effectively increasing the container size by one.
		void	push_back(const value_type& val);
		// Removes the last element in the list container, effectively reducing the container size by one.
		void	pop_back(void);

		// Single element insert. The container is extended by inserting a new element "val", before the element at the specified "position".
		iterator insert	(iterator position, const value_type& val);
		// Fill insert. The container is extended by inserting new elements containing "val", before the element at the specified "position".
		void	insert(iterator position, size_type n, const value_type& val);
		// Range insert. The container is extended by inserting new elements rangin from "first" to "last", before the element at the specified "position".
		template	<class InputIterator>
		void insert(iterator position, InputIterator first, InputIterator last);

		// Removes from the list container either an element, "position".
		iterator erase (iterator position);
		// Removes from the list container either a range of elements [first,last).
		iterator erase (iterator first, iterator last);

		// Exchanges the content of the container by the content of "lst", which is another list of the same type. Sizes may differ.
		void	swap(list& lst);

		// Resizes the container so that it contains "n" elements.
		void	resize(size_type n, value_type val = value_type());
		// Removes all elements from the list container (which are destroyed), and leaving the container with a size of 0.
		void	clear(void);

		// Splice entire list. Transfers all the elements of x into the container, inserting them at position.
		void	splice(iterator position, list& x);
		// Splice a single element. Transfers only the element pointed by i from x into the container, inserting them at position.
		void	splice(iterator position, list& x, iterator i);
		// Splice a range of elements. Transfers the range [first,last) from x into the container, inserting them at position
		void	splice(iterator position, list& x, iterator first, iterator last);

		// Removes from the container all the elements that compare equal to "val".
		void	remove(const value_type& val);
		// Removes from the container all the elements for which "Predicate pred" returns true.
		template	<class Predicate>
		void	remove_if(Predicate pred);

		// Removes all but the first element from every consecutive group of equal elements in the container. An element is only removed from the list container if it compares equal to the element immediately preceding it.
		void	unique(void);
		// Removes all elements that makes "BinaryPredicate binary_pred" return true in the container. An alement will be compared to a preceding element by "biniary_pred".
		template	<class BinaryPredicate>
		void	unique(BinaryPredicate binary_pred);

		// Merges x into the list by transferring all of its elements at their respective ordered positions into the container (both containers shall already be ordered).
		void	merge(list& lst);
		// Merges x into the list by transferring all of its elements at their respective ordered positions into the container (both containers shall already be ordered). Binary predicate "comp" shall be a function pointer or a function object.
		template	<class Compare>
		void	merge(list& x, Compare comp);

		// Sorts the elements in the list by applying an algorithm that uses "operator<", altering their position within the container.
		void sort(void);
		// Sorts the elements in the list by applying an algorithm that uses "comp", altering their position within the container.
		template	<class Compare>
		void	sort (Compare comp);

		// Reverses the order of the elements in the list container.
		void	reverse(void);

	};
}

#endif
