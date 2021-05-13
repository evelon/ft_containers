#ifndef LIST_ITERATOR_HPP
# define LIST_ITERATOR_HPP

# include <iterator>
# include "DoublyLinkedNode.hpp"

namespace ft
{
	template <typename Tp, template <typename T> class Node = DoublyLinkedNode>
	class	list_iterator;

	template <typename Tp, template <typename T> class Node>
	class	list_iterator
	{
	private:
		typedef list_iterator<Tp, Node>			iterator_type;
		typedef Node<Tp>						node;
		node*									ptrToNode;

	public:
		typedef std::bidirectional_iterator_tag	iterator_category;
		typedef Tp								value_type;
		typedef Tp&								reference;
		typedef Tp*								pointer;
		typedef std::ptrdiff_t					difference_type;

		list_iterator(void):
			ptrToNode(nullptr) {};
		list_iterator(iterator_type const& iter):
			ptrToNode(iter.ptrToNode) {};
		list_iterator&	operator=(iterator_type const& iter)
			{ this->ptrToNode = iter.ptrToNode; return (*this); };
		~list_iterator(void) {};

		bool		operator==(iterator_type const& iter) const
			{ return (this->ptrToNode == iter.ptrToNode); };
		bool		operator!=(iterator_type const& iter) const
			{ return (this->ptrToNode != iter.ptrToNode); };
		reference	operator*(void)
			{ return (*this->ptrToNode); };
		pointer		operator->(void) const
			{ return (*this->ptrToNode); };
		iterator_type&	operator++(void)
		{
			if (ptrToNode->content != nullptr)
				ptrToNode = ptrToNode->next;
			return (*this);
		};
		iterator_type&	operator--(void)
		{
			if (ptrToNode->prev->content != nullptr)
				ptrToNode = ptrToNode->prev;
			return (*this);
		};
		iterator_type	operator++(int)
		{
			iterator_type	temp = *this;
			if (ptrToNode->content != nullptr)
				ptrToNode = ptrToNode->next;
			return (temp);
		};
		iterator_type	operator--(int)
		{
			iterator_type	temp = *this;
			if (ptrToNode->prev->content != nullptr)
				ptrToNode = ptrToNode->prev;
			return (temp);
		};
	};
}

#endif