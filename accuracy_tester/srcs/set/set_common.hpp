#ifndef SET_COMMON_HPP
# define SET_COMMON_HPP

# include "../common.hpp"

# if NAMESPACE == FT
#  include "set.hpp"
# else
#  include <set>
# endif

# include <list>

class	B	{};

typedef NS::set<A, B, std::allocator<A> >	setA;
typedef NS::set<int>						setInt_o;
typedef NS::set<wrapper<int> >				setInt;
typedef NS::set<std::string>				setStr;
typedef NS::set<wrapper<char> >				setChar;

typedef NS::set<float>						setFloat_o;
typedef NS::set<wrapper<float> >			setFloat;
typedef NS::set<setInt::size_type>			setSize;

template	<typename T>
void	receive_set(NS::set<T>) {}

#endif