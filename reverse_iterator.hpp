#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "template_utils.hpp"
# include "relational_operator_impl.hpp"


#include <iostream>


namespace	ft
{
	template	<typename Iterator>
	class	reverse_iterator;

	template	<class Iterator>
	bool	operator==(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);

	template	<class Iterator>
	bool	operator!=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);

	template	<class Iterator>
	bool	operator<(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);

	template	<class Iterator>
	bool	operator<=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);

	template	<class Iterator>
	bool	operator>(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);

	template	<class Iterator>
	bool	operator>=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);

	template	<typename Iterator>
	reverse_iterator<Iterator>	operator+(int n, reverse_iterator<Iterator> const& rev_it);

	template	<class Iterator>
	typename reverse_iterator<Iterator>::difference_type	operator-
		(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);


	template	<typename Iterator>
	class	reverse_iterator: public Iterator
	{
	private:
		typedef reverse_iterator							iterator;

	public:
		typedef Iterator									iterator_type;
		typedef typename iterator_type::iterator_category	iterator_category;
		typedef typename iterator_type::value_type			value_type;
		typedef typename iterator_type::difference_type		difference_type;
		typedef typename iterator_type::pointer				pointer;
		typedef typename iterator_type::reference			reference;

	public:
		reverse_iterator(void):
			iterator_type() {};
		explicit reverse_iterator(iterator_type const& iter):
			iterator_type(iter) {};
		template	<class It>
		reverse_iterator(reverse_iterator<It> const& rev_iter):
			iterator_type(rev_iter)
			{ this->is_compatible(static_cast<It>(rev_iter)); };
		virtual ~reverse_iterator(void) {};
		reverse_iterator&	operator=(reverse_iterator const& rev_iter)
		{
			((iterator_type*)this)->operator=(rev_iter);
			return (*this);
		};
		iterator_type	base(void) const
			{ iterator_type temp(*this); return (temp); };
		reference	operator*(void)
			{ return (this->reverse_reference()); };
		reference	operator*(void) const
			{ return (this->reverse_reference()); };
		reverse_iterator	operator+(int op) const
			{ return (reverse_iterator(((iterator_type*)this)->operator-(op))); };
		reverse_iterator&	operator++(void)
		{
			((iterator_type*)this)->operator--();
			return (*this);
		}
		reverse_iterator	operator++(int)
		{
			reverse_iterator	temp(*this);
			((iterator_type*)this)->operator--(0);
			return (temp);
		};
		reverse_iterator&	operator+=(int op)
			{ ((iterator_type*)this)->operator-=(op); return (*this); };
		reverse_iterator	operator-(int op) const
			{ return (reverse_iterator(((iterator_type*)this)->operator+(op))); };

		reverse_iterator&	operator--(void)
		{
			((iterator_type*)this)->operator++();
			return (*this);
		}
		reverse_iterator	operator--(int)
		{
			reverse_iterator	temp(*this);
			((iterator_type*)this)->operator++(0);
			return (temp);
		};
		reverse_iterator&	operator-=(int op)
			{ ((iterator_type*)this)->operator+=(op); return (*this); };
		pointer		operator->(void)
			{ return (&operator*()); };
		pointer		operator->(void) const
			{ return (&operator*()); };
		reference	operator[](int ind)
			{ return (*(*this + ind)); };
		reference	operator[](int ind) const
			{ return (*(*this + ind)); };
	};

	template	<class Iterator>
	bool	operator==(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
		{ return (static_cast<Iterator>(lhs) == static_cast<Iterator>(rhs)); };

	template	<class Iterator>
	bool	operator!=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
		{ return (static_cast<Iterator>(lhs) != static_cast<Iterator>(rhs)); };

	template	<class Iterator>
	bool	operator<(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
		{ return (static_cast<Iterator>(lhs) < static_cast<Iterator>(rhs)); };

	template	<class Iterator>
	bool	operator<=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
		{ return (static_cast<Iterator>(lhs) <= static_cast<Iterator>(rhs)); };

	template	<class Iterator>
	bool	operator>(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
		{ return (static_cast<Iterator>(lhs) > static_cast<Iterator>(rhs)); };

	template	<class Iterator>
	bool	operator>=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
		{ return (static_cast<Iterator>(lhs) >= static_cast<Iterator>(rhs)); };

	template	<class Iterator>
	reverse_iterator<Iterator>	operator+(int n, reverse_iterator<Iterator> const& rev_it)
		{ return (rev_it + n); };

	template	<class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator-(
		const reverse_iterator<Iterator>& lhs,
		const reverse_iterator<Iterator>& rhs)
	{
		return (static_cast<Iterator>(rhs) - static_cast<Iterator>(lhs));
	};

	template	<class It, class _It>
	typename reverse_iterator<It>::difference_type operator-(
		const reverse_iterator<It>& lhs,
		const reverse_iterator<_It>& rhs)
	{

		return (static_cast<Iterator>(rhs) - static_cast<Iterator>(lhs));
	};

	template	<class Iterator>
	bool	operator==(const Iterator& lhs, const reverse_iterator<Iterator>& rhs)
	{
		typename enable_if<is_const_same<Iterator, reverse_iterator<Iterator> >::value>::type* dummy;
		(void)dummy;
		return (lhs == rhs);
	};

	template	<class Iterator>
	bool	operator==(const reverse_iterator<Iterator>& lhs, const Iterator& rhs)
	{
		typename enable_if<is_const_same<Iterator, reverse_iterator<Iterator> >::value>::type* dummy;
		(void)dummy;
		return (lhs == rhs);
	};

	template	<class Iterator>
	bool	operator<(const Iterator& lhs, const reverse_iterator<Iterator>& rhs)
	{
		typename enable_if<is_const_same<Iterator, reverse_iterator<Iterator> >::value>::type* dummy;
		(void)dummy;
		return (lhs < rhs);
	};

	template	<class Iterator>
	bool	operator<(const reverse_iterator<Iterator>& lhs, const Iterator& rhs)
	{
		typename enable_if<is_const_same<Iterator, reverse_iterator<Iterator> >::value>::type* dummy;
		(void)dummy;
		return (lhs < rhs);
	};
};


#endif
