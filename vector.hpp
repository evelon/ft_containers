#ifndef VECTOR_HPP
# define VECOTOR_HPP

# include <memory>
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
	};
}


#endif
