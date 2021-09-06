#ifndef STACK_COMMON_HPP
# define STACK_COMMON_HPP

# include "../common.hpp"

# if NAMESPACE == FT
#  include "stack.hpp"
# else
#  include <stack>
#  include <vector>
# endif

template	<class Stack>
void	check_stack(const Stack& st)
{
	std::cout << st.empty() << std::endl;
	std::cout << st.size() << std::endl;
	if (st.size())
		std::cout << st.top() << std::endl;
}

template	<class T, class Container = NS::vector<T> >
class	MutantStack : public NS::stack<T, Container>
{
private:
	typedef NS::stack<T, Container>	stack;

public:
	MutantStack(): stack() {};
	MutantStack(MutantStack const& ms): stack(ms) {};
	MutantStack(Container const& c): stack(c) {};
	~MutantStack() {};
	MutantStack&	operator=(MutantStack const& ms)
	{ *this = ms; }

	typedef typename stack::container_type::iterator				iterator;
	typedef typename stack::container_type::const_iterator			const_iterator;
	typedef typename stack::container_type::reverse_iterator		reverse_iterator;
	typedef typename stack::container_type::const_reverse_iterator	const_reverse_iterator;

	iterator		begin(void)
	{ return this->c.begin(); };
	const_iterator	begin(void) const
	{ return this->c.begin(); };
	iterator		end(void)
	{ return this->c.end(); };
	const_iterator	end(void) const
	{ return this->c.end(); };
	reverse_iterator		rbegin(void)
	{ return this->c.rbegin(); };
	const_reverse_iterator	rbegin(void) const
	{ return this->c.rbegin(); };
	reverse_iterator		rend(void)
	{ return this->c.rend(); };
	const_reverse_iterator	rend(void) const
	{ return this->c.rend(); };
};

#endif