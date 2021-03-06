#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

// # include <__config>
# include <memory>
# include <iostream>
# include "iterator.hpp"
# include "template_utils.hpp"
# include "reverse_iterator.hpp"
# include "relational_operator_impl.hpp"

namespace	ft
{
	template	<typename Tp>
	class	vector_iterator;

	template	<typename Tp>
	vector_iterator<Tp>	operator+(int op, vector_iterator<Tp> const& it);

	// template	<typename T, typename U>
	// bool	operator==(vector_iterator<T> lhs, vector_iterator<U> const& rhs);

	template	<typename T, typename U>
	bool	operator<(const vector_iterator<T>& lhs, const vector_iterator<U>& rhs);

	template	<typename Tp>
	vector_iterator<Tp>	operator+(int n, vector_iterator<Tp> const& it);

	template	<typename T, typename U>
	typename vector_iterator<T>::difference_type operator-(const vector_iterator<T>& lhs, const vector_iterator<U>& rhs);

	template	<>
	class	vector_iterator<bool>;

	template	<typename Tp, class Alloc = std::allocator<Tp> >
	class	vector;

	template	<class Alloc>
	class	vector<bool, Alloc>;

	class	storage_type_;

	template	<class Alloc = std::allocator<bool> >
	class	bool_vector_reference;

	template	<bool is_const, class Alloc = std::allocator<bool> >
	class	bit_iterator;

	template	<class Alloc>
	std::ostream&	operator<<(std::ostream& os, bool_vector_reference<Alloc> const& ref);

	// template	<>
	// vector_iterator<bool>	operator+(int op, vector_iterator<bool> const& it);

	// template <>
	// bool operator==(const vector_iterator<bool>& lhs, const vector_iterator<bool>& rhs);

	// template <>
	// bool operator<(const vector_iterator<bool>& lhs, const vector_iterator<bool>& rhs);

	// template	<>
	// vector_iterator<bool>	operator+(int n, vector_iterator<bool> const& it);

	// template <>
	// typename vector_iterator<bool>::difference_type operator-(const vector_iterator<bool>& lhs, const vector_iterator<bool>& rhs);


	template	<typename Tp>
	class	vector_iterator
	{
	private:
		typedef vector_iterator				iterator;
		void	type_check(void);

	protected:
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

		vector_iterator(reverse_iterator<iterator> const& rit):
			head_(rit.head_),
			size_(rit.size_),
			offset_(rit.size_)
		{};

		vector_iterator(pointer* const& head, size_type const& size, difference_type offset):
			head_(head),
			size_(&size),
			offset_(offset)
		{};

	public:
		vector_iterator(void):
			head_(NULL),
			size_(NULL),
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

		template	<typename _Tp>
		bool	operator==(vector_iterator<_Tp> const& rhs) const
		{
			typename enable_if<is_const_same<Tp, _Tp>::value>::type*	dummy;
			(void)dummy;
			return
			(
				this->head_ == ((iterator*)(&rhs))->head_
				&&
				this->offset_ == ((iterator*)(&rhs))->offset_
			);
		};

		template	<typename _Tp>
		bool	operator<(vector_iterator<_Tp> const& rhs) const
		{
			typename enable_if<is_const_same<Tp, _Tp>::value>::type*	dummy;
			(void)dummy;
			return (&**this < &*rhs);
		};
	};


	template	<typename Tp>
	bool		operator==(reverse_iterator<vector_iterator<Tp> > const&, vector_iterator<Tp> const&)
	{ typename disable_if<is_same<Tp, Tp>::value>::type* dummy; (void)dummy; }

	template	<typename Tp>
	bool		operator==(vector_iterator<Tp> const&, reverse_iterator<vector_iterator<Tp> > const&)
	{ typename disable_if<is_same<Tp, Tp>::value>::type* dummy; (void)dummy; }

	template	<typename Tp>
	bool		operator<(reverse_iterator<vector_iterator<Tp> > const&, vector_iterator<Tp> const&)
	{ typename disable_if<is_same<Tp, Tp>::value>::type* dummy; (void)dummy; }

	template	<typename Tp>
	bool		operator<(vector_iterator<Tp> const&, reverse_iterator<vector_iterator<Tp> > const&)
	{ typename disable_if<is_same<Tp, Tp>::value>::type* dummy; (void)dummy; }

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

	template	<class Alloc>
	class	bool_vector_reference
	{
	private:
		typedef typename Alloc::size_type	size_type;
		typedef size_type					storage_type_;

		static const size_type				storage_unit__ = 8 * sizeof(storage_type_);
		static const size_type				full_bits__ = storage_unit__ - 1;
		static const size_type				storage_bits__ = logarithm<storage_unit__, 2>::value;
		storage_type_&						storage_;
		unsigned char						bit_offset_;

		bool_vector_reference(void);

	protected:
		bool_vector_reference(storage_type_** const& head, size_type offset):
			storage_(*(*head + (offset / storage_unit__))), bit_offset_(offset & full_bits__) {};

	public:
		~bool_vector_reference(void) {};
		// convert to bool
		operator bool(void) const
			{return (storage_ >> bit_offset_ & 1); };
		// assign from bool
		bool_vector_reference&	operator=(const bool b)
		{
			storage_ &= ~(1 << bit_offset_);
			storage_ |= b << bit_offset_;
			return (*this);
		};
		// assign from bit
		bool_vector_reference&	operator=(const bool_vector_reference& b)
		{
			bool	bit = (b.storage_ >> b.bit_offset_) & 1;
			storage_ &= ~(1 << bit_offset_);
			storage_ |= bit << bit_offset_;
			return (*this);
		};

		friend std::ostream&	operator<<(std::ostream& os, bool_vector_reference const& ref)
		{
			os << ((ref.storage_ >> ref.bit_offset_) & 1);
			return (os);
		};
		// flip bit value.
		void flip(void)
		{ storage_ ^= 1 << bit_offset_; };
	};
}

#endif
