#ifndef COMMON_HPP
# define COMMON_HPP

# include <iostream>
# include <string>
# include <memory>

# define FT 0
# define STD 1

# ifndef NAMESPACE
#  define NAMESPACE FT
# endif

# if NAMESPACE == FT
#  define NS ft
# else
#  define NS std
# endif

template	<typename A, typename B>
void	compare_all(A const& a, B const& b)
{
	std::cout << (a == b) << '\n';
	std::cout << (a != b) << '\n';
	std::cout << (a < b) << '\n';
	std::cout << (a <= b) << '\n';
	std::cout << (a > b) << '\n';
	std::cout << (a >= b) << '\n';
}

template	<class It, class _It>
void	print_it(It first, _It last)
{
	unsigned int	count = 0;
	for (It it = first; it != last; ++it)
	{
		std::cout << count << ": " << *it << '\n';
		++count;
	}
}

template	<class Container>
void	print_all(Container cont)
{
	print_it(cont.begin(), cont.end());
	std::cout << "size: " << cont.size() << "\n\n";
}

template	<class Container>
void	fill_int(Container& cont, int first, int diff)
{
	for (typename Container::iterator it = cont.begin(); it != cont.end(); ++it)
	{
		*it = first;
		first += diff;
	}
}

template	<class Container, typename Tp>
void	fill_type(Container& cont, Tp first, Tp diff)
{
	for (typename Container::iterator it = cont.begin(); it != cont.end(); ++it)
	{
		*it = first;
		first += diff;
	}
}

template	<typename T>
class	wrapper;

template	<typename T>
std::ostream	operator<<(std::ostream os, wrapper<T> wrap);

template	<typename T>
bool	operator==(wrapper<T> lhs, wrapper<T> rhs);

template	<typename T>
class	wrapper
{
	T		content_;
	bool	verbose_;

public:
	wrapper(T content = T(), bool verbose = false): content_(content), verbose_(verbose)
		{ if (verbose_) std::cout << "wrapper constructed" << '\n'; };

	wrapper(wrapper const& a): content_(a.content_), verbose_(a.verbose_)
		{ if (verbose_) std::cout << "wrapper copy-constructed" << '\n'; };

	~wrapper()
		{ if (verbose_) std::cout << "wrapper destructed" << '\n'; };

	operator int() const
		{ return content_; }

	wrapper&	operator=(wrapper const& a)
	{
		this->content_ = a.content_; this->verbose_ = a.verbose_;
		if (verbose_) std::cout << "wrapper assigned" << '\n';
		return (*this);
	};

	friend std::ostream&	operator<<(std::ostream& os, wrapper wrap)
	{
		os << wrap.content_;
		return (os);
	};

	friend bool	operator==(wrapper lhs, wrapper rhs)
		{ return (lhs.content_ == rhs.content_); };
};

class	A {};

namespace	test
{
	template	<typename Arg1, typename Arg2, typename Result>
	struct	binary_function
	{
		typedef Arg1	first_argument_type;
		typedef Arg2	second_argument_type;
		typedef Result	result_type;
	};

	template	<typename Tp = void>
	struct	less : public binary_function<Tp, Tp, bool>
	{
		bool	operator()(Tp const& x, Tp const& y) const
			{ return (x < y); };
	};

	template	<bool B, typename T = void>
	struct	enable_if
	{};

	template	<typename T>
	struct	enable_if<true, T>
	{ typedef T	type; };

	template	<typename T, typename U>
	struct	is_same
	{ static const bool value = false; };

	template	<typename T>
	struct	is_same<T, T>
	{ static const bool value = true; };
}

#endif