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

		class	node_iterator: public list_iterator<Tp, node>
		{
		private:
			typedef list_iterator<Tp, node>	iterator;
		public:
			node_iterator():
				iterator() {};
			node_iterator(node_iterator const& n_it):
				iterator(n_it) {};
			node_iterator(iterator const& it):
				iterator(it) {};
			node_iterator&	operator=(node_iterator const& n_it)
				{ this->ptrToNode = n_it.ptrToNode; return (*this); }
			node_iterator&	operator=(iterator const& it)
				{ this->ptrToNode = it.ptrToNode; return (*this); }
			virtual ~node_iterator() {};


			node_iterator&	operator++(void)
			{
				if (this->ptrToNode->getContent() != nullptr)
					this->ptrToNode = this->ptrToNode->getNext();
				return (*this);
			};
			node_iterator&	operator--(void)
			{
				if (this->ptrToNode->getContent() != nullptr)
					this->ptrToNode = this->ptrToNode->getPrev();
				return (*this);
			};
			node_iterator	operator++(int)
			{
				node_iterator	temp = *this;
				if (this->ptrToNode->getContent() != nullptr)
					this->ptrToNode = this->ptrToNode->getNext();
				return (temp);
			};
			node_iterator	operator--(int)
			{
				node_iterator	temp = *this;
				if (this->ptrToNode->getContent() != nullptr)
					this->ptrToNode = this->ptrToNode->getPrev();
				return (temp);
			};
			node*&	getNode(void)
				{ return (this->ptrToNode); };
			node*&	getNext(void)
				{ return (this->ptrToNode->getNext()); }
			node*&	getPrev(void)
				{ return (this->ptrToNode->getNext()); }
			void	AddNext(node* nod)
				{ this->ptrToNode->AddNext(nod); }
			void	AddNext(node_iterator nit)
				{ this->ptrToNode->AddNext(nit->getNode()); }
			void	AddPrev(node* nod)
				{ this->ptrToNode->AddPrev(nod); }
			void	AddPrev(node_iterator nit)
				{ this->ptrToNode->AddPrev(nit->getNode()); }
		};

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

		bool	is_included(iterator& position, list& lst)
		{
			size_type	i = 0;
			for (iterator it = lst.begin(); it != position; it++)
				if (i++ > lst.list_size)
					return (false);
			return (true);
		}

		struct	basic_compare
		{
			bool	operator()(value_type const& a, value_type const& b) const
			{ return (a < b); }
		};
		// Sort from "first" node to "last" node.
		template	<class Predicate>
		void	quick_sort(iterator left, iterator right, Predicate compare)
		{
			iterator	check = left;
			if (left == right || --check == right)
				return ;
			node_iterator	pivot = left;
			node_iterator	i = left;
			node_iterator	j = right;

			while (i != j)
			{
				while (compare(*pivot, *j))
					j--;
				while (i != j && !compare(*pivot, *i))
					i++;
				i.getNode()->ContentExchange(j.getNode());
			}
			pivot.getNode()->ContentExchange((i--).getNode());
			quick_sort(left, i++, compare);
			quick_sort(++i, right, compare);
		}

	public:
		// Default constructor. Construct list with an allocator instance "alloc"
		explicit list(const allocator_type& alloc = allocator_type()):
			allocator(alloc),
			node_alloc(),
			blank_node(node_alloc.allocate(1)),
			list_size(0)
		{ node_alloc.construct(blank_node, *blank_node, alloc); };
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
			node_alloc.construct(blank_node, *blank_node, alloc);
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
			node_alloc.construct(blank_node, *blank_node, alloc);
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
			node_alloc.construct(blank_node, *blank_node, lst.allocator);
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
			if (lst.list_size <= this->list_size)
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
				iterator it;
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
			while (blank_node->getNext() != blank_node)
				pop_front();
			list_size = 0;
			for (; first != last; first++)
				push_back(*first);
		};
		// Fill assign. Assigns new contents to the list container, replacing its current contents, and modifying its size accordingly. The new contents are "n" elements, each initialized to a copy of "val".
		void	assign(size_type n, const value_type& val)
		{
			while (blank_node->getNext() != blank_node)
				pop_back();
			list_size = 0;
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
			if (!is_included(position, *this))
				return (position);
			node*	new_node(node_alloc.allocate(1));
			node_alloc.construct(new_node, *new_node);
			new_node->setContent(val);
			node_iterator	nit = position--;
			nit.AddPrev(new_node);
			list_size++;
			return (++position);
		};
		// Fill insert. The container is extended by inserting new elements containing "val", before the element at the specified "position".
		void		insert(iterator position, size_type n, const value_type& val)
		{
			if (!is_included(position, *this))
				return ;
			node_iterator	nit(position);
			node*			temp;
			for (size_type i = 0; i < n; i++)
			{
				temp = node_alloc.allocate(1);
				node_alloc.construct(temp, *temp);
				temp->setContent(val);
				nit.AddPrev(temp);
				list_size++;
			}
		}
		// Range insert. The container is extended by inserting new elements rangin from "first" to "last", before the element at the specified "position".
		template	<class InputIterator>
		void		insert(iterator position, InputIterator first, InputIterator last, typename ft::disable_if<is_integral<InputIterator>::value>::type* = 0)
		{
			if (!is_included(position, *this))
				return ;
			node_iterator	nit(position);

			list	temp_list(first, last);
			node_iterator	first_n(temp_list.begin());
			node_iterator	last_n(temp_list.end());
			node*			temp;
			for (; first_n != last_n; first_n++)
			{
				temp = node_alloc.allocate(1);
				node_alloc.construct(temp, *first_n.getNode());
				nit.AddPrev(temp);
				list_size++;
			}
		};

		// Removes from the list container either an element, "position".
		iterator erase (iterator position)
		{
			if (!is_included(position, *this))
				return (position);
			node_iterator	nit(position++);
			node_alloc.destroy(nit.getNode());
			node_alloc.deallocate(nit.getNode(), 1);
			list_size--;
			return (position);
		};
		// Removes from the list container either a range of elements [first,last).
		iterator erase (iterator first, iterator last)
		{
			if (!is_included(first, *this) || !is_included(last, *this))
				return (last);
			node_iterator	nit(first);
			node*			pos_node(nit.getNode());
			node*			temp;
			while (first != last)
			{
				if (first == this->end())
					break ;
				first++;
				temp = pos_node->getNext();
				node_alloc.destroy(pos_node);
				node_alloc.deallocate(pos_node, 1);
				pos_node = temp;
				list_size--;
			}
			return (first);
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
			node_iterator	nit = begin();
			for (size_type i = 0; i < n; i++)
			{
				if (nit != end())
					nit++;
				else
					push_back(val);
			}
			while (n < list_size)
				pop_back();
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
			if (!is_included(position, *this))
				return ;
			node_iterator	nit(--position);
			node*	pos_node = nit.getNode()->getNext();
			node*	cur_node = lst.blank_node->getNext();
			node*	next_node = cur_node->getNext();
			while (next_node != lst.blank_node)
			{
				next_node = cur_node->getNext();
				pos_node->AddPrev(cur_node->PopGetNode());
				cur_node = next_node;
				this->list_size++;
				lst.list_size--;
			}
		};
		// Splice a single element. Transfers only the element pointed by i from x into the container, inserting them at position.
		void	splice(iterator position, list& lst, iterator i)
		{
			if (!is_included(position, *this) || !is_included(i, lst))
				return ;
			node_iterator	this_nit(--position);
			node_iterator	that_nit(i);

			this_nit.AddPrev(that_nit.getNode()->PopGetNode());
			lst.list_size--;
			this->list_size++;
		};
		// Splice a range of elements. Transfers the range [first,last) from x into the container, inserting them at position
		void	splice(iterator position, list& lst, iterator first, iterator last)
		{
			list			temp_list(first, last);
			node_iterator	origin_first = first;
			node_iterator	first_n(temp_list.begin());
			node_iterator	last_n(temp_list.end());
			node_iterator	pos_n(--position);
			while (first_n != last_n && lst.list_size != 0)
			{
				(++origin_first).getPrev()->PopGetNode();
				pos_n.AddPrev((++first_n).getPrev()->PopGetNode());
				this->list_size++;
				lst.list_size--;
			}
		};

		// Removes from the container all the elements that compare equal to "val".
		void	remove(const value_type& val)
		{
			node*	cur_node = blank_node->getNext();
			node*	next_node;
			while (cur_node != blank_node)
			{
				next_node = cur_node->getNext();
				if (*cur_node->getContent() == val)
				{
					node_alloc.destroy(cur_node);
					node_alloc.deallocate(cur_node, 1);
					list_size--;
				}
				cur_node = next_node;
			}
		};
		// Removes from the container all the elements for which "Predicate pred" returns true.
		template	<class Predicate>
		void	remove_if(Predicate pred)
		{
			node*	cur_node = blank_node->getNext();
			node*	next_node;
			while (cur_node != blank_node)
			{
				next_node = cur_node->getNext();
				if (pred(*cur_node->getContent()))
				{
					node_alloc.destroy(cur_node);
					node_alloc.deallocate(cur_node, 1);
					list_size--;
				}
				cur_node = next_node;
			}
		}
		// Removes all but the first element from every consecutive group of equal elements in the container. An element is only removed from the list container if it compares equal to the element immediately preceding it.
		void	unique(void)
		{
			node*	cur_node = blank_node->getNext()->getNext();
			node*	next_node;
			while (cur_node != blank_node)
			{
				next_node = cur_node->getNext();
				if (*cur_node->getContent() == *cur_node->getPrev()->getContent())
				{
					node_alloc.destroy(cur_node);
					node_alloc.deallocate(cur_node, 1);
					list_size--;
				}
				cur_node = next_node;
			}
		};
		// Removes all elements that makes "BinaryPredicate binary_pred" return true in the container. An alement will be compared to a preceding element by "biniary_pred".
		template	<class BinaryPredicate>
		void	unique(BinaryPredicate binary_pred)
		{
			node*	cur_node = blank_node->getNext()->getNext();
			node*	next_node;
			while (cur_node != blank_node)
			{
				next_node = cur_node->getNext();
				if (binary_pred(*cur_node->getContent(), *cur_node->getPrev()->getContent()))
				{
					node_alloc.destroy(cur_node);
					node_alloc.deallocate(cur_node, 1);
					list_size--;
				}
				cur_node = next_node;
			}
		};
		// Merges x into the list by transferring all of its elements at their respective ordered positions into the container (both containers shall already be ordered).
		void	merge(list& lst)
		{ merge(lst, basic_compare()); }
		// Merges x into the list by transferring all of its elements at their respective ordered positions into the container (both containers shall already be ordered). Binary predicate "comp" shall be a function pointer or a function object.
		template	<class Compare>
		void	merge(list& lst, Compare comp)
		{
			node_iterator	this_nit(this->begin());
			node_iterator	that_nit(lst.begin());

			while (this_nit != this->end())
			{
				while (comp(*that_nit, *this_nit) && that_nit != lst.end())
				{
					that_nit++;
					this_nit.AddPrev(that_nit.getPrev()->PopGetNode());
				}
				this_nit++;
			}
		};

		// Sorts the elements in the list by applying an algorithm that uses "operator<", altering their position within the container.
		void	sort(void)
		{ quick_sort(begin(), --end(), basic_compare()); };
		// Sorts the elements in the list by applying an algorithm that uses "comp", altering their position within the container.
		template	<class Compare>
		void	sort (Compare comp)
		{ quick_sort(begin(), --end(), comp); };

		// // Reverses the order of the elements in the list container.
		void	reverse(void)
		{
			iterator	first = begin();
			iterator	last = --end();
			value_type	temp;

			while (first != last)
			{
				temp = *first;
				*first = *last;
				*last = temp;
				first++;
				if (first == last)
					break ;
				last--;
			}
		};
	};

	template	<class T, class Alloc>
	bool	operator==(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		typename list<T,Alloc>::const_iterator	lit = lhs.begin();
		typename list<T,Alloc>::const_iterator	rit = rhs.begin();
		while (lit != lhs.end() || rit != rhs.end())
		{
			if (*lit != *rit)
				return (false);
			lit++;
			rit++;
		}
		return (true);
	};

	template	<class T, class Alloc>
	bool	operator!=(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
		{ return (!(lhs == rhs)); };

	template	<class T, class Alloc>
	bool	operator<(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
	{
		typename list<T,Alloc>::const_iterator	lit = lhs.begin();
		typename list<T,Alloc>::const_iterator	rit = rhs.begin();
		while (lit != lhs.end() && rit != rhs.end())
		{
			if (*lit < *rit)
				return (true);
			else if (*lit > *rit)
				return (false);
			lit++;
			rit++;
		}
		if (lit == lhs.end() && rit != rhs.end())
			return (true);
		return (false);
	};

	template	<class T, class Alloc>
	bool	operator<=(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
		{ return (!(rhs < lhs)); };

	template	<class T, class Alloc>
	bool	operator>(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
		{ return (rhs < lhs); };

	template	<class T, class Alloc>
	bool	operator>=(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
		{ return (!(lhs < rhs)); };
}

#endif
