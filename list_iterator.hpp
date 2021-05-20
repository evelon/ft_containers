#ifndef LIST_ITERATOR_HPP
# define LIST_ITERATOR_HPP

# include <iterator>
# include "DoublyLinkedNode.hpp"
# include "enable_if.hpp"


namespace	ft
{
	template	<typename Tp, class Node = DoublyLinkedNode<Tp> >
	class	list_iterator;

	template	<typename Tp, class Node>
	class	list_iterator
	{
	protected:
		typedef Node							node;
		typedef list_iterator<Tp, Node>			iterator;
		static Tp								default_value;
		node*									ptrToNode;

	public:
		typedef std::bidirectional_iterator_tag	iterator_category;
		typedef Tp								value_type;
		typedef Tp&								reference;
		typedef Tp*								pointer;
		typedef std::ptrdiff_t					difference_type;

	protected:
		reference	reverse_reference(void)
		{
			value_type*	value = this->ptrToNode->getPrev()->getContent();
			if (value)
				return (*value);
			return (default_value);
		};

	public:
		list_iterator(void):
			ptrToNode(nullptr) {};
		list_iterator(node* nod):
			ptrToNode(nod) {};
		list_iterator(iterator const& iter):
			ptrToNode(iter.ptrToNode) {};
		template	<typename _Tp, typename N>
		list_iterator(list_iterator<_Tp, N> const& iter):
			ptrToNode(((iterator*)(&iter))->ptrToNode)
		{
			typename ft::disable_if<is_const_of<Tp, _Tp>::value>::type* dummy;
			(void)dummy;
		};
		~list_iterator() {};
		iterator&	operator=(iterator const& iter)
		{
			this->ptrToNode = iter.ptrToNode;
			return (*this);
		}
		template	<typename _Tp, typename N>
		iterator&	operator=(list_iterator<_Tp, N> const& iter)
		{
			typename ft::enable_if<is_const_same<_Tp, Tp>::value>::type*	dummy;
			(void)dummy;
			this->ptrToNode = ((iterator*)(&iter))->ptrToNode;
			return (*this);
		};


		template	<typename _Tp, typename N>
		bool		operator==(list_iterator<_Tp, N> const& iter) const
		{
			typename ft::enable_if<is_const_same<_Tp, Tp>::value>::type*	dummy;
			(void)dummy;
			return (this->ptrToNode == ((iterator*)(&iter))->ptrToNode);
		};
		template	<typename _Tp, typename N>
		bool		operator!=(list_iterator<_Tp, N> const& iter) const
		{
			typename ft::enable_if<is_const_same<_Tp, Tp>::value>::type*	dummy;
			(void)dummy;
			return (this->ptrToNode != ((iterator*)(&iter))->ptrToNode);
		};
		reference	operator*(void)
		{
			value_type*	value = this->ptrToNode->getContent();
			if (value)
				return (*value);
			return (default_value);
		};
		pointer		operator->(void) const
			{ return (this->ptrToNode->getContent()); };
		iterator&	operator++(void)
		{
			// if (ptrToNode->getContent() != nullptr)
				ptrToNode = ptrToNode->getNext();
			return (*this);
		};
		iterator&	operator--(void)
		{
			// if (ptrToNode->getContent() != nullptr)
				ptrToNode = ptrToNode->getPrev();
			return (*this);
		};
		iterator	operator++(int)
		{
			iterator	temp = *this;
			// if (ptrToNode->getContent() != nullptr)
				ptrToNode = ptrToNode->getNext();
			return (temp);
		};
		iterator	operator--(int)
		{
			iterator	temp = *this;
			// if (ptrToNode->getContent() != nullptr)
				ptrToNode = ptrToNode->getPrev();
			return (temp);
		};
	};

	template	<typename Tp, class Node>
	Tp	list_iterator<Tp, Node>::default_value = Tp();
}

#endif