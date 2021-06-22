#ifndef LIST_TEST_HPP
# define LIST_TEST_HPP

# include "../common.hpp"

# if NS == ft
#  include "list.hpp"
# else
#  include <list>
# endif

typedef 	ft::list<A, std::allocator<A> >listA;

template	<typename Tp>
void	receive_list(NS::list<Tp>) {}

#endif