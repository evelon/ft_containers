#ifndef VECTOR_COMMON_HPP
# define VECTOR_COMMON_HPP

# include "../common.hpp"

# if NAMESPACE == FT
#  include "vector.hpp"
// header guard test
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
void	receive_vector(NS::vector<Tp>) {}

#endif