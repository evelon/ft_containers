#ifndef LIST_REVERSE_ITERATOR_HPP
# define LIST_REVERSE_ITERATOR_HPP

# include "list_iterator.hpp"

namespace ft
{
	template <typename Tp, class Node = DoublyLinkedNode<Tp> >
	class	list_reverse_iterator;

	template <typename Tp, class Node>
	class	list_reverse_iterator: public list_iterator<Tp, Node>
	{
		list_iterator<Tp, Node>	base(void) const
			{ list_iterator<Tp, Node> temp = *this; return (--temp); };
		iterator_type&	operator++(void)
			{ return (operator--()); };
		iterator_type&	operator--(void)
			{ return (operator++()); };
		iterator_type	operator++(int)
			{ return (operator--(0)); };
		iterator_type	operator--(int)
			{ return (operator++(0)); };
	}
};

#endif
