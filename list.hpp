#include <memory>

namespace ft
{
	template	<typename Tp, class Alloc = std::allocator<Tp> > class list;

	template	<typename Tp, class Alloc>
	class	list
	{
	private:

	public:
		typedef Tp								Value_type;
		typedef Alloc							allocator_type;
		typedef typename Alloc::reference		reference;
		typedef typename Alloc::const_reference	const_reference;
		typedef typename Alloc::pointer			pointer;
		typedef typename Alloc::const_pointer	const_pointer;
	};
}