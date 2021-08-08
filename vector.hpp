#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <limits>
# include <stdexcept>
# include "reverse_iterator.hpp"
# include "vector_iterator.hpp"

namespace	ft
{
	// template	<class Tp, class Alloc = std::allocator<Tp> >
	// class	vector;

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
			for (InputIterator it = first; it != last; ++it)
				diff++;
			if (diff > capacity_)
			{
				if (capacity_)
					alloc_.deallocate(*head_, capacity_);
				*head_ = alloc_.allocate(diff);
				capacity_ = diff;
			}
			for (size_type i = 0; first != last; ++first)
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
			for (size_type i = 0; i < n; ++i)
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
				for (size_type i = 0; i < size_; ++i)
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
				for (size_type i = 0; i < size_; ++i)
					(*head_)[i] = temp[i];
				if (capacity_)
					alloc_.deallocate(temp, capacity_);
				capacity_ = capacity_ ? capacity_ * 2 : 1;
			}
			if (size_)
				for (iterator it = end(); it > position && it > begin(); --it)
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
				for (size_type i = 0; i < size_; ++i)
					(*head_)[i] = temp[i];
				if (capacity_)
					alloc_.deallocate(temp, capacity_);
				capacity_ = new_capacity;
			}
			for (iterator it = end() - 1; it >= position; --it)
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
			for (InputIterator it = first; ft::operator!=(it, last); it++)
				++diff;
			if (size_ + diff > capacity_)
			{
				pointer	temp;
				temp = *head_;
				size_type	new_capacity = determineCapacity(size_ + diff);
				*head_ = alloc_.allocate(new_capacity);
				for (size_type i = 0; i < size_; ++i)
					(*head_)[i] = temp[i];
				if (capacity_)
					alloc_.deallocate(temp, capacity_);
				capacity_ = new_capacity;
			}
			iterator	it = end() + diff - 1;
			for (iterator pos = position; pos < end(); ++pos)
			{
				*it = *(it - diff);
				it--;
			}
			for (; ft::operator!=(first, last); ++first)
				*(position++) = *first;
			size_ += diff;
		};
		// Removes from the vector a single element at "position"
		iterator	erase(iterator position)
		{
			if (position < begin() || position > end())
				return (position);
			for (iterator it = position; it < end() - 1; ++it)
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
		// Exchanges the content of the container by the content of vec, which is another vector object of the same type.
		void	swap(vector& vec)
		{
			size_type	temp_cap = this->capacity_;
			pointer*	temp_head = this->head_;
			size_type	temp_size = this->size_;
			this->capacity_ = vec.capacity_;
			this->head_ = vec.head_;
			this->size_ = vec.size_;
			vec.capacity_ = temp_cap;
			vec.head_ = temp_head;
			vec.size_ = temp_size;
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
}

#endif
