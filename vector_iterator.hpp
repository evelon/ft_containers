#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

// # include <__config>
# include "iterator.hpp"
# include "enable_if.hpp"
# include "reverse_iterator.hpp"
<<<<<<< HEAD
# include "vector.hpp"

=======
#include<iostream>
>>>>>>> commit
namespace	ft
{
	template	<typename Tp>
	class	vector_iterator;

	template	<typename Tp>
	vector_iterator<Tp>	operator+(int op, vector_iterator<Tp> const& it);

	template	<typename T, typename U>
	bool	operator==(const vector_iterator<T>& lhs, const vector_iterator<U>& rhs);

	template	<typename T, typename U>
	bool	operator!=(const vector_iterator<T>& lhs, const vector_iterator<U>& rhs);

	template	<typename T, typename U>
	bool	operator<(const vector_iterator<T>& lhs, const vector_iterator<U>& rhs);

	template	<typename T, typename U>
	bool	operator<=(const vector_iterator<T>& lhs, const vector_iterator<U>& rhs);

	template	<typename T, typename U>
	bool	operator>(const vector_iterator<T>& lhs, const vector_iterator<U>& rhs);

	template	<typename T, typename U>
	bool	operator>=(const vector_iterator<T>& lhs, const vector_iterator<U>& rhs);

	template	<typename Tp>
	vector_iterator<Tp>	operator+(int n, vector_iterator<Tp> const& it);

	template	<typename T, typename U>
	typename vector_iterator<T>::difference_type operator-(const vector_iterator<T>& lhs, const vector_iterator<U>& rhs);

	template	<>
	class	vector_iterator<bool>;

	// template	<>
	// vector_iterator<bool>	operator+(int op, vector_iterator<bool> const& it);

	// template <>
	// bool operator==(const vector_iterator<bool>& lhs, const vector_iterator<bool>& rhs);

	// template <>
	// bool operator!=(const vector_iterator<bool>& lhs, const vector_iterator<bool>& rhs);

	// template <>
	// bool operator<(const vector_iterator<bool>& lhs, const vector_iterator<bool>& rhs);

	// template <>
	// bool operator<=(const vector_iterator<bool>& lhs, const vector_iterator<bool>& rhs);

	// template <>
	// bool operator>(const vector_iterator<bool>& lhs, const vector_iterator<bool>& rhs);

	// template <>
	// bool operator>=(const vector_iterator<bool>& lhs, const vector_iterator<bool>& rhs);

	// template	<>
	// vector_iterator<bool>	operator+(int n, vector_iterator<bool> const& it);

	// template <>
	// typename vector_iterator<bool>::difference_type operator-(const vector_iterator<bool>& lhs, const vector_iterator<bool>& rhs);


	template	<typename Tp>
	class	vector_iterator
	{
	protected:
		typedef vector_iterator				iterator;

		template	<typename _Tp>
		void	is_compatible(vector_iterator<_Tp> const& iter,
			typename enable_if<is_const_same<_Tp, Tp>::value>::type* = 0) const
			{ (void)iter; };

	public:
		typedef random_access_iterator_tag	iterator_category;
		typedef Tp							value_type;
		typedef Tp&							reference;
		typedef Tp*							pointer;
		typedef ptrdiff_t					difference_type;
		typedef size_t						size_type;

	private:
		pointer*			head_;
		size_type const*	size_;
		difference_type		offset_;

	protected:
		reference	reverse_reference(void)
		{ return (*(*head_ + offset_ - 1)); };

		vector_iterator(pointer* const& head, size_type const& size, difference_type offset):
			head_(head),
			size_(&size),
			offset_(offset)
		{};

	public:
		vector_iterator(void):
			head_(nullptr),
			size_(nullptr),
			offset_(0)
		{};
		vector_iterator(iterator const& iter):
			head_(iter.head_),
			size_(iter.size_),
			offset_(iter.offset_)
		{}
		template	<typename _Tp>
		vector_iterator(
			vector_iterator<_Tp> const& iter,
			typename ft::disable_if<is_const_of<Tp, _Tp>::value>::type* = 0):
			head_(((iterator*)(&iter))->head_),
			size_(((iterator*)(&iter))->size_),
			offset_(((iterator*)(&iter))->offset_)
		{};
		virtual ~vector_iterator(void) {};

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
			iterator	temp(iter);
			this->head_ = temp.head_;
			this->size_ = temp.size_;
			this->offset_ = temp.offset_;
			return (*this);
		};

		reference	operator*(void) const
			{ return (*(*head_ + offset_)); };
		iterator	operator+(int op) const
		{
			iterator	new_it(*this);
			new_it.offset_ += op;
			return (new_it);
		};
		iterator&	operator++(void)
			{ offset_++; return (*this); };
		iterator	operator++(int)
		{
			iterator	temp(*this);
			offset_++;
			return (temp);
		};
		iterator&	operator+=(int op)
			{ offset_ += op; return (*this); };
		iterator	operator-(int op)
		{
			iterator	new_it(*this);
			new_it.offset_ -= op;
			return (new_it);
		};
		iterator&	operator--(void)
			{ offset_--; return (*this); };
		iterator	operator--(int)
		{
			iterator	temp(*this);
			offset_--;
			return (temp);
		};
		iterator&	operator-=(int op)
			{ offset_ -= op; return (*this); };
		pointer		operator->(void)
			{ return (&operator*()); };
		reference	operator[](int ind)
			{ return (*(*head_ + offset_ + ind)); };
	};

	template	<typename T, typename U>
	bool	operator==(const vector_iterator<T>& lhs, const vector_iterator<U>& rhs)
	{
		typename enable_if<is_const_same<T, U>::value>::type*	dummy;
		(void)dummy;
		return (&*lhs == &*rhs);
	};

	template	<typename T, typename U>
	bool	operator!=(const vector_iterator<T>& lhs, const vector_iterator<U>& rhs)
	{
		typename enable_if<is_const_same<T, U>::value>::type*	dummy;
		(void)dummy;
		return (&*lhs != &*rhs);
	};

	template	<typename T, typename U>
	bool	operator<(const vector_iterator<T>& lhs, const vector_iterator<U>& rhs)
	{
		typename enable_if<is_const_same<T, U>::value>::type*	dummy;
		(void)dummy;
		return (&*lhs < &*rhs);
	};

	template	<typename T, typename U>
	bool	operator<=(const vector_iterator<T>& lhs, const vector_iterator<U>& rhs)
	{
		typename enable_if<is_const_same<T, U>::value>::type*	dummy;
		(void)dummy;
		return (&*lhs <= &*rhs);
	};

	template	<typename T, typename U>
	bool	operator>(const vector_iterator<T>& lhs, const vector_iterator<U>& rhs)
	{
		typename enable_if<is_const_same<T, U>::value>::type*	dummy;
		(void)dummy;
		return (&*lhs > &*rhs);
	};

	template	<typename T, typename U>
	bool	operator>=(const vector_iterator<T>& lhs, const vector_iterator<U>& rhs)
	{
		typename enable_if<is_const_same<T, U>::value>::type*	dummy;
		(void)dummy;
		return (&*lhs >= &*rhs);
	};

	template	<typename Tp>
	vector_iterator<Tp>	operator+(int n, vector_iterator<Tp> const& it)
		{ return (it + n); };

	template	<typename T, typename U>
	typename vector_iterator<T>::difference_type operator-(
		const vector_iterator<T>& lhs,
		const vector_iterator<U>& rhs)
	{
		typename enable_if<is_const_same<T, U>::value>::type*	dummy;
		(void)dummy;
		return (&*lhs - &*rhs);
	};

	template	<>
	class	vector_iterator<bool>
	{
	private:
		typedef vector_iterator						iterator;
		typedef unsigned char						byte;
		typedef byte*								byte_array;
		typedef unsigned char						bit_offset;
		template	<typename B>
		void	is_compatible(vector_iterator<B> const& iter,
			typename enable_if<is_const_same<B, bool>::value>::type* = 0) const
			{ (void)iter; };

	protected:
		class	internal_reference : public vector<bool>::reference
		{
		private:
			typedef vector<bool>::reference	base_reference;
		public:
			internal_reference(byte_array* const& head, size_t offset):
				base_reference(head, offset) {};
		};

	public:
		typedef random_access_iterator_tag			iterator_category;
		typedef bool								value_type;
		typedef vector<bool>::reference				reference;
		typedef iterator							pointer;
		typedef std::ptrdiff_t						difference_type;
		typedef size_t								size_type;

	private:
		byte_array*			head_;
		size_type const*	size_;
		difference_type		offset_;

	protected:
		// reference	reverse_reference(void)
		// { return (*(*head_ + offset_ - 1)); };

		vector_iterator(byte_array* const& head, size_type const& size, difference_type offset):
			head_(head),
			size_(&size),
			offset_(offset)
		{};

	public:
		vector_iterator(void):
			head_(nullptr),
			size_(nullptr),
			offset_(0)
		{};
		vector_iterator(iterator const& iter):
			head_(iter.head_),
			size_(iter.size_),
			offset_(iter.offset_)
		{}
		template	<typename B>
		vector_iterator(
			vector_iterator<B> const& iter,
			typename ft::disable_if<is_const_of<bool, B>::value>::type* = 0):
			head_(((iterator*)(&iter))->head_),
			size_(((iterator*)(&iter))->size_),
			offset_(((iterator*)(&iter))->offset_)
		{};
		virtual ~vector_iterator(void) {};

		iterator&	operator=(iterator const& iter)
		{
			this->head_ = iter.head_;
			this->size_ = iter.size_;
			this->offset_ = iter.offset_;
			return (*this);
		};
		template	<typename B>
		iterator&	operator=(vector_iterator<B> const& iter)
		{
			typename ft::enable_if<is_const_same<bool, B>::value>::type*	dummy;
			(void)dummy;
			iterator	temp(iter);
			this->head_ = temp.head_;
			this->size_ = temp.size_;
			this->offset_ = temp.offset_;
			return (*this);
		};

		reference	operator*(void) const
			{ return (internal_reference(head_, offset_)); };
		iterator	operator+(int op) const
		{
			iterator	new_it(*this);
			new_it.offset_ += op;
			return (new_it);
		};
		iterator&	operator++(void)
			{ offset_++; return (*this); };
		iterator	operator++(int)
		{
			iterator	temp(*this);
			offset_++;
			return (temp);
		};
		iterator&	operator+=(int op)
			{ offset_ += op; return (*this); };
		iterator	operator-(int op)
		{
			iterator	new_it(*this);
			new_it.offset_ -= op;
			return (new_it);
		};
		iterator&	operator--(void)
			{ offset_--; return (*this); };
		iterator	operator--(int)
		{
			iterator	temp(*this);
			offset_--;
			return (temp);
		};
		iterator&	operator-=(int op)
			{ offset_ -= op; return (*this); };
		pointer		operator->(void)
			{ return (*this); };
		reference	operator[](int ind)
			{ return (internal_reference(head_, offset_ + ind)); };

	};

	// template	<>
	// vector_iterator<bool>	operator+(int op, vector_iterator<bool> const& it);

	// template <>
	// bool operator==(const vector_iterator<bool>& lhs, const vector_iterator<bool>& rhs);

	// template <>
	// bool operator!=(const vector_iterator<bool>& lhs, const vector_iterator<bool>& rhs);

	// template <>
	// bool operator<(const vector_iterator<bool>& lhs, const vector_iterator<bool>& rhs);

	// template <>
	// bool operator<=(const vector_iterator<bool>& lhs, const vector_iterator<bool>& rhs);

	// template <>
	// bool operator>(const vector_iterator<bool>& lhs, const vector_iterator<bool>& rhs);

	// template <>
	// bool operator>=(const vector_iterator<bool>& lhs, const vector_iterator<bool>& rhs);

	// template	<>
	// vector_iterator<bool>	operator+(int n, vector_iterator<bool> const& it);

	// template <>
	// typename vector_iterator<bool>::difference_type operator-(const vector_iterator<bool>& lhs, const vector_iterator<bool>& rhs);

}

#endif