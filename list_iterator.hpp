#ifndef LIST_ITERATOR_HPP
# define LIST_ITERATOR_HPP

# include "iterator.hpp"
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
		typedef Node						node;
		typedef list_iterator<Tp, Node>		iterator;

	public:
		typedef bidirectional_iterator_tag	iterator_category;
		typedef Tp							value_type;
		typedef Tp&							reference;
		typedef Tp*							pointer;
		typedef std::ptrdiff_t				difference_type;

	private:
		static value_type					default_value_;
		node*								ptrToNode_;

	protected:
		node*&		getNode_(void)
			{ return (ptrToNode_); };
		reference	reverse_reference(void)
		{
			value_type*	value = this->ptrToNode_->getPrev()->getContent();
			if (value)
				return (*value);
			return (default_value_);
		};

	public:
		list_iterator(void):
			ptrToNode_(nullptr) {};
		list_iterator(node* nod):
			ptrToNode_(nod) {};
		list_iterator(iterator const& iter):
			ptrToNode_(iter.ptrToNode_) {};
		template	<typename _Tp, typename N>
		list_iterator(list_iterator<_Tp, N> const& iter):
			ptrToNode_(((iterator*)(&iter))->ptrToNode_)
		{
			typename disable_if<is_const_of<Tp, _Tp>::value>::type* dummy;
			(void)dummy;
		};
		~list_iterator() {};
		iterator&	operator=(iterator const& iter)
		{
			this->ptrToNode_ = iter.ptrToNode_;
			return (*this);
		}
		template	<typename _Tp, typename N>
		iterator&	operator=(list_iterator<_Tp, N> const& iter)
		{
			typename enable_if<is_const_same<_Tp, Tp>::value>::type*	dummy;
			(void)dummy;
			this->ptrToNode_ = ((iterator*)(&iter))->ptrToNode_;
			return (*this);
		};


		template	<typename _Tp, typename N>
		bool		operator==(list_iterator<_Tp, N> const& iter) const
		{
			typename enable_if<is_const_same<_Tp, Tp>::value>::type*	dummy;
			(void)dummy;
			return (this->ptrToNode_ == ((iterator*)(&iter))->ptrToNode_);
		};
		template	<typename _Tp, typename N>
		bool		operator!=(list_iterator<_Tp, N> const& iter) const
		{
			typename enable_if<is_const_same<_Tp, Tp>::value>::type*	dummy;
			(void)dummy;
			return (this->ptrToNode_ != ((iterator*)(&iter))->ptrToNode_);
		};
		reference	operator*(void)
		{
			value_type*	value = this->ptrToNode_->getContent();
			if (value)
				return (*value);
			return (default_value_);
		};
		pointer		operator->(void) const
			{ return (this->ptrToNode_->getContent()); };
		iterator&	operator++(void)
		{
			// if (ptrToNode->getContent() != nullptr)
				ptrToNode_ = ptrToNode_->getNext();
			return (*this);
		};
		iterator&	operator--(void)
		{
			// if (ptrToNode->getContent() != nullptr)
				ptrToNode_ = ptrToNode_->getPrev();
			return (*this);
		};
		iterator	operator++(int)
		{
			iterator	temp = *this;
			// if (ptrToNode->getContent() != nullptr)
				ptrToNode_ = ptrToNode_->getNext();
			return (temp);
		};
		iterator	operator--(int)
		{
			iterator	temp = *this;
			// if (ptrToNode->getContent() != nullptr)
				ptrToNode_ = ptrToNode_->getPrev();
			return (temp);
		};
	};

	template	<typename Tp, class Node>
	Tp	list_iterator<Tp, Node>::default_value_ = Tp();
}

#endif