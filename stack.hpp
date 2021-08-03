#ifndef STACK_HPP
# define STACK_HPP

# include	"vector.hpp"

namespace	ft
{
	template	<class T, class Container = vector<T> >
	class	stack;

	template	<class T, class Container>
	bool	operator==(const stack<T, Container>& lhs, const stack<T, Container>& rhs);

	template	<class T, class Container>
	bool	operator<(const stack<T, Container>& lhs, const stack<T, Container>& rhs);


	template <class T, class Container>
	class	stack
	{
	public:
		typedef T			value_type;
		typedef Container	container_type;
		typedef size_t		size_type;

	private:
		container_type	inner_container;

	public:
		explicit stack(const container_type& ctnr = container_type()):
			inner_container(ctnr) {};

		bool	empty() const
			{ return (inner_container.empty()); };
		size_type	size() const
			{ return (inner_container.size()); };
		value_type&	top()
			{ return (inner_container.back()); };
		const value_type&	top() const
			{ return (inner_container.back()); };
		void	push(const value_type& val)
			{ inner_container.push_back(val); };
		void	pop()
			{ inner_container.pop_back(); };

		template	<class Tp, class Container_>
		friend bool	operator==(const stack<Tp, Container_>& lhs, const stack<Tp, Container_>& rhs)
			{ return (lhs.inner_container == rhs.inner_container); };

		template	<class Tp, class Container_>
		friend bool	operator<(const stack<Tp, Container_>& lhs, const stack<Tp, Container_>& rhs)
			{ return (lhs.inner_container < rhs.inner_container); };
	};
}

#endif