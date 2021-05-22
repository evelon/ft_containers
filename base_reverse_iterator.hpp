#ifndef LIST_REVERSE_ITERATOR_HPP
# define LIST_REVERSE_ITERATOR_HPP

# include "list_iterator.hpp"

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
		typedef base_reverse_iterator						reverse_iterator;

	public:
		typedef Iterator									iterator_type;
		typedef typename iterator_type::iterator_category	iterator_category;
		typedef typename iterator_type::value_type			value_type;
		typedef typename iterator_type::difference_type		difference_type;
		typedef typename iterator_type::pointer				pointer;
		typedef typename iterator_type::reference			reference;

	public:
		base_reverse_iterator(void):
			iterator_type() {};
		explicit base_reverse_iterator(iterator_type const& iter):
			iterator_type(iter) {};
		template	<class It>
		base_reverse_iterator(base_reverse_iterator<It> const& rev_iter):
			iterator_type(rev_iter)
		{
			// typename enable_if<is_const_same<typename Iterator::value_type, typename It::value_type>::value>::type* dummy;
			// (void)dummy;
			Iterator	dummy1;
			It			dummy2;
			(void)(dummy1 == dummy2);
		};
		~base_reverse_iterator(void) {};
		base_reverse_iterator&	operator=(reverse_iterator const& rev_iter)
		{
			static_cast<iterator_type*>(this)->operator=(rev_iter);
			return (*this);
		};

		pointer		operator->(void)
			{ return (&operator*()); };
		reference	operator*(void)
			{ return (this->reverse_reference()); };
		iterator_type	base(void) const
			{ iterator_type temp(*this); return (temp); };
		reverse_iterator&	operator++(void)
		{
			static_cast<iterator_type*>(this)->operator--();
			return (*this);
		}
		reverse_iterator&	operator--(void)
		{
			static_cast<iterator_type*>(this)->operator++();
			return (*this);
		}
		reverse_iterator	operator++(int)
		{
			reverse_iterator	temp(*this);
			static_cast<iterator_type*>(this)->operator--(0);
			return (temp);
		};
		reverse_iterator	operator--(int)
		{
			reverse_iterator	temp(*this);
			static_cast<iterator_type*>(this)->operator++(0);
			return (temp);
		};
		reverse_iterator	operator+(int op) const
			{ return (static_cast<iterator_type*>(this)->operator-(op)); };
		reverse_iterator	operator-(int op) const
			{ return (static_cast<iterator_type*>(this)->operator+(op)); };
		int					operator-(reverse_iterator const& rit) const
			{ return (static_cast<iterator_type*>(&rit)->operator-(*this)); };
		reverse_iterator&	operator +=(int op)
			{ return (static_cast<iterator_type*>(this)->operator-=(op)); };
		reverse_iterator&	operator -=(int op)
			{ return (static_cast<iterator_type*>(this)->operator+=(op)); };

		bool	operator<(reverse_iterator const& rit) const
			{ return (static_cast<iterator_type*>(this)->operator>=(rit)); };
		bool	operator>(reverse_iterator const& rit) const
			{ return (static_cast<iterator_type*>(this)->operator<=(rit)); };
		bool	operator<=(reverse_iterator const& rit) const
			{ return (static_cast<iterator_type*>(this)->operator>(rit)); };
		bool	operator>=(reverse_iterator const& rit) const
			{ return (static_cast<iterator_type*>(this)->operator<(rit)); };

		value_type&	operator[](int ind)
			{ return (*static_cast<iterator_type*>(this)->operator-=(ind)); };
	};

	template	<typename Iterator>
	base_reverse_iterator<Iterator>	operator+(int op, base_reverse_iterator<Iterator> const& rit)
		{ return (rit + op); }
};


#endif
