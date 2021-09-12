#ifndef MAP_COMMON_HPP
# define MAP_COMMON_HPP

# include "../common.hpp"

# if NAMESPACE == FT
#  include "map.hpp"
# else
#  include <map>
# endif

# include <list>

class	B	{};

class	C	{};

#define PAIR(x, y) NS::make_pair(x, y)
typedef NS::map<A, B, C, std::allocator<NS::pair<const A, B> > >	mapAB;
typedef NS::map<char, int>						mapCharInt_o;
typedef NS::map<wrapper<char>, wrapper<int> >	mapCharInt;
typedef NS::map<std::string, wrapper<int> >		mapStrInt;

typedef std::list<NS::pair<wrapper<int>, std::string> >	stdListIntStr;
typedef NS::map<wrapper<int>, std::string>		mapIntStr;

typedef NS::map<int, float>						mapIntFloat_o;
typedef NS::map<wrapper<int>, wrapper<float> >	mapIntFloat;
typedef NS::map<int, mapCharInt::size_type>		mapIntSize;

template	<typename T, typename U>
void	receive_map(NS::map<T, U>) {}

template	<class It, class _It>
void	print_map_it(It first, _It last)
{
	unsigned int	count = 0;
	for (It it = first; it != last; ++it)
	{
		std::cout << count << "// Key: "<< (*it).first << " Value: " << (*it).second << '\n';
		++count;
	}
}

template	<typename Mp>
void	print_map(Mp map)
{
	print_map_it(map.begin(), map.end());
	std::cout << "size: " << map.size() << "\n\n";
}

#endif