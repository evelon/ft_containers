#ifndef VECTOR_HPP
# define VECOTOR_HPP

# include <memory>
# include <limits>
# include "vector_iterator.hpp"
# include "base_reverse_iterator.hpp"

namespace	ft
{
	template	<class Tp, class Alloc = std::allocator<Tp> >
	class	vector;

	template	<class Tp, class Alloc = std::allocator<Tp> >
	class	vector
	{
	private:
		typedef typename Alloc::template rebind<Tp*>::other	pointer_allocator;
	public:
		typedef Tp										value_type;
		typedef Alloc									allocator_type;
		typedef typename Alloc::reference				reference;
		typedef typename Alloc::const_reference			const_reference;
		typedef typename Alloc::pointer					pointer;
		typedef typename Alloc::const_pointer			const_pointer;
		typedef vector_iterator<Tp>						iterator;
		typedef vector_iterator<const Tp>				const_iterator;
		typedef base_reverse_iterator<iterator>			reverse_iterator;
		typedef base_reverse_iterator<const_iterator>	const_reverse_iterator;
		typedef ptrdiff_t								difference_type;
		typedef size_t									size_type;

	private:
		allocator_type		alloc_;
		pointer_allocator	ptrAlloc_;
		size_type			capacity_;
		pointer*			head_;
		size_type			size_;

		// size_type	determineCapacity(size_type n)
		// {
		// 	if (n < 8)
		// 		return (capacity_ = 8);
		// 	bit = 0;
		// 	while (n >>= 1)
		// 		bit++;
		// 	return (capacity_ = 1 << bit);
		// }

	public:
		// Constructs an empty container, with no elements.
		explicit vector(const allocator_type& alloc = allocator_type()):
			alloc_(alloc),
			ptrAlloc_(pointer_allocator()),
			capacity_(0),
			head_(ptrAlloc_.allocate(1)),
			size_(0);
		{};
		// Constructs a container with "n" elements. Each element is a copy of "val".
		explicit vector(
			size_type n,
			const value_type& val = value_type(),
			const allocator_type& alloc = allocator_type()):
			alloc_(alloc),
			capacity_(n),
			head_(alloc.allocate(capacity_)),
			size_(n)
		{
			for (int i = 0; i < n; i++)
				head_[i] = val;
		};
		// Constructs a container with as many elements as the range [first,last), with each element constructed from its corresponding element in that range, in the same order.
		template <class InputIterator>
		vector(
			InputIterator first,
			InputIterator last,
			const allocator_type& alloc = allocator_type()):
			alloc_(alloc)
		{
			typename ft::disable_if<is_integral<InputIterator>::value>::type* dummy;
			(void)dummy;
			size_type	n = 0;
			for (InputIterator it = first; it != last; it++)
				n++;
			capacity_ = n;
			head_ = alloc.allocate(capacity_);
			size = n;
			for (int i = 0; first != last; first++ && i++)
				head_[i] = *first;
		};
		// Constructs a container with a copy of each of the elements in "vec", in the same order.
		vector(const vector& vec):
			alloc_(vec.alloc_),
			capacity_(vec.size_),
			head_(alloc_.allocator(this->capacity_)),
			size_(vec.size_)
		{
			for (int i = 0; i < vec.size_; i++)
				(*this->head_)[i] = (*vec.head_)[i];
		};
		// Destroys all container elements, and deallocates all the storage capacity.
		~vector()
		{ alloc_.deallocate(head_, capacity_); };
		vector&	operator=(const vector& vec)
		{
			this->alloc_.deallocate(this->head_, this->capacity_);
			this->alloc_ = vec.alloc_;
			this->capacity_ = vec.capacity_;
			*this->head_ = this->alloc_.allocate(capacity_);
			this->size_ = vec.size_;
			for (int i = 0; i < vec.size_; i++)
				(*this->head_)[i] = (*vec.head_)[i];
			return (*this);
		};
		// Returns an iterator pointing to the first element in the vector.
		iterator begin(void)
			{ return (iterator(head_, size_, 0)); };
		// Returns an const iterator pointing to the first element in the vector.
		const_iterator begin(void) const
			{ return (const_iterator(head_, size_, 0)); };
		// Returns an iterator referring to the past-the-end element in the vector container.
		iterator end(void)
			{ return (iterator(head_, size_, size_)); };
		// Returns an const iterator referring to the past-the-end element in the vector container.
		const_iterator end(void) const
			{ return (const_iterator(head_, size_, size_)); };
		// Returns a reverse iterator pointing to the last element in the vector, which iterates backwords.
		reverse_iterator rbegin(void)
			{ return (reverse_iterator(head_, size_, size_)); };
		// Returns a const reverse iterator pointing to the last element in the vector, which iterates backwords.
		const_reverse_iterator rbegin(void) const
			{ return (const_reverse_iterator(head_, size_, size_)); };
		// Returns a reverse iterator pointing to the theoretical element preceding the first element in the vector.
		reverse_iterator rend(void)
			{ return (reverse_iterator(head_, size_, 0)); };
		// Returns a const reverse iterator pointing to the theoretical element preceding the first element in the vector.
		const_reverse_iterator rend(void) const
			{ return (const_reverse_iterator(head_, size_, 0)); };
		// Returns the number of elements.
		size_type size(void) const
			{ return (size_); };
		// Returns the maximum number of elements that a vector can hold.
		size_type max_size(void) const
		{
			if (alloc_.max_size() > std::numeric_limits<difference_type>::max())
				return (alloc_.max_size());
			return (std::numeric_limits<difference_type>::max());
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
					for (int i = 0; i < size_; i++ )
						(*head_)[i] = temp[i];
					alloc_.deallocate(temp, capacity_);
					capacity_ = n;
				}
				for (int i = size_; i < n; i++)
					(*head_)[i] = val;
			}
			size_ = n;
		};
		// Returns the size of the storage space currently allocated for the vector, expressed in terms of elements.
		size_type	capacity(void) const
			{ return (capacity_); };
		// Returns whether the vector is empty.
		bool	empty(void) const
			{ return (size_ == 0) };
		// Requests that the vector capacity be at least enough to contain n elements.
		void	reserve(size_type n)
		{
			if (capacity_ >= n)
				return ;
			pointer	temp;
			temp = *head_;
			*head_ = alloc_.allocate(n);
			for (int i = 0; i < size_; i++ )
				(*head_)[i] = temp[i];
			alloc_.deallocate(temp, capacity_);
			capacity_ = n;
		};
	};
}

#endif
