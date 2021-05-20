#ifndef LIST_REVERSE_ITERATOR_HPP
# define LIST_REVERSE_ITERATOR_HPP

# include "list_iterator.hpp"

# include <iostream>
# include <iterator>

namespace	ft
{
	template <typename Iterator>
	class	base_reverse_iterator;

	template	<typename Iterator>
	base_reverse_iterator<Iterator>	operator+(int op, base_reverse_iterator<Iterator> const& rit);

	template <typename Iterator>
	class	base_reverse_iterator: public Iterator
	{
	private:
		typedef Iterator						iterator;
		typedef base_reverse_iterator			reverse_iterator;
		typedef typename iterator::value_type	value_type;
		typedef typename iterator::reference	reference;
		typedef typename iterator::pointer		pointer;

	public:
		base_reverse_iterator(void):
			iterator() {};
		template	<typename Ptr>
		base_reverse_iterator(Ptr ptr):
			iterator(ptr) {};
		base_reverse_iterator(reverse_iterator const& rev_iter):
			iterator(rev_iter) {};
		base_reverse_iterator(iterator const& iter):
			iterator(iter) {};
		~base_reverse_iterator(void) {};
		base_reverse_iterator&	operator=(reverse_iterator const& rev_iter)
		{
			static_cast<iterator*>(this)->operator=(rev_iter);
			return (*this);
		};

		pointer		operator->(void)
			{ return (&operator*()); };
		reference	operator*(void)
			{ return (this->reverse_reference()); };
		iterator	base(void) const
			{ iterator temp(*this); return (temp); };
		reverse_iterator&	operator++(void)
		{
			static_cast<iterator*>(this)->operator--();
			return (*this);
		}
		reverse_iterator&	operator--(void)
		{
			static_cast<iterator*>(this)->operator++();
			return (*this);
		}
		reverse_iterator	operator++(int)
		{
			reverse_iterator	temp(*this);
			static_cast<iterator*>(this)->operator--(0);
			return (temp);
		};
		reverse_iterator	operator--(int)
		{
			reverse_iterator	temp(*this);
			static_cast<iterator*>(this)->operator++(0);
			return (temp);
		};
		reverse_iterator	operator+(int op) const
			{ return (static_cast<iterator*>(this)->operator-(op)); };
		reverse_iterator	operator-(int op) const
			{ return (static_cast<iterator*>(this)->operator+(op)); };
		int					operator-(reverse_iterator const& rit) const
			{ return (static_cast<iterator*>(&rit)->operator-(*this)); };
		reverse_iterator&	operator +=(int op)
			{ return (static_cast<iterator*>(this)->operator-=(op)); };
		reverse_iterator&	operator -=(int op)
			{ return (static_cast<iterator*>(this)->operator+=(op)); };

		bool	operator<(reverse_iterator const& rit) const
			{ return (static_cast<iterator*>(this)->operator>=(rit)); };
		bool	operator>(reverse_iterator const& rit) const
			{ return (static_cast<iterator*>(this)->operator<=(rit)); };
		bool	operator<=(reverse_iterator const& rit) const
			{ return (static_cast<iterator*>(this)->operator>(rit)); };
		bool	operator>=(reverse_iterator const& rit) const
			{ return (static_cast<iterator*>(this)->operator<(rit)); };

		value_type&	operator[](int ind)
			{ return (*static_cast<iterator*>(this)->operator-=(ind)); };
	};

	template	<typename Iterator>
	base_reverse_iterator<Iterator>	operator+(int op, base_reverse_iterator<Iterator> const& rit)
		{ return (rit + op); }
};


#endif
