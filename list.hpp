#ifndef LIST_HPP
# define LIST_HPP

# include <memory>
# include "enable_if.hpp"
# include "DoublyLinkedNode.hpp"
# include "list_iterator.hpp"
# include "base_reverse_iterator.hpp"

# include <unistd.h>

namespace ft
{
	template	<typename Tp, class Alloc = std::allocator<Tp> >
	class	list;

	template	<typename Tp, class Alloc>
	class	list
	{
	private:
		typedef DoublyLinkedNode<Tp, Alloc>						node;
		typedef typename Alloc::template rebind<node>::other	node_allocator;

	public:
		typedef Tp										value_type;
		typedef Alloc									allocator_type;
		typedef typename Alloc::reference				reference;
		typedef typename Alloc::const_reference			const_reference;
		typedef typename Alloc::pointer					pointer;
		typedef typename Alloc::const_pointer			const_pointer;
		typedef list_iterator<Tp, node>					iterator;
		typedef list_iterator<const Tp, node>			const_iterator;
		typedef base_reverse_iterator<iterator>			reverse_iterator;
		typedef base_reverse_iterator<const_iterator>	const_reverse_iterator;
		typedef ptrdiff_t								difference_type;
		typedef size_t									size_type;

	private:
		allocator_type	allocator;
		node_allocator	node_alloc;
		node*			blank_node;
		size_type		list_size;

		size_type	node_alloc_max_size() const
		{
			size_type	node_max = node_alloc.max_size();
			size_type	type_max = std::numeric_limits<difference_type>::max();
			if (node_max > type_max)
				return (type_max);
			return (node_max);
		}

		// Find a node corresponding to an iterator "position". "ret_node" becomes the result value.
		iterator	find_node(iterator position, node*& ret_node)
		{
			ret_node = blank_node->getNext();
			iterator	it = this->begin();
			size_type	i = 0;
			while (it != position)
			{
				if (i > list_size || it == this->end())
					return (this->end());
				ret_node = ret_node->getNext();
				it++;
				i++;
			}
			return (it);
		}

	public:
		// Default constructor. Construct list with an allocator instance "alloc"
		explicit list(const allocator_type& alloc = allocator_type()):
			allocator(alloc),
			node_alloc(),
			blank_node(node_alloc.allocate(1)),
			list_size(0)
		{ node_alloc.construct(blank_node, *blank_node); };
		// Fill constructor. Construct list with "n" number of values of "val", with an allocator instance "alloc"
		explicit list(
			size_type n,
			const value_type& val = value_type(),
			const allocator_type& alloc = allocator_type()):
			allocator(alloc),
			node_alloc(),
			blank_node(node_alloc.allocate(1)),
			list_size(0)
		{
			node_alloc.construct(blank_node, *blank_node);
			for (size_type i = 0; i < n; i++)
				push_back(val);
		};
		// Range constructor. Construct list in range from "first" to "last", with an allocator instance "alloc"
		template	<class InputIterator>
		list(
			InputIterator first,
			InputIterator last,
			const allocator_type& alloc = allocator_type(),
			typename ft::disable_if<is_integral<InputIterator>::value>::type* = 0):
			allocator(alloc),
			node_alloc(),
			blank_node(node_alloc.allocate(1)),
			list_size(0)
		{
			node_alloc.construct(blank_node, *blank_node);
			for (; first != last; first++)
				push_back(*first);
		};
		// Copy constructor. Construct list by copying the list "lst".
		list(const list& lst):
			allocator(lst.allocator),
			node_alloc(lst.node_alloc),
			blank_node(node_alloc.allocate(1)),
			list_size(0)
		{
			node_alloc.construct(blank_node, *blank_node);
			for (const_iterator it = lst.begin(); it != lst.end(); it++)
				push_back(*it);
		};

		// List destructor
		~list(void)
		{
			node*	temp;
			while (blank_node->getNext() != blank_node)
			{
				temp = blank_node->getPrev();
				node_alloc.destroy(temp);
				node_alloc.deallocate(temp, 1);
			}
			node_alloc.destroy(blank_node);
			node_alloc.deallocate(blank_node, 1);
		};

		// Assign content
		list&	operator=(const list& lst)
		{
			node*	cur_node = this->blank_node->getNext();
			if (lst.size() <= this->list_size)
			{
				for (const_iterator it = lst.begin(); it != lst.end(); it++)
				{
					cur_node->setContent(*it);
					cur_node = cur_node->getNext();
				}
				node*	temp;
				while (cur_node != this->blank_node)
				{
					temp = cur_node->getNext();
					this->node_alloc.destroy(cur_node);
					this->node_alloc.deallocate(cur_node, 1);
					cur_node = temp;
				}
			}
			else
			{
				const_iterator it;
				for (it = lst.begin(); cur_node != this->blank_node; it++)
				{
					cur_node->setContent(*it);
					cur_node = cur_node->getNext();
				}
				for (; it != lst.end(); it++)
					push_back(*it);
			}
			this->list_size = lst.size();
			return (*this);
		}

		// Returns an iterator pointing to the first element in the list container.
		iterator		begin(void)
			{ return (iterator(blank_node->getNext())); };
		// Returns an const iterator pointing to the first element in the list container.
		const_iterator	begin(void) const
			{ return (const_iterator(blank_node->getNext())); };

		// Returns an iterator referring to the past-the-end element in the list container.
		iterator		end(void)
			{ return (iterator(blank_node)); };
		// Returns an const iterator referring to the past-the-end element in the list container.
		const_iterator	end(void) const
			{ return (const_iterator(blank_node)); };

		// Returns a reverse iterator pointing to the last element in the container.
		reverse_iterator		rbegin(void)
			{ return (reverse_iterator(blank_node->getPrev())); };
		// Returns a const reverse iterator pointing to the last element in the container.
		const_reverse_iterator	rbegin(void) const
			{ return (const_reverse_iterator(blank_node->getPrev())); };

		// Returns a reverse iterator pointing to the element preceding the first element in the list container.
		reverse_iterator		rend(void)
			{ return (reverse_iterator(blank_node)); };
		// Returns a const reverse iterator pointing to the element preceding the first element in the list container.
		const_reverse_iterator	rend(void) const
			{ return (const_reverse_iterator(blank_node)); };

		// Returns whether the list container is empty.
		bool			empty(void) const
			{ return (!list_size); };
		// Returns the number of elements in the list container.
		size_type		size(void) const
			{ return (list_size); };
		// Returns the maximum number of elements that the list container can hold.
		size_type		max_size(void) const
			{ return (node_alloc_max_size()); };

		// Returns a reference to the first element in the list container.
		reference		front(void)
			{ return (*(blank_node->getNext()->getContent())); };
		// Returns a const reference to the first element in the list container.
		const_reference	front(void) const
			{ return (*(blank_node->getNext()->getContent())); };

		// Returns a reference to the last element in the list container.
		reference		back(void)
			{ return (*(blank_node->getPrev()->getContent())); };
		// Returns a const reference to the last element in the list container.
		const_reference	back(void) const
			{ return (*(blank_node->getPrev()->getContent())); };

		// Range assign. Assigns new contents to the list container, replacing its current contents, and modifying its size accordingly. The new contents are elements constructed from each of the elements in the range between "first" and "last", in the same order.
		template	<class InputIterator>
		void	assign(
			InputIterator first,
			InputIterator last,
			typename ft::disable_if<is_integral<InputIterator>::value>::type* = 0)
		{
			for (; first != last; first++)
				push_back(*first);
		};
		// Fill assign. Assigns new contents to the list container, replacing its current contents, and modifying its size accordingly. The new contents are "n" elements, each initialized to a copy of "val".
		void	assign(size_type n, const value_type& val)
		{
			for (size_type i = 0; i < n; i++)
				push_back(val);
		};

		// Inserts a new element at the beginning of the list, right before its current first element, effectively increasing its size by one.
		void	push_front(const value_type& val)
		{
			node*	new_node = node_alloc.allocate(1, blank_node);
			node_alloc.construct(new_node, *new_node);
			new_node->setContent(val);
			blank_node->AddNext(new_node);
			list_size++;
		};
		// Removes the first element in the list container, effectively reducing its size by one.
		void	pop_front(void)
		{
			node*	dump = blank_node->getNext();
			node_alloc.destroy(dump);
			node_alloc.deallocate(dump, 1);
			list_size--;
		};
		// Adds a new element at the end of the list container, after its current last element, effectively increasing the container size by one.
		void	push_back(const value_type& val)
		{
			node*	new_node = node_alloc.allocate(1, blank_node->getPrev());
			node_alloc.construct(new_node, *new_node);
			new_node->setContent(val);
			blank_node->AddPrev(new_node);
			list_size++;
		};
		// Removes the last element in the list container, effectively reducing the container size by one.
		void	pop_back(void)
		{
			node*	dump = blank_node->getPrev();
			node_alloc.destroy(dump);
			node_alloc.deallocate(dump, 1);
			list_size--;
		};

		// Single element insert. The container is extended by inserting a new element "val", before the element at the specified "position".
		iterator	insert(iterator position, const value_type& val)
		{
			node*		pos_node;
			iterator	it = find_node(position, pos_node);
			if (it != position)
				return ;
			pos_node->AddNext(val);
			list_size++;
		};
		// Fill insert. The container is extended by inserting new elements containing "val", before the element at the specified "position".
		void		insert(iterator position, size_type n, const value_type& val)
		{
			node*		pos_node;
			iterator	it = find_node(position, pos_node);
			if (it != position)
				return ;
			for (int i = 0; i < n; i++)
			{
				pos_node->AddNext(val);
				list_size++;
			}
		};
		// Range insert. The container is extended by inserting new elements rangin from "first" to "last", before the element at the specified "position".
		template	<class InputIterator>
		void		insert(iterator position, InputIterator first, InputIterator last)
		{
			node*		pos_node;
			iterator	it = find_node(position, pos_node);
			if (it != position)
				return ;
			pos_node = pos_node->getNext();

			list	temp_list(first, last);
			first = temp_list.begin();
			last = temp_list.end();
			for (; first != last; first++)
			{
				std::cout << *first << std::endl;
				node*	temp = node_alloc.allocate(1);
				node_alloc.construct(temp, *temp);
				temp->setContent(*first);
				pos_node->AddPrev(temp);
				list_size++;
			}
		};

		// Removes from the list container either an element, "position".
		iterator erase (iterator position)
		{
			node*		pos_node;
			iterator	it = find_node(position, pos_node);
			if (it != position)
				return (it);
			it++;
			node_alloc.destroy(pos_node);
			node_alloc.deallocate(pos_node, 1);
			list_size--;
			return (it);
		};
		// Removes from the list container either a range of elements [first,last).
		iterator erase (iterator first, iterator last)
		{
			node*		pos_node;
			iterator	it = find_node(first, pos_node);
			if (it != first)
				return (it);
			node*	temp;
			while (it != last)
			{
				if (it == this->end())
					break ;
				it++;
				temp = pos_node->getNext();
				node_alloc.destroy(pos_node);
				node_alloc.deallocate(pos_node, 1);
				pos_node = temp;
				list_size--;
			}
			return (it);
		};

		// Exchanges the content of the container by the content of "lst", which is another list of the same type. Sizes may differ.
		void	swap(list& lst)
		{
			node*	temp_node;
			temp_node = lst.blank_node;
			lst.blank_node = this->blank_node;
			this->blank_node = temp_node;
			size_type	temp_size;
			temp_size = lst.list_size;
			lst.list_size = this->list_size;
			this->list_size = temp_size;
		};

		// Resizes the container so that it contains "n" elements.
		void	resize(size_type n, value_type val = value_type())
		{
			for (size_type i = 0; i < n; i++)
			{
				push_back(val);
				list_size++;
			}
		};
		// Removes all elements from the list container (which are destroyed), and leaving the container with a size of 0.
		void	clear(void)
		{
			while (blank_node->getNext() != blank_node)
				pop_back();
			list_size = 0;
		};

		// Splice entire list. Transfers all the elements of x into the container, inserting them at position.
		void	splice(iterator position, list& lst)
		{
			node*		pos_node;
			iterator	it = find_node(position, pos_node);
			if (it != position)
			{
				std::cout << "abc";
				return ;
			}
			pos_node = pos_node->getNext();

			list	temp_list(lst);

			node*	cur_node = temp_list.blank_node;
			node*	next_node = cur_node->getNext();
			while (next_node != temp_list.blank_node)
			{
				std::cout << "test";
				next_node = cur_node->getNext();
				pos_node->AddPrev(cur_node->PopGetNode());
				cur_node = next_node;
				list_size++;
			}
		};
		// Splice a single element. Transfers only the element pointed by i from x into the container, inserting them at position.
		void	splice(iterator position, list& lst, iterator i)
		{
			node*		target_node;
			iterator	it = lst.find_node(i, target_node);
			if (it != i)
				return ;
			node*		pos_node;
			it = find_node(position, pos_node);
			if (it != position)
				return ;
			node*	temp = node_alloc.allocate(1);
			node_alloc.construct(temp, *target_node);
			pos_node->AddPrev(temp);
			list_size++;
		};
		// Splice a range of elements. Transfers the range [first,last) from x into the container, inserting them at position
		// void	splice(iterator position, list& lst, iterator first, iterator last)
		// {
		// 	node*	target_node;
		// 	iterator	it = lst.find_node(first, target_node);
		// 	if (it != first)
		// 		return ;
		// 	node*		pos_node;
		// 	iterator	it = find_node(position, pos_node);
		// 	if (it != position)
		// 		return ;
		// 	pos_node = pos_node->getNext();

		// 	list	temp_list(first, last);
		// 	first = temp_list.begin();
		// 	last = temp_list.end();
		// 	for (; first != last; first++)
		// 	{
		// 		std::cout << *first << std::endl;
		// 		node*	temp = node_alloc.allocate(1);
		// 		temp->setContent(*first);
		// 		pos_node->AddPrev(temp);
		// 		list_size++;
		// 	}
		// };

		// // Removes from the container all the elements that compare equal to "val".
		// void	remove(const value_type& val);
		// // Removes from the container all the elements for which "Predicate pred" returns true.
		// template	<class Predicate>
		// void	remove_if(Predicate pred);

		// // Removes all but the first element from every consecutive group of equal elements in the container. An element is only removed from the list container if it compares equal to the element immediately preceding it.
		// void	unique(void);
		// // Removes all elements that makes "BinaryPredicate binary_pred" return true in the container. An alement will be compared to a preceding element by "biniary_pred".
		// template	<class BinaryPredicate>
		// void	unique(BinaryPredicate binary_pred);

		// // Merges x into the list by transferring all of its elements at their respective ordered positions into the container (both containers shall already be ordered).
		// void	merge(list& lst);
		// // Merges x into the list by transferring all of its elements at their respective ordered positions into the container (both containers shall already be ordered). Binary predicate "comp" shall be a function pointer or a function object.
		// template	<class Compare>
		// void	merge(list& x, Compare comp);

		// // Sorts the elements in the list by applying an algorithm that uses "operator<", altering their position within the container.
		// void sort(void);
		// // Sorts the elements in the list by applying an algorithm that uses "comp", altering their position within the container.
		// template	<class Compare>
		// void	sort (Compare comp);

		// // Reverses the order of the elements in the list container.
		// void	reverse(void);

	};
}

#endif
