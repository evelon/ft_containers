#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

// # include <__config>
# include <memory>
# include <iostream>
# include "iterator.hpp"
# include "enable_if.hpp"
# include "reverse_iterator.hpp"
# include "relational_operator_impl.hpp"

namespace	ft
{
	template	<typename Tp>
	class	vector_iterator;

	template	<typename Tp>
	vector_iterator<Tp>	operator+(int op, vector_iterator<Tp> const& it);

	template	<typename T, typename U>
	bool	operator==(const vector_iterator<T>& lhs, const vector_iterator<U>& rhs);

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

	class	byte;

	class	bool_vector_reference;

	std::ostream&	operator<<(std::ostream& os, bool_vector_reference const& ref);

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

		vector_iterator(reverse_iterator<iterator>) {};

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
	};

	template	<typename T, typename U>
	bool	operator==(const vector_iterator<T>& lhs, const vector_iterator<U>& rhs)
	{
		typename enable_if<is_const_same<T, U>::value>::type*	dummy;
		(void)dummy;
		return (&*lhs == &*rhs);
	};

	template	<typename T, typename U>
	bool	operator<(const vector_iterator<T>& lhs, const vector_iterator<U>& rhs)
	{
		typename enable_if<is_const_same<T, U>::value>::type*	dummy;
		(void)dummy;
		return (&*lhs < &*rhs);
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

	class	byte
	{
	private:
		union	u_bitset
		{
			unsigned char	field;
			struct	s_bits
			{
				friend class	byte;
				unsigned char	_7 : 1;
				unsigned char	_6 : 1;
				unsigned char	_5 : 1;
				unsigned char	_4 : 1;
				unsigned char	_3 : 1;
				unsigned char	_2 : 1;
				unsigned char	_1 : 1;
				unsigned char	_0 : 1;
			}				bits;
		};

		union u_bitset	bitset;

	public:
		byte(void)
		{ bitset.field = 0; };
		byte(byte const& b)
		{ this->bitset.field = b.bitset.field; }
		~byte(void) {};
		byte&	operator=(unsigned char value)
		{
			bitset.field = value;
			return (*this);
		};
		unsigned char	operator>>(int const shift)
			{ return (bitset.field >> shift); };
		unsigned char	operator<<(int const shift)
			{ return (bitset.field << shift); };
		template	<typename T>
		unsigned char	operator|(T const& t)
			{ return (bitset.field | t); };
		template	<typename T>
		unsigned char	operator&(T const& t)
			{ return (bitset.field & t); };
		template	<typename T>
		unsigned char	operator^(T const& t)
			{ return (bitset.field ^ t); };
		byte&	operator>>=(int const shift)
			{ bitset.field >>= shift; return (*this); }
		byte&	operator<<=(int const shift)
			{ bitset.field <<= shift; return (*this); }
		template	<typename T>
		byte&	operator|=(T const& t)
			{ bitset.field |= t; return (*this); };
		template	<typename T>
		byte&	operator&=(T const& t)
			{ bitset.field &= t; return (*this); };
		template	<typename T>
		byte&	operator^=(T const& t)
			{ bitset.field ^= t; return (*this); };
		unsigned char	get_bitset(void)
			{ return (bitset.field); };
		void	set_bitset(unsigned char value)
			{ bitset.field = value; };
		void	set_bits(int bit, bool value)
		{
			switch(bit)
			{
				case 0:
					bitset.bits._0 = value;
					break ;
				case 1:
					bitset.bits._1 = value;
					break ;
				case 2:
					bitset.bits._2 = value;
					break ;
				case 3:
					bitset.bits._3 = value;
					break ;
				case 4:
					bitset.bits._4 = value;
					break ;
				case 5:
					bitset.bits._5 = value;
					break ;
				case 6:
					bitset.bits._6 = value;
					break ;
				case 7:
					bitset.bits._7 = value;
					break ;
			}
		}
		bool	get_bits(int bit)
		{
			switch(bit)
			{
				case 0:
					return (bitset.bits._0);
				case 1:
					return (bitset.bits._1);
				case 2:
					return (bitset.bits._2);
				case 3:
					return (bitset.bits._3);
				case 4:
					return (bitset.bits._4);
				case 5:
					return (bitset.bits._5);
				case 6:
					return (bitset.bits._6);
				case 7:
					return (bitset.bits._7);
			}
			return (false);
		}
	};

	class	bool_vector_reference
	{
	private:
		byte&			byte_;
		unsigned char	bit_offset_;

		bool_vector_reference(void);

	protected:
		bool_vector_reference(byte** const& head, size_t offset):
			byte_(*(*head + (offset >> 3))), bit_offset_(offset & 7) {};

	public:
		~bool_vector_reference(void) {};
		// convert to bool
		operator bool(void) const
			{return (byte_ >> bit_offset_ & 1); };
		// assign from bool
		bool_vector_reference&	operator=(const bool b)
		{
			byte_ &= ~(1 << bit_offset_);
			byte_ |= b << bit_offset_;
			return (*this);
		};
		// assign from bit
		bool_vector_reference&	operator=(const bool_vector_reference& b)
		{
			bool	bit = b.byte_ >> b.bit_offset_ & 1;
			byte_ &= ~(1 << bit_offset_);
			byte_ |= bit << bit_offset_;
			return (*this);
		};

		friend std::ostream&	operator<<(std::ostream& os, bool_vector_reference const& ref)
		{
			os << ((ref.byte_ >> ref.bit_offset_) & 1);
			return (os);
		};
		// flip bit value.
		void flip(void)
		{ byte_ ^= 1 << bit_offset_; };
	};

	template	<bool is_const>
	class	bit_iterator
	{
	private:
		typedef bit_iterator						iterator;
		typedef bool_vector_reference				bool_reference;
		typedef
			typename conditional<is_const, const byte, byte>::type
													byte_;
		typedef byte_*								byte_array_;

		template	<bool _is_const>
		void	is_compatible(bit_iterator<_is_const> const& iter) const
			{ (void)iter; };

	protected:
		class	internal_reference : public bool_reference
		{
		private:
			typedef bool_reference	base_reference;

			internal_reference(void) {};

		public:
			internal_reference(internal_reference const& ref):
				base_reference(ref) {};
			internal_reference(byte_array_* const& head, size_t offset):
				base_reference(head, offset) {};

		};

	public:
		typedef random_access_iterator_tag			iterator_category;
		typedef bool								value_type;
		typedef bool_reference						reference;
		typedef iterator							pointer;
		typedef std::ptrdiff_t						difference_type;
		typedef size_t								size_type;

	private:
		byte_array_*			head_;
		size_type const*	size_;
		difference_type		offset_;

	protected:
		reference	reverse_reference(void)
			{ return (internal_reference(head_, offset_ - 1)); };

		bit_iterator(byte_array_* const& head, size_type const& size, difference_type offset):
			head_(head),
			size_(&size),
			offset_(offset)
		{};

	public:
		bit_iterator(void):
			head_(NULL),
			size_(NULL),
			offset_(0)
		{};
		bit_iterator(iterator const& iter):
			head_(iter.head_),
			size_(iter.size_),
			offset_(iter.offset_)
		{}
		template	<bool _is_const>
		bit_iterator(
			bit_iterator<_is_const> const& iter,
			typename disable_if<_and<_is_const, _not<is_const>::value>::value>::type* = 0):
			head_(((iterator*)(&iter))->head_),
			size_(((iterator*)(&iter))->size_),
			offset_(((iterator*)(&iter))->offset_)
		{};
		virtual ~bit_iterator(void) {};

		iterator&	operator=(iterator const& iter)
		{
			this->head_ = iter.head_;
			this->size_ = iter.size_;
			this->offset_ = iter.offset_;
			return (*this);
		};
		template	<bool _is_const>
		iterator&	operator=(bit_iterator<_is_const> const& iter)
		{
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

		friend bool	operator==(const iterator& lhs, const iterator& rhs)
		{
			if (lhs.head_ != rhs.head_)
				return (false);
			if (lhs.offset_ != rhs.offset_)
				return (false);
			return (true);
		};
		friend bool operator<(const iterator& lhs, const iterator& rhs)
		{
			if (lhs.head_ != rhs.head_)
				return (false);
			return (lhs.offset_ < rhs.offset_);
		};
		friend difference_type	operator-(const iterator& lhs, const iterator& rhs)
		{
			return (lhs.offset_ - rhs.offset_);
		};
	};

	template	<bool is_const>
	bit_iterator<is_const>	operator+(int n, bit_iterator<is_const> const& it)
		{ return (it + n); };
}

#endif