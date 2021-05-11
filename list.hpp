#include <memory>

namespace ft
{
	template	<typename T, class Alloc = std::allocator<T> > class list;

	template	<typename T, class Alloc>
	class	list
	{
	private:

	public:
		typedef T								Value_type;
		typedef Alloc							allocator_type;
		typedef	typename Alloc::reference		reference;
		typedef	typename Alloc::const_reference	const_reference;
		typedef	typename Alloc::pointer			pointer;
		typedef	typename Alloc::const_pointer	const_pointer;
	};
}