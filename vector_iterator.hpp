#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

# include <__config>
# include "iterator.hpp"
# include "enable_if.hpp"

namespace	ft
{
	template	<typename Tp>
	class	vector_iterator;

	template	<typename Tp>
	vector_iterator<Tp>	operator+(int op, vector_iterator<Tp> const& it);

	template	<typename Tp>
	class	vector_iterator
	{
	protected:
		typedef vector_iterator<Tp>			iterator;

	public:
		typedef random_access_iterator_tag	iterator_category;
		typedef Tp							value_type;
		typedef Tp&							reference;
		typedef Tp*							pointer;
		typedef std::ptrdiff_t				difference_type;
		typedef size_t						size_type;

	private:
		pointer*		head_;
		size_type*		size_;
		difference_type	offset_;

	// protected:
	// 	reference	reverse_reference(void)
	// 	{ return (--this->ptr); };

	public:
		vector_iterator(void):
			head_(nullptr),
			size_(nullptr),
			offset_(0)
		{};
		vector_iterator(pointer& head, size_type& size, difference_type offset):
			head_(&head),
			size_(&size),
			offset_(offset)
		{};
		vector_iterator(iterator const& iter):
			head_(iter.head_),
			size_(iter.size_),
			offset_(iter.offset_)
		{}
		template	<typename _Tp>
		vector_iterator(vector_iterator<_Tp> const& iter):
			head_(iter.head_),
			size_(iter.size_),
			offset_(iter.offset_)
		{
			typename ft::disable_if<is_const_of<Tp, _Tp>::value>::type*	dummy;
			(void)dummy;
		};
		iterator&	operator=(iterator const& iter)
		{
			this->head_ = iter.head_;
			this->size_ = iter.size_;
			this->offset_ = iter.offset_;
			return (*this);
		};
		template	<typename _Tp>
		iterator&	operator=(vector_iterator<_Tp> const& iter)
		{
			typename ft::enable_if<is_const_same<_Tp, Tp>::value>::type*	dummy;
			(void)dummy;
			this->head_ = iter.head_;
			this->size_ = iter.size_;
			this->offset_ = iter.offset_;
			return (*this);
		};

		template	<typename _Tp>
		bool		operator==(vector_iterator<_Tp> const& iter) const
		{
			typename ft::enable_if<is_const_same<_Tp, Tp>::value>::type*	dummy;
			(void)dummy;
			if (this->head_ == iter.head_ && this->offset_ == iter.offset_)
				return (true);
			return (false);
		};
		template	<typename _Tp>
		bool		operator!=(vector_iterator<_Tp> const& iter) const
		{
			typename ft::enable_if<is_const_same<_Tp, Tp>::value>::type*	dummy;
			(void)dummy;
			if (this->head_ == iter.head_ && this->offset_ == iter.offset_)
				return (false);
			return (true);
		};
		pointer		operator->(void)
			{ return (&operator*()); };
		reference	operator*(void)
			{ return (*head_ + offset_); };
		iterator&	operator++(void)
			{ offset_++; return (*this); };
		iterator&	operator--(void)
			{ offset_--; return (*this); };
		iterator	operator++(int)
		{
			iterator	temp(*this);
			offset_++;
			return (temp);
		};
		iterator	operator--(int)
		{
			iterator	temp(*this);
			offset_--;
			return (temp);
		};
		iterator	operator+(int op)
			{ offset_ += op; return (*this) };
		iterator	operator-(int op)
			{ offset_ -= op; return (*this) };
		int			operator-(iterator const& it)
			{ return (this->offset_ - it.offset_); };
		iterator&	operator +=(int op)
			{ offset_ += op; return (*this)  };
		iterator&	operator -=(int op)
			{ offset_ -= op; return (*this)  };

		bool	operator<(iterator const& it) const
			{ return ((*this->head_ + this->offset_) < (*it.head_ + it.offset_); };
		bool	operator>(iterator const& it) const
			{ return ((*this->head_ + this->offset_) > (*it.head_ + it.offset_); };
		bool	operator<=(iterator const& it) const
			{ return ((*this->head_ + this->offset_) <= (*it.head_ + it.offset_); };
		bool	operator>=(iterator const& it) const
			{ return ((*this->head_ + this->offset_) >= (*it.head_ + it.offset_); };

		value_type&	operator[](int ind)
			{ return (*head_ + offset_ + ind); };
	};

	template	<typename Tp>
	vector_iterator<Tp>	operator+(int op, vector_iterator<Tp> const& it)
		{ return (it + op); }
}

#endif