#ifndef LIST_HPP
# define LIST_HPP

# include "template_utils.hpp"
# include "DoublyLinkedNode.hpp"
# include "list_iterator.hpp"
# include "reverse_iterator.hpp"

#include <iostream>


namespace	ft
{
	template	<typename Tp, class Alloc = std::allocator<Tp> >
	class	list;

	template	<typename Tp, class Alloc>
	class	list
	{
	private:
		typedef DoublyLinkedNode<Tp, Alloc>						node_;
		typedef typename Alloc::template rebind<node_>::other	node_allocator_;

		class	node_iterator: public list_iterator<Tp>
		{
		private:
			typedef list_iterator<Tp>	iterator;
		public:
			node_iterator():
				iterator() {};
			node_iterator(node_iterator const& n_it):
				iterator(n_it) {};
			node_iterator(node_* nod):
				iterator(nod) {};
			node_iterator(iterator const& it):
				iterator(it) {};
			node_iterator&	operator=(node_iterator const& n_it)
				{ iterator::operator=(n_it); return (*this); }
			node_iterator&	operator=(iterator const& it)
				{ iterator::operator=(it); return (*this); }
			virtual ~node_iterator() {};

			node_iterator&	operator++(void)
			{
				if (this->getNode()->getContent() != NULL)
					this->getNode() = this->getNode()->getNext();
				return (*this);
			};
			node_iterator&	operator--(void)
			{
				if (this->getNode()->getContent() != NULL)
					this->getNode() = this->getNode()->getPrev();
				return (*this);
			};
			node_iterator	operator++(int)
			{
				node_iterator	temp = *this;
				if (this->getNode()->getContent() != NULL)
					this->getNode() = this->getNode()->getNext();
				return (temp);
			};
			node_iterator	operator--(int)
			{
				node_iterator	temp = *this;
				if (this->getNode()->getContent() != NULL)
					this->getNode() = this->getNode()->getPrev();
				return (temp);
			};
			node_*&	getNode(void)
				{ return (this->getNode_()); };
			node_*&	getNext(void)
				{ return (this->getNode()->getNext()); }
			node_*&	getPrev(void)
				{ return (this->getNode()->getPrev()); }
			void	AddNext(node_* nod)
				{ this->getNode()->AddNext(nod); }
			void	AddNext(node_iterator nit)
				{ this->getNode()->AddNext(nit->getNode()); }
			void	AddPrev(node_* nod)
				{ this->getNode()->AddPrev(nod); }
			void	AddPrev(node_iterator nit)
				{ this->getNode()->AddPrev(nit->getNode()); }
		};

	public:
		typedef Tp										value_type;
		typedef Alloc									allocator_type;
		typedef typename Alloc::reference				reference;
		typedef typename Alloc::const_reference			const_reference;
		typedef typename Alloc::pointer					pointer;
		typedef typename Alloc::const_pointer			const_pointer;
		typedef list_iterator<const Tp>					const_iterator;
		typedef list_iterator<Tp>						iterator;
		typedef reverse_iterator<const_iterator>		const_reverse_iterator;
		typedef reverse_iterator<iterator>				reverse_iterator;
		typedef ptrdiff_t								difference_type;
		typedef size_t									size_type;

	private:
		allocator_type	alloc_;
		node_allocator_	node_alloc_;
		node_*			blank_node_;
		size_type		size_;

		size_type	node_alloc_max_size() const
		{
			size_type	node_max = node_alloc_.max_size();
			size_type	type_max = std::numeric_limits<difference_type>::max();
			if (node_max > type_max)
				return (type_max);
			return (node_max);
		}

		bool	is_included(iterator& position, list& lst)
		{
			size_type	i = 0;
			for (iterator it = lst.begin(); it != position; it++)
				if (i++ > lst.size_)
					return (false);
			return (true);
		}

		struct	basic_compare
		{
			bool	operator()(value_type const& a, value_type const& b) const
			{ return (a < b); }
		};
		// Sort from "first" node to "last" node.

		// void	print_list(void)
		// {
		// 	for (iterator it = begin(); it != end(); it++)
		// 		std::cout << "[" << *it << "]" << std::endl;
		// 		std::cout << std::endl;
		// }

		template	<class Predicate>
		void	insertion_sort(Predicate compare)
		{
			node_iterator	i, j, key, pre_begin;

			pre_begin = --begin();
			for (i = ++begin(); i != end(); i++)
			{
				key = i--;
				for (j = i++; j != pre_begin && compare(*key, *j); j--);
				j.getNode()->AddNext(key.getNode()->PopGetNode());
			}
		}

	public:
		// Default constructor. Construct list with an _alloc instance "alloc"
		explicit list(const allocator_type& alloc = allocator_type()):
			alloc_(alloc),
			node_alloc_(),
			blank_node_(node_alloc_.allocate(1)),
			size_(0)
		{ node_alloc_.construct(blank_node_, *blank_node_, alloc); };
		// Fill constructor. Construct list with "n" number of values of "val", with an _alloc instance "alloc"
		explicit list(
			size_type n,
			const value_type& val = value_type(),
			const allocator_type& alloc = allocator_type()):
			alloc_(alloc),
			node_alloc_(),
			blank_node_(node_alloc_.allocate(1)),
			size_(0)
		{
			node_alloc_.construct(blank_node_, *blank_node_, alloc);
			for (size_type i = 0; i < n; i++)
				push_back(val);
		};
		// Range constructor. Construct list in range from "first" to "last", with an _alloc instance "alloc"
		template	<class InputIterator>
		list(
			InputIterator first,
			InputIterator last,
			const allocator_type& alloc = allocator_type(),
			typename ft::disable_if<is_integral<InputIterator>::value>::type* = 0):
			alloc_(alloc),
			node_alloc_(),
			blank_node_(node_alloc_.allocate(1)),
			size_(0)
		{
			node_alloc_.construct(blank_node_, *blank_node_, alloc);
			for (; first != last; first++)
				push_back(*first);
		};
		// Copy constructor. Construct list by copying the list "lst".
		list(const list& lst):
			alloc_(lst.alloc_),
			node_alloc_(lst.node_alloc_),
			blank_node_(node_alloc_.allocate(1)),
			size_(0)
		{
			node_alloc_.construct(blank_node_, *blank_node_, lst.alloc_);
			for (const_iterator it = lst.begin(); it != lst.end(); it++)
				push_back(*it);
		};

		// List destructor
		~list(void)
		{
			node_*	temp;
			while (blank_node_->getNext() != blank_node_)
			{
				temp = blank_node_->getPrev();
				node_alloc_.destroy(temp);
				node_alloc_.deallocate(temp, 1);
			}
			node_alloc_.destroy(blank_node_);
			node_alloc_.deallocate(blank_node_, 1);
		};

		// Assign content
		list&	operator=(const list& lst)
		{
			node_*	cur_node = this->blank_node_->getNext();
			if (lst.size_ <= this->size_)
			{
				for (const_iterator it = lst.begin(); it != lst.end(); it++)
				{
					cur_node->setContent(*it);
					cur_node = cur_node->getNext();
				}
				node_*	temp;
				while (cur_node != this->blank_node_)
				{
					temp = cur_node->getNext();
					this->node_alloc_.destroy(cur_node);
					this->node_alloc_.deallocate(cur_node, 1);
					cur_node = temp;
				}
			}
			else
			{
				iterator it;
				for (it = lst.begin(); cur_node != this->blank_node_; it++)
				{
					cur_node->setContent(*it);
					cur_node = cur_node->getNext();
				}
				for (; it != lst.end(); it++)
					push_back(*it);
			}
			this->size_ = lst.size();
			return (*this);
		}

		// Returns an iterator pointing to the first element in the list container.
		iterator		begin(void)
			{ return (node_iterator(blank_node_->getNext())); };
		// Returns an const iterator pointing to the first element in the list container.
		const_iterator	begin(void) const
			{ return (const_iterator(node_iterator(blank_node_->getNext()))); };

		// Returns an iterator referring to the past-the-end element in the list container.
		iterator		end(void)
			{ return (node_iterator(blank_node_)); };
		// Returns an const iterator referring to the past-the-end element in the list container.
		const_iterator	end(void) const
			{ return (const_iterator(node_iterator(blank_node_))); };

		// Returns a reverse iterator pointing to the last element in the container.
		reverse_iterator		rbegin(void)
			{ return (reverse_iterator(node_iterator(blank_node_))); };
		// Returns a const reverse iterator pointing to the last element in the container.
		const_reverse_iterator	rbegin(void) const
			{ return (const_reverse_iterator(node_iterator(blank_node_))); };

		// Returns a reverse iterator pointing to the element preceding the first element in the list container.
		reverse_iterator		rend(void)
			{ return (reverse_iterator(node_iterator(blank_node_->getNext()))); };
		// Returns a const reverse iterator pointing to the element preceding the first element in the list container.
		const_reverse_iterator	rend(void) const
			{ return (const_reverse_iterator(node_iterator(blank_node_->getNext()))); };

		// Returns whether the list container is empty.
		bool			empty(void) const
			{ return (!size_); };
		// Returns the number of elements in the list container.
		size_type		size(void) const
			{ return (size_); };
		// Returns the maximum number of elements that the list container can hold.
		size_type		max_size(void) const
			{ return (node_alloc_max_size()); };

		// Returns a reference to the first element in the list container.
		reference		front(void)
			{ return (*(blank_node_->getNext()->getContent())); };
		// Returns a const reference to the first element in the list container.
		const_reference	front(void) const
			{ return (*(blank_node_->getNext()->getContent())); };

		// Returns a reference to the last element in the list container.
		reference		back(void)
			{ return (*(blank_node_->getPrev()->getContent())); };
		// Returns a const reference to the last element in the list container.
		const_reference	back(void) const
			{ return (*(blank_node_->getPrev()->getContent())); };

		// Range assign. Assigns new contents to the list container, replacing its current contents, and modifying its size accordingly. The new contents are elements constructed from each of the elements in the range between "first" and "last", in the same order.
		template	<class InputIterator>
		void	assign(
			InputIterator first,
			InputIterator last,
			typename ft::disable_if<is_integral<InputIterator>::value>::type* = 0)
		{
			while (blank_node_->getNext() != blank_node_)
				pop_front();
			size_ = 0;
			for (; first != last; first++)
				push_back(*first);
		};
		// Fill assign. Assigns new contents to the list container, replacing its current contents, and modifying its size accordingly. The new contents are "n" elements, each initialized to a copy of "val".
		void	assign(size_type n, const value_type& val)
		{
			while (blank_node_->getNext() != blank_node_)
				pop_back();
			size_ = 0;
			for (size_type i = 0; i < n; i++)
				push_back(val);
		};

		// Inserts a new element at the beginning of the list, right before its current first element, effectively increasing its size by one.
		void	push_front(const value_type& val)
		{
			node_*	new_node = node_alloc_.allocate(1, blank_node_);
			node_alloc_.construct(new_node, *new_node);
			new_node->setContent(val);
			blank_node_->AddNext(new_node);
			size_++;
		};
		// Removes the first element in the list container, effectively reducing its size by one.
		void	pop_front(void)
		{
			node_*	dump = blank_node_->getNext();
			node_alloc_.destroy(dump);
			node_alloc_.deallocate(dump, 1);
			size_--;
		};
		// Adds a new element at the end of the list container, after its current last element, effectively increasing the container size by one.
		void	push_back(const value_type& val)
		{
			node_*	new_node = node_alloc_.allocate(1, blank_node_->getPrev());
			node_alloc_.construct(new_node, *new_node);
			new_node->setContent(val);
			blank_node_->AddPrev(new_node);
			size_++;
		};
		// Removes the last element in the list container, effectively reducing the container size by one.
		void	pop_back(void)
		{
			node_*	dump = blank_node_->getPrev();
			node_alloc_.destroy(dump);
			node_alloc_.deallocate(dump, 1);
			size_--;
		};

		// Single element insert. The container is extended by inserting a new element "val", before the element at the specified "position".
		iterator	insert(iterator position, const value_type& val)
		{
			if (!is_included(position, *this))
				return (position);
			node_*	new_node(node_alloc_.allocate(1));
			node_alloc_.construct(new_node, *new_node);
			new_node->setContent(val);
			node_iterator	nit = position--;
			nit.AddPrev(new_node);
			size_++;
			return (++position);
		};
		// Fill insert. The container is extended by inserting new elements containing "val", before the element at the specified "position".
		void		insert(iterator position, size_type n, const value_type& val)
		{
			if (!is_included(position, *this))
				return ;
			node_iterator	nit(position);
			node_*			temp;
			for (size_type i = 0; i < n; i++)
			{
				temp = node_alloc_.allocate(1);
				node_alloc_.construct(temp, *temp);
				temp->setContent(val);
				nit.AddPrev(temp);
				size_++;
			}
		}
		// Range insert. The container is extended by inserting new elements rangin from "first" to "last", before the element at the specified "position".
		template	<class InputIterator>
		void		insert(
			iterator position,
			InputIterator first,
			InputIterator last,
			typename ft::disable_if<is_integral<InputIterator>::value>::type* = 0)
		{
			if (!is_included(position, *this))
				return ;
			node_iterator	nit(position);

			list	temp_list(first, last);
			node_iterator	first_n(temp_list.begin());
			node_iterator	last_n(temp_list.end());
			node_*			temp;
			for (; first_n != last_n; first_n++)
			{
				temp = node_alloc_.allocate(1);
				node_alloc_.construct(temp, *first_n.getNode());
				nit.AddPrev(temp);
				size_++;
			}
		};

		// Removes from the list container either an element, "position".
		iterator erase (iterator position)
		{
			if (!is_included(position, *this))
				return (position);
			node_iterator	nit(position++);
			node_alloc_.destroy(nit.getNode());
			node_alloc_.deallocate(nit.getNode(), 1);
			size_--;
			return (position);
		};
		// Removes from the list container either a range of elements [first,last).
		iterator erase (iterator first, iterator last)
		{
			if (!is_included(first, *this) || !is_included(last, *this))
				return (last);
			node_iterator	nit(first);
			node_*			pos_node(nit.getNode());
			node_*			temp;
			while (first != last)
			{
				if (first == this->end())
					break ;
				first++;
				temp = pos_node->getNext();
				node_alloc_.destroy(pos_node);
				node_alloc_.deallocate(pos_node, 1);
				pos_node = temp;
				size_--;
			}
			return (first);
		};

		// Exchanges the content of the container by the content of "lst", which is another list of the same type. Sizes may differ.
		void	swap(list& lst)
		{
			node_*	temp_node;
			temp_node = lst.blank_node_;
			lst.blank_node_ = this->blank_node_;
			this->blank_node_ = temp_node;
			size_type	temp_size;
			temp_size = lst.size_;
			lst.size_ = this->size_;
			this->size_ = temp_size;
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
			while (n < size_)
				pop_back();
		};
		// Removes all elements from the list container (which are destroyed), and leaving the container with a size of 0.
		void	clear(void)
		{
			while (blank_node_->getNext() != blank_node_)
				pop_back();
			size_ = 0;
		};

		// Splice entire list. Transfers all the elements of x into the container, inserting them at position.
		void	splice(iterator position, list& lst)
		{
			if (!is_included(position, *this))
				return ;
			node_iterator	nit(position);
			node_*	pos_node = nit.getNode();
			node_*	cur_node = lst.blank_node_->getNext();
			node_*	next_node = cur_node->getNext();
			while (next_node != lst.blank_node_)
			{
				next_node = cur_node->getNext();
				pos_node->AddPrev(cur_node->PopGetNode());
				cur_node = next_node;
				this->size_++;
				lst.size_--;
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
			lst.size_--;
			this->size_++;
		};
		// Splice a range of elements. Transfers the range [first,last) from "lst" into the container, inserting them at position
		void	splice(iterator position, list& lst, iterator first, iterator last)
		{
			if (!is_included(position, *this) || !is_included(first, lst) || !is_included(last, lst))
				return ;
			node_iterator	nit(position);
			node_iterator	first_n = first;
			node_iterator	last_n = last;
			node_iterator	temp = first_n++;
			while (first_n != last_n)
			{
				nit.AddPrev(temp.getNode()->PopGetNode());
				temp = first_n++;
				lst.size_--;
				this->size_++;
			}
			nit.AddPrev(temp.getNode()->PopGetNode());
			lst.size_--;
			this->size_++;
		};

		// Removes from the container all the elements that compare equal to "val".
		void	remove(const value_type& val)
		{
			node_*	cur_node = blank_node_->getNext();
			node_*	next_node;
			while (cur_node != blank_node_)
			{
				next_node = cur_node->getNext();
				if (*cur_node->getContent() == val)
				{
					node_alloc_.destroy(cur_node);
					node_alloc_.deallocate(cur_node, 1);
					size_--;
				}
				cur_node = next_node;
			}
		};
		// Removes from the container all the elements for which "Predicate pred" returns true.
		template	<class Predicate>
		void	remove_if(Predicate pred)
		{
			node_*	cur_node = blank_node_->getNext();
			node_*	next_node;
			while (cur_node != blank_node_)
			{
				next_node = cur_node->getNext();
				if (pred(*cur_node->getContent()))
				{
					node_alloc_.destroy(cur_node);
					node_alloc_.deallocate(cur_node, 1);
					size_--;
				}
				cur_node = next_node;
			}
		}
		// Removes all but the first element from every consecutive group of equal elements in the container. An element is only removed from the list container if it compares equal to the element immediately preceding it.
		void	unique(void)
		{
			node_*	cur_node = blank_node_->getNext()->getNext();
			node_*	next_node;
			while (cur_node != blank_node_)
			{
				next_node = cur_node->getNext();
				if (*cur_node->getContent() == *cur_node->getPrev()->getContent())
				{
					node_alloc_.destroy(cur_node);
					node_alloc_.deallocate(cur_node, 1);
					size_--;
				}
				cur_node = next_node;
			}
		};
		// Removes all elements that makes "BinaryPredicate binary_pred" return true in the container. An alement will be compared to a preceding element by "biniary_pred".
		template	<class BinaryPredicate>
		void	unique(BinaryPredicate binary_pred)
		{
			node_*	cur_node = blank_node_->getNext()->getNext();
			node_*	next_node;
			while (cur_node != blank_node_)
			{
				next_node = cur_node->getNext();
				if (binary_pred(*cur_node->getContent(), *cur_node->getPrev()->getContent()))
				{
					node_alloc_.destroy(cur_node);
					node_alloc_.deallocate(cur_node, 1);
					size_--;
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
			node_iterator	lst_nit(lst.begin());

			while (this_nit != this->end())
			{
				while (comp(*lst_nit, *this_nit) && lst_nit != lst.end())
				{
					lst_nit++;
					this_nit.AddPrev(lst_nit.getPrev()->PopGetNode());
					this->size_++;
					lst.size_--;
				}
				this_nit++;
			}
			while (lst_nit != lst.end())
			{
				lst_nit++;
				this_nit.AddPrev(lst_nit.getPrev()->PopGetNode());
				this->size_++;
				lst.size_--;
			}
		};

		// Sorts the elements in the list by applying an algorithm that uses "operator<", altering their position within the container.
		void	sort(void)
		{ insertion_sort(basic_compare()); };
		// Sorts the elements in the list by applying an algorithm that uses "comp", altering their position within the container.
		template	<class Compare>
		void	sort (Compare comp)
		{ insertion_sort(comp); };

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

		// Returns a copy of the allocator object associated with the list container.
		allocator_type get_allocator() const
			{ return (allocator_type()); };
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

	template	<class T, class Alloc>
	void	swap(list<T, Alloc>& x, list<T, Alloc>& y)
		{ list<T, Alloc> temp = x; x = y; y = temp; }
}

#endif
