#ifndef LIST_HPP
# define LIST_HPP

# include <memory>
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
		typedef DoublyLinkedNode	node;

		node			blank_node;
		allocator_type	allocator;
		size_type		size;

		list(void);

	public:
		typedef Tp										Value_type;
		typedef Alloc<Tp>								allocator_type;
		typedef typename Alloc<Tp>::reference			reference;
		typedef typename Alloc<Tp>::const_reference		const_reference;
		typedef typename Alloc<Tp>::pointer				pointer;
		typedef typename Alloc<Tp>::const_pointer		const_pointer;
		typedef list_iterator<Tp, Node>					iterator;
		typedef list_iterator<const Tp, Node>			const_iterator;
		typedef list_reverse_iterator<Tp, Node>			reverse_iterator;
		typedef list_reverse_iterator<const Tp, Node>	const_reverse_iterator;
		typedef ptrdiff_t								difference_type;
		typedef size_t									size_type;

		// Default constructor. Construct list with an allocator instance "alloc"
		explicit list(const allocator_type& alloc = allocator_type()):
			blank_node(), allocator(alloc), size(0)
		{};
		// Fill constructor. Construct list with "n" number of values of "val", with an allocator instance "alloc"
		explicit list(
			size_type n,
			const value_type& val = value_type(),
			const allocator_type& alloc = allocator_type()):
			blank_node(), allocator(alloc), size(n)
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
		iterator		begin(void);
		// Returns an const iterator pointing to the first element in the list container.
		const_iterator	begin(void) const;

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

		// Range assign. Assigns new contents to the list container, replacing its current contents, and modifying its size accordingly. \
		// The new contents are elements constructed from each of the elements in the range between "first" and "last", in the same order.
		template	<class InputIterator>
		void	assign(InputIterator first, InputIterator last);
		// Fill assign. Assigns new contents to the list container, replacing its current contents, and modifying its size accordingly. \
		// The new contents are "n" elements, each initialized to a copy of "val".
		void	assign(size_type n, const value_type& val);

		// Inserts a new element at the beginning of the list, right before its current first element, effectively increasing its size by one.
		void	push_front(const value_type& val);
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
		template <class InputIterator>
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

	};
}

#endif
