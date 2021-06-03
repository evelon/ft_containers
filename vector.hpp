#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <limits>
# include <stdexcept>
# include "reverse_iterator.hpp"
# include "vector_iterator.hpp"


#include <bitset>

namespace	ft
{
	// template	<class Tp, class Alloc = std::allocator<Tp> >
	// class	vector;

	template	<class Alloc>
	class	vector<bool, Alloc>;

	template	<typename Tp>
	class	vector_iterator;

	template	<class T, class Alloc>
	bool	operator==(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs);

	template	<class T, class Alloc>
	bool	operator<(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs);

	template	<class T, class Alloc>
	void	swap(vector<T,Alloc>& x, vector<T,Alloc>& y);


	template	<>
	class	vector_iterator<bool>;

	bool	operator<(const vector<bool>& lhs, const vector<bool>& rhs);

	template	<class Tp, class Alloc>
	class	vector
	{
	private:
		typedef typename Alloc::template rebind<Tp*>::other	pointer_allocator;

	public:
		typedef Tp									value_type;
		typedef Alloc								allocator_type;
		typedef typename Alloc::reference			reference;
		typedef typename Alloc::const_reference		const_reference;
		typedef typename Alloc::pointer				pointer;
		typedef typename Alloc::const_pointer		const_pointer;
		typedef vector_iterator<const Tp>			const_iterator;
		typedef vector_iterator<Tp>					iterator;
		typedef reverse_iterator<const_iterator>	const_reverse_iterator;
		typedef reverse_iterator<iterator>			reverse_iterator;
		typedef ptrdiff_t							difference_type;
		typedef size_t								size_type;

	private:
		allocator_type		alloc_;
		pointer_allocator	ptrAlloc_;
		size_type			capacity_;
		pointer*			head_;
		size_type			size_;

		class	internal_iterator : public iterator
		{
		private:
			internal_iterator(void) {};
			internal_iterator(internal_iterator const&) {};
			internal_iterator&	operator=(internal_iterator const&) {};
		public:
			internal_iterator(pointer* const& head, size_type const& size, difference_type offset):
				iterator(head, size, offset)
			{};
			virtual ~internal_iterator(void) {};
		};

		size_type	determineCapacity(size_type new_size)
		{
			if (new_size > capacity_ * 2)
				return (new_size);
			return (capacity_ ? capacity_ * 2 : 1);
		};

	public:
		// Constructs an empty container, with no elements.
		explicit vector(const allocator_type& alloc = allocator_type()):
			alloc_(alloc),
			ptrAlloc_(pointer_allocator()),
			capacity_(0),
			head_(ptrAlloc_.allocate(1)),
			size_(0)
		{};
		// Constructs a container with "n" elements. Each element is a copy of "val".
		explicit vector(
			size_type n,
			const value_type& val = value_type(),
			const allocator_type& alloc = allocator_type()):
			alloc_(alloc),
			ptrAlloc_(pointer_allocator()),
			capacity_(n),
			head_(ptrAlloc_.allocate(1)),
			size_(n)
		{
			if (capacity_)
				*head_ = alloc_.allocate(capacity_);
			for (size_type i = 0; i < n; i++)
				(*head_)[i] = val;
		};
		// Constructs a container with as many elements as the range [first,last), with each element constructed from its corresponding element in that range, in the same order.
		template <class InputIterator>
		vector(
			InputIterator first,
			InputIterator last,
			const allocator_type& alloc = allocator_type(),
			typename disable_if<is_integral<InputIterator>::value>::type* = 0):
			alloc_(alloc),
			ptrAlloc_(pointer_allocator()),
			head_(ptrAlloc_.allocate(1))
		{
			size_type	n = 0;
			for (InputIterator it = first; it != last; it++)
				n++;
			capacity_ = n;
			if (n)
				*head_ = alloc_.allocate(capacity_);
			size_ = n;
			for (size_type i = 0; first != last;)
				(*head_)[i++] = *first++;
		};
		// Constructs a container with a copy of each of the elements in "vec", in the same order.
		vector(const vector& vec):
			capacity_(vec.size_),
			head_(ptrAlloc_.allocate(1)),
			size_(vec.size_)
		{
			*head_ = alloc_.allocate(capacity_);
			alloc_.allocate(this->capacity_);
			for (size_type i = 0; i < vec.size_; i++)
				(*this->head_)[i] = (*vec.head_)[i];
		};
		// Destroys all container elements, and deallocates all the storage capacity.
		~vector(void)
		{
			if (capacity_)
			{
				alloc_.deallocate(*head_, capacity_);
				ptrAlloc_.deallocate(head_, 1);
			}
		};
		vector&	operator=(const vector& vec)
		{
			if (capacity_)
				this->alloc_.deallocate(*this->head_, this->capacity_);
			if (this->capacity_ < vec.size_)
				this->capacity_ = vec.size_;
			*this->head_ = this->alloc_.allocate(capacity_);
			this->size_ = vec.size_;
			for (size_type i = 0; i < vec.size_; i++)
				(*this->head_)[i] = (*vec.head_)[i];
			return (*this);
		};
		// Returns an iterator pointing to the first element in the vector.
		iterator	begin(void)
			{ return (internal_iterator(head_, size_, 0)); };
		// Returns an const iterator pointing to the first element in the vector.
		const_iterator	begin(void) const
			{ return (const_iterator(internal_iterator(head_, size_, 0))); };
		// Returns an iterator referring to the past-the-end element in the vector container.
		iterator	end(void)
			{ return (internal_iterator(head_, size_, size_)); };
		// Returns an const iterator referring to the past-the-end element in the vector container.
		const_iterator	end(void) const
			{ return (const_iterator(internal_iterator(head_, size_, size_))); };
		// Returns a reverse iterator pointing to the last element in the vector, which iterates backwords.
		reverse_iterator	rbegin(void)
			{ return (reverse_iterator(internal_iterator(head_, size_, size_))); };
		// Returns a const reverse iterator pointing to the last element in the vector, which iterates backwords.
		const_reverse_iterator	rbegin(void) const
			{ return (const_reverse_iterator(internal_iterator(head_, size_, size_))); };
		// Returns a reverse iterator pointing to the theoretical element preceding the first element in the vector.
		reverse_iterator	rend(void)
			{ return (reverse_iterator(internal_iterator(head_, size_, 0))); };
		// Returns a const reverse iterator pointing to the theoretical element preceding the first element in the vector.
		const_reverse_iterator	rend(void) const
			{ return (const_reverse_iterator(internal_iterator(head_, size_, 0))); };
		// Returns the number of elements.
		size_type	size(void) const
			{ return (size_); };
		// Returns the maximum number of elements that a vector can hold.
		size_type	max_size(void) const
		{
			if (alloc_.max_size() < std::numeric_limits<size_type>::max())
				return (alloc_.max_size());
			return (std::numeric_limits<size_type>::max());
		};
		// Resizes the container so that it contains "n" elements.
		void	resize(size_type n, value_type val = value_type())
		{
			if (size_ < n)
			{
				if (capacity_ < n)
				{
					pointer	temp;
					temp = *head_;
					*head_ = alloc_.allocate(n);
					for (size_type i = 0; i < size_; i++ )
						(*head_)[i] = temp[i];
					if (capacity_)
						alloc_.deallocate(temp, capacity_);
					capacity_ = n;
				}
				for (size_type i = size_; i < n; i++)
					(*head_)[i] = val;
			}
			size_ = n;
		};
		// Returns the size of the storage space currently allocated for the vector, expressed in terms of elements.
		size_type	capacity(void) const
			{ return (capacity_); };
		// Returns whether the vector is empty.
		bool	empty(void) const
			{ return (size_ == 0); };
		// Requests that the vector capacity be at least enough to contain n elements.
		void	reserve(size_type n)
		{
			if (capacity_ >= n)
				return ;
			pointer	temp;
			temp = *head_;
			*head_ = alloc_.allocate(n);
			for (size_type i = 0; i < size_; i++ )
				(*head_)[i] = temp[i];
			if (capacity_)
				alloc_.deallocate(temp, capacity_);
			capacity_ = n;
		};
		reference	operator[](size_type n)
			{ return (*(*head_ + n)); };
		const_reference	operator[](size_type n) const
			{ return (*(*head_ + n)); };
		// Returns a reference to the element at position n in the vector. Checks boundary.
		reference	at(size_type n)
		{
			if (size_ <= n)
				throw (std::out_of_range("vector"));
			return (*(*head_ + n));
		};
		// Returns a reference to the element at position n in the vector. Checks boundary.
		const_reference	at(size_type n) const
		{
			if (size_ <= n)
				throw (std::out_of_range("vector"));
			return (*(*head_ + n));
		};
		// Returns a reference to the first element in the vector.
		reference		front(void)
			{ return (**head_); };
		// Returns a reference to the first element in the vector.
		const_reference	front(void) const
			{ return (**head_); };
		// Returns a reference to the last element in the vector.
		reference		back(void)
			{ return (*(*head_ + size_ - 1)); };
		// Returns a reference to the last element in the vector.
		const_reference	back(void) const
			{ return (*(*head_ + size_ - 1)); };
		// Assigns new contents ranging from "first" to "last" to the vector, replacing its current contents, and modifying its size accordingly.
		template	<class InputIterator>
		void	assign(
			InputIterator first,
			InputIterator last,
			typename ft::disable_if<is_integral<InputIterator>::value>::type* = 0)
		{
			size_type	diff = 0;
			for (InputIterator it = first; it != last; it++)
				diff++;
			if (diff > capacity_)
			{
				if (capacity_)
					alloc_.deallocate(*head_, capacity_);
				*head_ = alloc_.allocate(diff);
				capacity_ = diff;
			}
			for (size_type i = 0; first != last; first++)
				(*head_)[i++] = *first;
			size_ = diff;
		};
		// Assigns new contents to the vector, replacing its current contents, filling to "val" and modifying its size to "n" accordingly.
		void	assign(size_type n, const value_type& val)
		{
			if (n > capacity_)
			{
				if (capacity_)
					alloc_.deallocate(*head_, capacity_);
				*head_ = alloc_.allocate(n);
				capacity_ = n;
			}
			for (size_type i = 0; i < n; i++)
				(*head_)[i] = val;
			size_ = n;
		};
		// Adds a new element at the end of the vector, after its current last element.
		void	push_back(const value_type& val)
		{
			if (size_ == capacity_)
			{
				pointer	temp;
				temp = *head_;
				*head_ = alloc_.allocate(capacity_ ? capacity_ * 2 : 1);
				for (size_type i = 0; i < size_; i++ )
					(*head_)[i] = temp[i];
				if (capacity_)
					alloc_.deallocate(temp, capacity_);
				capacity_ = capacity_ ? capacity_ * 2 : 1;
			}
			(*head_)[size_++] = val;
		};
		// Removes the last element in the vector, effectively reducing the container size by one.
		void	pop_back(void)
			{ size_--; };
		// The vector is extended by inserting a new element before the element at the specified position, effectively increasing the container size..
		iterator	insert(iterator position, const value_type& val)
		{
			if (position < begin() || position > end())
				return (position);
			if (size_ == capacity_)
			{
				pointer	temp;
				temp = *head_;
				*head_ = alloc_.allocate(capacity_ ? capacity_ * 2 : 1);
				for (size_type i = 0; i < size_; i++ )
					(*head_)[i] = temp[i];
				if (capacity_)
					alloc_.deallocate(temp, capacity_);
				capacity_ = capacity_ ? capacity_ * 2 : 1;
			}
			if (size_)
				for (iterator it = end(); it > position && it > begin(); it--)
					*it = *(it - 1);
			*position = val;
			size_++;
			return (position);
		};
		// The vector is extended by inserting new elements, which of values are "val", before the element at the specified position, effectively increasing the container size by "n".
		void	insert(iterator position, size_type n, const value_type& val)
		{
			if (position < begin() || position > end())
				return ;
			if (size_ + n > capacity_)
			{
				pointer	temp;
				temp = *head_;
				size_type	new_capacity = size_ + n;
				*head_ = alloc_.allocate(new_capacity);
				for (size_type i = 0; i < size_; i++ )
					(*head_)[i] = temp[i];
				if (capacity_)
					alloc_.deallocate(temp, capacity_);
				capacity_ = new_capacity;
			}
			for (iterator it = end() - 1; it >= position; it--)
				*(it + n) = *it;
			for (size_type i = 0; i < n; i++)
				*(position++) = val;
			size_ += n;
		};
		template	<class InputIterator>
		void	insert(
			iterator position,
			InputIterator first,
			InputIterator last,
			typename ft::disable_if<is_integral<InputIterator>::value>::type* = 0)
		{
			if (position < begin() || position > end())
				return ;
			int	diff = 0;
			for (InputIterator it = first; it != last; it++)
				diff++;
			if (size_ + diff > capacity_)
			{
				pointer	temp;
				temp = *head_;
				size_type	new_capacity = determineCapacity(size_ + diff);
				*head_ = alloc_.allocate(new_capacity);
				for (size_type i = 0; i < size_; i++ )
					(*head_)[i] = temp[i];
				if (capacity_)
					alloc_.deallocate(temp, capacity_);
				capacity_ = new_capacity;
			}
			iterator	it = end() + diff - 1;
			for (iterator pos = position; pos < end(); pos++)
			{
				*it = *(it - diff);
				it--;
			}
			for (; first != last; first++)
				*(position++) = *first;
			size_ += diff;
		};
		// Removes from the vector a single element at "position"
		iterator	erase(iterator position)
		{
			if (position < begin() || position > end())
				return (position);
			for (iterator it = position; it <= end() - 1; it++)
				*it = *(it + 1);
			size_--;
			return (position);
		};
		// Removes from the vector a range of elements [first,last).
		iterator	erase(iterator first, iterator last)
		{
			iterator	ret = first;
			size_type	diff = last - first;
			while (last < end())
				*(first++) = *(last++);
			size_ -= diff;
			return (ret);
		};
		// Exchanges the content of the container by the content of x, which is another vector object of the same type.
		void	swap(vector& vec)
		{
			vector	temp = *this;
			*this = vec;
			vec = temp;
		};
		// Removes all elements from the vector (which are destroyed), leaving the container with a size of 0.
		void	clear(void)
			{ size_ = 0; };
		allocator_type	get_allocator(void) const
			{ return (allocator_type()); };
	};

	template	<class T, class Alloc>
	bool	operator==(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		typename vector<T, Alloc>::const_iterator lhs_it = lhs.begin();
		typename vector<T, Alloc>::const_iterator rhs_it = rhs.begin();
		while (lhs_it != lhs.end())
		{
			if (*(lhs_it++) != *(rhs_it++))
				return (false);
		}
		return (true);
	};

	template	<class T, class Alloc>
	bool	operator!=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
		{ return (!(lhs == rhs)); };

	template	<class T, class Alloc>
	bool	operator<(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		typename vector<T, Alloc>::const_iterator lhs_it = lhs.begin();
		typename vector<T, Alloc>::const_iterator rhs_it = rhs.begin();
		while (lhs_it != lhs.end() && rhs_it != rhs.end())
		{
			if (*lhs_it != *rhs_it)
				return (*lhs_it < *rhs_it);
			lhs_it++;
			rhs_it++;
		}
		return (lhs.size() < rhs.size());
	};

	template	<class T, class Alloc>
	void	swap(vector<T,Alloc>& x, vector<T,Alloc>& y)
	{
		vector<T, Alloc> temp = x;
		x = y;
		y = temp;
	};

	template	<class Alloc>
	class	vector<bool, Alloc>
	{
	private:
		typedef typename Alloc::size_type								storage_type_;
		typedef storage_type_*											storage_ptr_;
		typedef typename Alloc::template rebind<storage_type_>::other	storage_allocator_;
		typedef typename Alloc::template rebind<storage_ptr_>::other	storage_ptr_allocator_;
		typedef unsigned char											bit_offset_;

	public:
		typedef bool									value_type;
		typedef Alloc									allocator_type;
		typedef typename Alloc::const_reference			const_reference;
		typedef bit_iterator<false>						pointer;
		typedef bit_iterator<true>						const_pointer;
		typedef const_pointer							const_iterator;
		typedef pointer									iterator;
		typedef reverse_iterator<const_iterator>		const_reverse_iterator;
		typedef reverse_iterator<iterator>				reverse_iterator;
		typedef ptrdiff_t								difference_type;
		typedef size_t									size_type;

		class	reference : public bool_vector_reference<Alloc>
		{
		private:
			reference(void);

		protected:
			reference(storage_ptr_* const&, size_t);

		public:
			~reference(void);
			operator bool(void);
			reference&	operator=(const bool b);
			reference&	operator=(const reference& b);
			void flip(void);
		};

	private:
		static const size_type		storage_unit__ = 8 * sizeof(storage_type_);
		allocator_type				alloc_;
		storage_allocator_			storageAlloc_;
		storage_ptr_allocator_		storagePtrAlloc_;
		size_type					storageCapacity_;
		storage_ptr_*				storageHead_;
		size_type					size_;

		class	internal_iterator : public iterator
		{
		private:

			internal_iterator(void) {};
			internal_iterator(internal_iterator const&) {};
			internal_iterator&	operator=(internal_iterator const&) {};
		public:
			internal_iterator(vector::storage_ptr_* const& head, size_type const& size, difference_type offset):
				bit_iterator(head, size, offset)
			{};
			virtual ~internal_iterator(void) {};
		};

		size_type	determineCapacity(size_type new_size)
		{
			size_type	new_capacity = storageCapacity_;
			new_size = (new_size / storage_unit__) + ((new_size % storage_unit__) != 0);
			if (new_size > (max_size() >> 1))
				return (max_size());
			while (new_capacity < new_size)
				new_capacity <<= 1;
			if (new_capacity > storage_unit__)
				return (new_capacity);
			return (storage_unit__);
		}

		storage_type_	nth_bit(size_type nth, value_type bit)
		{
			storage_type_	bit_point = !!bit;
			size_type		t = nth;
			for (; t > 31; t -= 31)
				bit_point = bit_point << 31;
			return (bit_point << t);
		}

	public:
		// Constructs an empty container, with no elements.
		explicit vector(const allocator_type& alloc = allocator_type()):
			alloc_(alloc),
			storageAlloc_(storage_allocator_()),
			storagePtrAlloc_(storage_ptr_allocator_()),
			storageCapacity_(0),
			storageHead_(storagePtrAlloc_.allocate(1)),
			size_(0)
		{ *storageHead_ = storageAlloc_.allocate(0); };
		// Constructs a container with "n" elements. Each element is a copy of "val".
		explicit vector(
			size_type n,
			const value_type& val = value_type(),
			const allocator_type& alloc = allocator_type()):
			alloc_(alloc),
			storageAlloc_(storage_allocator_()),
			storagePtrAlloc_(storage_ptr_allocator_()),
			storageCapacity_((n / storage_unit__)+ (((n % storage_unit__) != 0))),
			storageHead_(storagePtrAlloc_.allocate(1)),
			size_(n)
		{
			*storageHead_ = storageAlloc_.allocate(storageCapacity_);
			if (val == false)
				memset(*storageHead_, 0, storageCapacity_ * sizeof(storage_type_));
			else
				memset(*storageHead_, ~0, storageCapacity_ * sizeof(storage_type_));
		};
		// Constructs a container with as many elements as the range [first,last), with each element constructed from its corresponding element in that range, in the same order.
		template <class InputIterator>
		vector(
			InputIterator first,
			InputIterator last,
			const allocator_type& alloc = allocator_type()):
			alloc_(alloc),
			storageAlloc_(storage_allocator_()),
			storagePtrAlloc_(storage_ptr_allocator_()),
			storageHead_(storagePtrAlloc_.allocate(1))
		{
			typename ft::disable_if<is_integral<InputIterator>::value>::type*	dummy;
			(void)dummy;
			size_type	n = 0;
			for (InputIterator it = first; it != last; it++)
				n++;
			storageCapacity_ = (n / storage_unit__) + ((n % storage_unit__) != 0);
			*storageHead_ = storageAlloc_.allocate(storageCapacity_);
			memset(*storageHead_, 0, storageCapacity_ * sizeof(storage_type_));
			size_ = n;
			for (size_type i = 0; first != last; i++)
			{
				if (*first)
					(*storageHead_)[i / storage_unit__] |= nth_bit(i % storage_unit__, !!*first);
				first++;
			}
		};
		// Constructs a container with a copy of each of the elements in "vec", in the same order.
		vector(const vector& vec):
			alloc_(vec.alloc_),
			storageAlloc_(vec.storageAlloc_),
			storagePtrAlloc_(vec.storagePtrAlloc_),
			storageCapacity_((vec.size_ / storage_unit__) + ((vec.size % storage_unit__) != 0)),
			storageHead_(storagePtrAlloc_.allocate(1)),
			size_(vec.size_)
		{
			*storageHead_ = storageAlloc_.allocate(storageCapacity_);
			for (size_type i = 0; i < storageCapacity_; i++)
				*storageHead_[i] = (*vec.storageHead_)[i];
		};
		// Destroys all container elements, and deallocates all the storage capacity.
		~vector()
		{
			storageAlloc_.deallocate(*storageHead_, storageCapacity_);
			storagePtrAlloc_.deallocate(storageHead_, 1);
		};
		vector&	operator=(const vector& vec)
		{
			this->storageAlloc_.deallocate(this->storageHead_, this->storageCapacity_);
			this->storageCapacity_ = (vec.size_ / storage_unit__) + ((vec.size_ % storage_unit__) != 0);
			this->capacity_ = vec.capacity_;
			*this->storageHead_ = this->storageAlloc_.allocate(storageCapacity_);
			this->size_ = vec.size_;
			for (size_type i = 0; i < (vec.size_ / storage_unit__ + ((vec.size_ % storage_unit__) != 0)); i++)
				(*this->storageHead_)[i] = (*vec.storageHead_)[i];
			return (*this);
		};
		// Returns an iterator pointing to the first element in the vector.
		iterator	begin(void)
			{ return (iterator(internal_iterator(storageHead_, size_, 0))); };
		// Returns an const iterator pointing to the first element in the vector.
		const_iterator	begin(void) const
			{ return (const_iterator(internal_iterator(storageHead_, size_, 0))); };
		// Returns an iterator referring to the past-the-end element in the vector container.
		iterator	end(void)
			{ return (iterator(internal_iterator(storageHead_, size_, size_))); };
		// Returns an const iterator referring to the past-the-end element in the vector container.
		const_iterator	end(void) const
			{ return (const_iterator(internal_iterator(storageHead_, size_, size_))); };
		// Returns a reverse iterator pointing to the last element in the vector, which iterates backwords.
		reverse_iterator	rbegin(void)
			{ return (reverse_iterator(internal_iterator(storageHead_, size_, size_))); };
		// Returns a const reverse iterator pointing to the last element in the vector, which iterates backwords.
		const_reverse_iterator	rbegin(void) const
			{ return (const_reverse_iterator(internal_iterator(storageHead_, size_, size_))); };
		// Returns a reverse iterator pointing to the theoretical element preceding the first element in the vector.
		reverse_iterator	rend(void)
			{ return (reverse_iterator(internal_iterator(storageHead_, size_, 0))); };
		// Returns a const reverse iterator pointing to the theoretical element preceding the first element in the vector.
		const_reverse_iterator	rend(void) const
			{ return (const_reverse_iterator(internal_iterator(storageHead_, size_, 0))); };
		// Returns the number of elements.
		size_type	size(void) const
			{ return (size_); };
		// Returns the maximum number of elements that a vector can hold.
		size_type	max_size(void) const
		{
			if (storageAlloc_.max_size() > std::numeric_limits<difference_type>::max())
				return (storageAlloc_.max_size());
			return (std::numeric_limits<difference_type>::max());
		};
		// Resizes the container so that it contains "n" elements.
		void	resize(size_type n, value_type val = value_type())
		{
			if (size_ < n)
			{
				val = !!val;
				if (storageCapacity_ << 3 < n)
				{
					storage_ptr_	temp = *storageHead_;
					size_type	old_capacity = storageCapacity_;
					storageCapacity_ = (n / storage_unit__) + ((n % storage_unit__) != 0);
					*storageHead_ = storageAlloc_.allocate(storageCapacity_);
					for (size_type i = 0; i < old_capacity; i++)
						(*storageHead_)[i] = temp[i];
					storageAlloc_.deallocate(temp, old_capacity);
				}
				if (((size_ % storage_unit__) != 0))
				{
					while (((size_ % storage_unit__) != 0) && size_ < n)
					{
						(*storageHead_)[size_ / storage_unit__].set_bits(size_ % storage_unit__, val);
						size_++;
					}
				}
				for (size_type i = size_ / storage_unit__; i < storageCapacity_; i++)
					memset(*storageHead_, val ? ~0 : 0 , storageCapacity_ * sizeof(storage_type_));
			}
			size_ = n;
		};
		// Returns the size of the storage space currently allocated for the vector, expressed in terms of elements.
		size_type	capacity(void) const
			{ return (storageCapacity_ * 8); };
		// Returns whether the vector is empty.
		bool	empty(void) const
			{ return (size_ == 0); };
		// Requests that the vector capacity be at least enough to contain n elements.
		void	reserve(size_type n)
		{
			if (storageCapacity_ >= (n << 3))
				return ;
			storage_ptr_	temp = *storageHead_;
			size_type		old_capacity = storageCapacity_;
			storageCapacity_ = (n / storage_unit__) + ((n % storage_unit__) != 0)
			*storageHead_ = storageAlloc_.allocate(storageCapacity_);
			for (int i = 0; i < size_; i++ )
				(*storageHead_)[i] = temp[i];
			storageAlloc_.deallocate(temp, old_capacity);
		};
		reference	operator[](size_type n)
			{ return (reference(storageHead_, n)); };
		const_reference	operator[](size_type n) const
			{ return (const_reference(storageHead_, n)); };
		// Returns a reference to the element at position n in the vector. Checks boundary.
		reference	at(size_type n)
		{
			if (size_ <= n)
				throw (std::out_of_range("vector"));
			return (reference(storageHead_, n));
		};
		// Returns a reference to the element at position n in the vector. Checks boundary.
		const_reference	at(size_type n) const
		{
			if (size_ <= n)
				throw (std::out_of_range("vector"));
			return (const_reference(storageHead_, n));
		};
		// Returns a reference to the first element in the vector.
		reference		front(void)
			{ return (reference(storageHead_, 0)); };
		// Returns a reference to the first element in the vector.
		const_reference	front(void) const
			{ return (const_reference(storageHead_, 0)); };
		// Returns a reference to the last element in the vector.
		reference		back(void)
			{ return (reference(storageHead_, size_)); };
		// Returns a reference to the last element in the vector.
		const_reference	back(void) const
			{ return (const_reference(storageHead_, size_)); };
		// Assigns new contents ranging from "first" to "last" to the vector, replacing its current contents, and modifying its size accordingly.
		template	<class InputIterator>
		void	assign(InputIterator first, InputIterator last)
		{
			typename ft::disable_if<is_integral<InputIterator>::value>::type*	dummy;
			(void)dummy;

			size_type	diff = 0;
			for (InputIterator it = first; it != last; it++)
				diff++;
			std::cout << ((diff / storage_unit__) + ((diff % storage_unit__) != 0)) << " " << std::endl;
			if ((diff / storage_unit__) + ((diff % storage_unit__) != 0) > storageCapacity_)
			{
				storageAlloc_.deallocate(*storageHead_, storageCapacity_);
				storageCapacity_ = (diff / storage_unit__) + ((diff % storage_unit__) != 0);
				*storageHead_ = storageAlloc_.allocate(storageCapacity_);
				memset(*storageHead_, 0, storageCapacity_ * sizeof(storage_type_));
			}
			for (size_type i = 0; first != last; first++)
			{
				std::cout << (i % storage_unit__) << std::endl;;
				if (*first)
					(*storageHead_)[i / storage_unit__] |= nth_bit(i % storage_unit__, !!*first);
				i++;
			}
			std::cout << std::endl;
			size_ = diff;
		};
		// Assigns new contents to the vector, replacing its current contents, filling to "val" and modifying its size to "n" accordingly.
		void	assign(size_type n, const value_type& val)
		{
			if ((n / storage_unit__) + ((n % storage_unit__) != 0) > storageCapacity_)
			{
				storageAlloc_.deallocate(*storageHead_, storageCapacity_);
				storageCapacity_ = (n / storage_unit__) + ((n % storage_unit__) != 0);
				*storageHead_ = storageAlloc_.allocate(storageCapacity_);
			}
			if (val)
				memset(*storageHead_, ~0, storageCapacity_ * sizeof(storage_type_));
			else
				memset(*storageHead_, 0, storageCapacity_ * sizeof(storage_type_));
			size_ = n;
		};
		// Adds a new element at the end of the vector, after its current last element.
		void	push_back(const value_type& val)
		{
			if (size_ == storageCapacity_ * storage_unit__)
			{
				storage_ptr_	temp = *storageHead_;
				*storageHead_ = storageAlloc_.allocate(storageCapacity_ * 2);
				for (size_type i = 0; i < storageCapacity_; i++ )
					(*storageHead_)[i] = temp[i];
				storageAlloc_.deallocate(temp, storageCapacity_);
				storageCapacity_ *= 2;
			}
			size_type	storage_size = 0;
			size_type	bit_position = size_;
			while (bit_position > storage_unit__)
			{
				storage_size++;
				bit_position -= storage_unit__;
			}
			if (val)
				(*storageHead_)[storage_size] |= nth_bit(bit_position, true);
			else
				(*storageHead_)[storage_size] &= ~nth_bit(bit_position, true);
			size_++;
		};
		// Removes the last element in the vector, effectively reducing the container size by one.
		void	pop_back()
			{ size_--; };
		// The vector is extended by inserting a new element before the element at the specified position, effectively increasing the container size..
		iterator	insert(iterator position, const value_type& val)
		{
			if (position < begin() || position > end())
				return (position);
			if (size_ == storageCapacity_ * storage_unit__)
			{
				storage_ptr_	temp = *storageHead_;
				*storageHead_ = storageAlloc_.allocate(storageCapacity_ * 2);
				for (size_type i = 0; i < storageCapacity_; i++ )
					(*storageHead_)[i] = temp[i];
				storageAlloc_.deallocate(temp, storageCapacity_);
				storageCapacity_ *= 2;
			}
			for (iterator it = end(); it >= position; it--)
				*it = *(it - 1);
			*position = !!val;
			size_++;
			return (position);
		};
		// The vector is extended by inserting new elements, which of values are "val", before the element at the specified position, effectively increasing the container size by "n".
		void	insert(iterator position, size_type n, const value_type& val)
		{
			if (position < begin() || position > end())
				return ;
			if (size_ + n >= storageCapacity_ * storage_unit__)
			{
				storage_ptr_	temp = *storageHead_;
				size_type		old_capacity = storageCapacity_;
				storageCapacity_ = determineCapacity(size_ + n);
				*storageHead_ = storageAlloc_.allocate(storageCapacity_);
				for (size_type i = 0; i < old_capacity; i++ )
					(*storageHead_)[i] = temp[i];
				storageAlloc_.deallocate(temp, old_capacity);
			}
			for (iterator it = end() + n; it >= position + n; it--)
				*it = *(it - n);
			for (iterator it = position; it != position + n; it++)
				*it = val;
			size_ += n;
		};
		template <class InputIterator>
		void	insert(iterator position, InputIterator first, InputIterator last)
		{
			typename ft::disable_if<is_integral<InputIterator>::value>::type*	dummy;
			(void)dummy;
			if (position < begin() || position > end())
				return ;

			size_type	diff = 0;
			for (iterator it = first; it != last; it++)
				diff++;
			if (size_ + diff >= storageCapacity_ * storage_unit__)
			{
				storage_ptr_	temp = *storageHead_;
				size_type		old_capacity = storageCapacity_;
				storageCapacity_ = determineCapacity(size_ + diff);
				*storageHead_ = storageAlloc_.allocate(storageCapacity_);
				for (size_type i = 0; i < old_capacity; i++ )
					(*storageHead_)[i] = temp[i];
				storageAlloc_.deallocate(temp, old_capacity);
			}
			for (iterator it = end() + diff; it >= position + diff; it--)
				*it = *(it - diff);
			for (iterator it = position; it != position + diff; it++)
				*it = *(first++);
			size_ += diff;
		};
		// Removes from the vector a single element at "position"
		iterator	erase(iterator position)
		{
			if (position < begin() || position > end())
				return (position);
			for (iterator it = position; it != end(); it++)
				*it = *(it + 1);
			size_--;
		};
		// Removes from the vector a range of elements [first,last).
		iterator	erase(iterator first, iterator last)
		{
			size_type diff = last - first;
			for (iterator it = first; it != last || it + diff != end(); it++)
				*it = *(it + diff);
			size_ -= diff;
		};
		// Exchanges the content of the container by the content of x, which is another vector object of the same type.
		void	swap(vector& vec)
		{
			vector	temp = *this;
			*this = vec;
			vec = temp;
		};

		static void swap (reference ref1, reference ref2)
		{
			bool	temp = ref1;
			ref1 = ref2;
			ref2 = temp;
		}
		// Removes all elements from the vector (which are destroyed), leaving the container with a size of 0.
		void	clear(void)
			{ size_ = 0; };
		allocator_type	get_allocator(void) const
			{ return (allocator_type()); };

		// Flips all values in the container: All instances of true become false, and all instances of false become true.
		void	flip(void)
		{
			for (size_type i = 0; i < size_ / storage_unit__; i++)
				~(*storageHead_)[i];
		}

		friend bool	operator<(const vector<bool>& lhs, const vector<bool>& rhs)
		{
			size_type	l_byte_size = lhs.size_ / storage_unit__;
			size_type	r_byte_size = rhs.size_ / storage_unit__;
			size_type	min_offset;

			for (min_offset = 0; min_offset < l_byte_size && min_offset < r_byte_size; min_offset++)
				if (lhs.storageHead_[min_offset] >= rhs.storageHead_[min_offset])
					return (false);

			min_offset <<= 3;
			size_type	l_remain = lhs.size_ - min_offset;
			size_type	r_remain = rhs.size_ - min_offset;

			for (size_type i = 0; i < l_remain && i < r_remain; i++)
				if (reference(rhs.storageHead_, min_offset + i) > reference(lhs.storageHead_, min_offset + 1))
					return (false);
			if (lhs.size_ >= rhs.size_)
				return (false);
			return (true);
		};
	};

	template	<class T, class Alloc>
	bool	operator==(const vector<bool>& lhs, const vector<bool>& rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		typename vector<bool>::const_iterator lhs_it = lhs.begin();
		typename vector<bool>::const_iterator rhs_it = rhs.begin();
		while (lhs_it != lhs.end())
		{
			if (*(lhs_it++) != *(rhs_it++))
				return (false);
		}
		return (true);
	};

	template	<class T, class Alloc>
	bool	operator!=(const vector<bool>& lhs, const vector<bool>& rhs)
		{ return (!(lhs == rhs)); };

	template	<class T, class Alloc>
	void	swap(vector<bool>& x, vector<bool>& y)
	{
		vector<bool> temp = x;
		x = y;
		y = temp;
	};
}

#endif
