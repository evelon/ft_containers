#ifndef LIST_ITERATOR_HPP
# define LIST_ITERATOR_HPP

# include <iterator>
# include "DoublyLinkedNode.hpp"

namespace ft
{
	template <typename Tp, class Node = DoublyLinkedNode<Tp> >
	class	list_iterator;

	template <typename Tp, class Node>
	class	list_iterator
	{
	private:
		typedef list_iterator<Tp, Node>			iterator_type;
		typedef Node							node;
		node*									ptrToNode;

	public:
		typedef std::bidirectional_iterator_tag	iterator_category;
		typedef Tp								value_type;
		typedef Tp&								reference;
		typedef Tp*								pointer;
		typedef std::ptrdiff_t					difference_type;

		list_iterator(void):
			ptrToNode(nullptr) {};
		list_iterator(node* nod):
			ptrToNode(nod) {};
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
				ptrToNode = ptrToNode->getNext();
			return (*this);
		};
		iterator_type&	operator--(void)
		{
			if (ptrToNode->getPrev()->content != nullptr)
				ptrToNode = ptrToNode->getPrev();
			return (*this);
		};
		iterator_type	operator++(int)
		{
			iterator_type	temp = *this;
			if (ptrToNode->content != nullptr)
				ptrToNode = ptrToNode->getNext();
			return (temp);
		};
		iterator_type	operator--(int)
		{
			iterator_type	temp = *this;
			if (ptrToNode->getPrev()->content != nullptr)
				ptrToNode = ptrToNode->getPrev();
			return (temp);
		};
	};
}

#endif