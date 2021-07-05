#ifndef LIST_COMMON_HPP
# define LIST_COMMON_HPP

# include "../common.hpp"

# if NAMESPACE == FT
#  include "list.hpp"
# else
#  include <list>
# endif

typedef NS::list<A, std::allocator<A> >			listA;
typedef NS::list<int>			listInt_o;
typedef NS::list<wrapper<int> >	listInt;
typedef NS::list<std::string>	listStr;
typedef NS::list<float>			listFloat_o;
typedef NS::list<wrapper<float> >			listFloat;
typedef NS::list<listA::size_type>		listSize;

template	<typename Tp>
void	receive_list(NS::list<Tp>) {}

#endif