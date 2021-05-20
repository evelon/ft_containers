#ifndef LIST_REVERSE_ITERATOR_HPP
# define LIST_REVERSE_ITERATOR_HPP

# include "list_iterator.hpp"

# include <iostream>
# include <iterator>

namespace	ft
{
	template <typename Iterator>
	class	base_reverse_iterator;

	template <typename Iterator>
	class	base_reverse_iterator: public Iterator
	{
	private:
		typedef Iterator							iterator_type;
		typedef base_reverse_iterator				reverse_iterator_type;
		typedef typename iterator_type::value_type	value_type;
		typedef typename iterator_type::reference	reference;
		typedef typename iterator_type::pointer		pointer;

	public:
		base_reverse_iterator(void):
			iterator_type() {};
		template	<typename Ptr>
		base_reverse_iterator(Ptr ptr):
			iterator_type(ptr) {};
		base_reverse_iterator(reverse_iterator_type const& rev_iter):
			iterator_type(rev_iter) {};
		base_reverse_iterator(iterator_type const& iter):
			iterator_type(iter) {};
		base_reverse_iterator&	operator=(reverse_iterator_type const& rev_iter)
		{
			static_cast<iterator_type*>(this)->operator=(rev_iter);
			return (*this);
		};
		~base_reverse_iterator(void) {};

		pointer		operator->(void)
			{ return (&operator*()); };
		reference	operator*(void)
		{ return (static_cast<iterator_type*>(this)->reverse_reference()); };
		iterator_type	base(void) const
			{ iterator_type temp(*this); return (temp); };
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
		{
			reverse_iterator_type	temp(*this);
			static_cast<iterator_type*>(this)->operator--(0);
			return (temp);
		};
		reverse_iterator_type	operator--(int)
		{
			reverse_iterator_type	temp(*this);
			static_cast<iterator_type*>(this)->operator++(0);
			return (temp);
		};
	};
};

#endif
