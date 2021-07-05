#ifndef MAP_TEST_HPP
# define MAP_TEST_HPP

# include "../common.hpp"

# if NAMESPACE == FT
#  include "map.hpp"
# else
#  include <map>
# endif

class	B	{};

class	C	{};

typedef NS::map<A, B, C, std::allocator<NS::pair<const A, B> > >	mapAB;
typedef NS::map<char, int>						mapCharInt_o;
typedef NS::map<wrapper<char>, wrapper<int> >	mapCharInt;
typedef NS::map<std::string, wrapper<int> >		mapStrInt;
typedef NS::map<int, float>						mapIntFloat_o;
typedef NS::map<wrapper<int>, wrapper<float> >	mapIntFloat;
typedef NS::map<int, mapCharInt::size_type>		mapIntSize;

template	<typename T, typename U>
void	receive_map(NS::map<T, U>) {}

#endif