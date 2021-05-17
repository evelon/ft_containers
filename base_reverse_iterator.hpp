#ifndef LIST_REVERSE_ITERATOR_HPP
# define LIST_REVERSE_ITERATOR_HPP

# include "list_iterator.hpp"

# include <iostream>
# include <iterator>

namespace ft
{
	template <typename Iterator>
	class	base_reverse_iterator;

	template <typename Iterator>
	class	base_reverse_iterator: public Iterator
	{
	private:
		typedef Iterator				iterator_type;
		typedef base_reverse_iterator	reverse_iterator_type;

	public:
		base_reverse_iterator(void):
			iterator_type() {};
		template	<typename Ptr>
		base_reverse_iterator(Ptr ptr):
			iterator_type(ptr) {};
		base_reverse_iterator(reverse_iterator_type const& rev_iter):
			iterator_type(rev_iter) {};
		base_reverse_iterator&	operator=(reverse_iterator_type const& rev_iter)
			{ return (static_cast<iterator_type*>(this)->operator=(rev_iter)); }
		~base_reverse_iterator(void) {};
		iterator_type	base(void) const
			{ iterator_type temp(*this); return (++temp); };
		reverse_iterator_type&	operator++(void)
		{
			static_cast<iterator_type*>(this)->operator--();
			return (*this);
		}
		reverse_iterator_type&	operator--(void)
		{
			static_cast<iterator_type*>(this)->operator++();
			return (*this);
		}
		reverse_iterator_type	operator++(int)
			{ return (static_cast<iterator_type*>(this)->operator--(0)); };
		reverse_iterator_type	operator--(int)
			{ return (static_cast<iterator_type*>(this)->operator++(0)); };
	};
};

#endif
