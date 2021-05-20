#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

# include <iterator>
# include "enable_if.hpp"

namespace	ft
{
	template	<typename Tp>
	class	vector_iterator;

	template	<typename Tp>
	vector_iterator<Tp>	operator+(int op, iterator const& it);

	template	<typename Tp>
	class	vector_iterator
	{
	protected:
		typedef vector_iterator<Tp>				iterator;
		typedef Tp*								ptr;

	public:
		typedef std::random_access_iterator_tag	iterator_category;
		typedef Tp								value_type;
		typedef Tp&								reference;
		typedef Tp*								pointer;
		typedef std::ptrdiff_t					difference_type;

	protected:
		reference	reverse_reference(void)
		{ return (--this->ptr); };

	public:
		vector_iterator(void):
			ptr(nullptr) {};
		vector_iterator(iterator const& iter):
			ptr(iter.pter) {};
		template	<typename _Tp>
		vector_iterator(vector_iterator<_Tp> const& iter):
			ptr(((iterator*)(&iter))->ptr)
		{
			typename ft::disable_if<is_const_of<Tp, _Tp>::value>::type* dummy;
			(void)dummy;
		};
		iterator&	operator=(iterator const& iter)
		{
			this->ptr = iter.ptr;
			return (*this);
		};
		template	<typename _Tp>
		iterator&	operator=(vector_iterator<_Tp> const& iter)
		{
			typename ft::enable_if<is_const_same<_Tp, Tp>::value>::type*	dummy;
			(void)dummy;
			this->ptr = ((iterator*)(&iter))->ptr;
			return (*this);
		};

		template	<typename _Tp>
		bool		operator==(vector_iterator<_Tp> const& iter) const
		{
			typename ft::enable_if<is_const_same<_Tp, Tp>::value>::type*	dummy;
			(void)dummy;
			return (this->ptr == ((iterator*)(&iter))->ptr);
		};
		template	<typename _Tp>
		bool		operator!=(vector_iterator<_Tp> const& iter) const
		{
			typename ft::enable_if<is_const_same<_Tp, Tp>::value>::type*	dummy;
			(void)dummy;
			return (this->ptr != ((iterator*)(&iter))->ptr);
		};
		pointer		operator->(void)
			{ return (&operator*()); };
		reference	operator*(void)
			{ return (ptr); };
		iterator&	operator++(void)
			{ ptr++; return (*this); };
		iterator&	operator--(void)
			{ ptr--; return (*this); };
		iterator	operator++(int)
		{
			iterator	temp(*this);
			ptr++;
			return (temp);
		};
		iterator	operator--(int)
		{
			iterator	temp(*this);
			ptr--;
			return (temp);
		};
		iterator	operator+(int op)
			{ ptr += op; return (*this) };
		iterator	operator-(int op)
			{ ptr -= op; return (*this) };
		int			operator-(iterator const& it)
			{ return (this->ptr - it.ptr); };
		iterator&	operator +=(int op)
			{ ptr += op; return (*this)  };
		iterator&	operator -=(int op)
			{ ptr -= op; return (*this)  };

		bool	operator<(iterator const& it) const
			{ return (this->ptr < it.ptr); };
		bool	operator>(iterator const& it) const
			{ return (this->ptr > it.ptr); };
		bool	operator<=(iterator const& it) const
			{ return (this->ptr <= it.ptr); };
		bool	operator>=(iterator const& it) const
			{ return (this->ptr >= it.ptr); };

		value_type&	operator[](int ind)
			{ return (*(ptr + ind)); };
	};

	template	<typename Tp>
	vector_iterator<Tp>	operator+(int op, iterator const& it)
		{ return (it + op); }
}

#endif