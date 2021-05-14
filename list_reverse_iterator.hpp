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
	private:
		typedef list_iterator<Tp, Node>			iterator_type;
		typedef list_reverse_iterator<Tp, Node>	reverse_iterator_type;

	public:
		reverse_iterator_type	base(void) const
			{ iterator_type temp = *this; return (--temp); };
		reverse_iterator_type&	operator++(void)
			{ return (static_cast<iterator_type>(this)->operator--()); };
		reverse_iterator_type&	operator--(void)
			{ return (static_cast<iterator_type>(this)->operator++()); };
		reverse_iterator_type	operator++(int)
			{ return (static_cast<iterator_type>(this)->operator--(0)); };
		reverse_iterator_type	operator--(int)
			{ return (static_cast<iterator_type>(this)->operator++(0)); };
	};
};

#endif
