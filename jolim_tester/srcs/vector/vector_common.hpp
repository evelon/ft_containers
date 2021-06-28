#ifndef VECTOR_TEST_HPP
# define VECTOR_TEST_HPP

# include "../common.hpp"

# if NAMESPACE == FT
#  include "vector.hpp"
# else
#  include <vector>
# endif

typedef NS::vector<A, std::allocator<A> >	vecA;
typedef NS::vector<int>						vecInt_o;
typedef NS::vector<wrapper<int> >			vecInt;
typedef NS::vector<std::string>				vecStr;
typedef NS::vector<float>					vecFloat_o;
typedef NS::vector<wrapper<float> >			vecFloat;
typedef NS::vector<vecA::size_type>		vecSize;

template	<typename Tp>
void	receive_list(NS::vector<Tp>) {}

#endif