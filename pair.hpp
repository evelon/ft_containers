#ifndef PAIR_HPP
# define PAIR_HPP

namespace	ft
{
	template	<class T1, class T2>
	struct	pair
	{
		typedef T1	first_type;
		typedef T2	second_type;

		first_type	first;
		second_type	second;

		pair(void): first(), second() {};
		template	<class U, class V>
		pair(pair<U, V> const& pr): first(pr.first), second(pr.second) {};
		pair(const first_type& a, const second_type& b): first(a), second(b) {};

		pair&	operator=(pair const& pr)
			{ first = pr.first; second = pr.second; };
	};

	template	<class T1, class T2>
	bool	operator==(pair<T1, T2> const& lhs, pair<T1, T2> const& rhs)
	{
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	};

	template	<class T1, class T2>
	bool	operator<(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
	};

	template	<class T1, class T2>
	pair<T1, T2>	make_pair(T1 x, T2 y)
		{ return (pair<T1, T2>(x, y)); };
}

#endif