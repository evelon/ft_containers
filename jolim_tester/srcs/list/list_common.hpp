#ifndef LIST_TEST_HPP
# define LIST_TEST_HPP

# include "../common.hpp"

# if NAMESPACE == FT
#  include "list.hpp"
# else
#  include <list>
# endif

typedef 	NS::list<A, std::allocator<A> >			listA;
typedef 	NS::list<int>			listInt;
typedef 	NS::list<std::string>	listStr;

template	<typename Tp>
void	receive_list(NS::list<Tp>) {}

#endif