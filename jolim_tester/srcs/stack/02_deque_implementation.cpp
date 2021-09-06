#include "stack_common.hpp"
#include <deque>

typedef NS::stack<int, std::deque<int> >	intSt;
typedef NS::stack<std::string, std::deque<std::string> >	StrSt;
typedef MutantStack<int, std::deque<int> >	intMs;
typedef MutantStack<std::string, std::deque<std::string> >	StrMs;

int	main()
{
	intSt	stack1;

	check_stack(stack1);

	stack1.push(1);
	check_stack(stack1);

	stack1.pop();
	check_stack(stack1);

	stack1.push(2);
	check_stack(stack1);

	stack1.push(4);
	check_stack(stack1);

	stack1.pop();
	check_stack(stack1);

	const int	cint = stack1.top();
	std::cout << cint << std::endl;

	stack1.top() = 8;
	check_stack(stack1);

	std::deque<std::string>	deq;
	deq.push_back("abc");
	deq.push_back("efws");

	StrSt	stack2(deq);

	check_stack(stack2);

	stack2.pop();
	check_stack(stack2);

	stack2.push("fwe");
	check_stack(stack2);

	stack2.pop();
	check_stack(stack2);

	stack2.pop();
	check_stack(stack2);

	deq.push_back("fsd");

	StrMs	mstack1(deq);

	print_it(mstack1.begin(), mstack1.end());
	print_it(mstack1.rbegin(), mstack1.rend());

	intMs	mstack2;

	fill_int(mstack2, 14, 4);
	print_all(mstack2);
}