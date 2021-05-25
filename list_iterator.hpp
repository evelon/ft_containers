#ifndef LIST_ITERATOR_HPP
# define LIST_ITERATOR_HPP

# include "iterator.hpp"
# include "DoublyLinkedNode.hpp"
# include "enable_if.hpp"


namespace	ft
{
	template	<typename Tp>
	class	list_iterator;

	template	<class Iterator>
	class	reverse_iterator;

	template	<typename Tp>
	class	list_iterator
	{
	private:
		typedef list_iterator<Tp>			iterator;

	protected:
		typedef DoublyLinkedNode<Tp> 		node;

		template	<typename _Tp>
		void	is_compatible(list_iterator<_Tp> const& iter,
			typename enable_if<is_const_same<_Tp, Tp>::value>::type* = 0) const
			{ (void)iter; };

	public:
		typedef bidirectional_iterator_tag	iterator_category;
		typedef Tp							value_type;
		typedef Tp&							reference;
		typedef Tp*							pointer;
		typedef std::ptrdiff_t				difference_type;

	private:
		static value_type					default_value_;
		node*								ptrToNode_;

		list_iterator(reverse_iterator<iterator>) {};

	protected:
		list_iterator(node* nod):
			ptrToNode_(nod) {};

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
			ptrToNode_(NULL) {};
		list_iterator(iterator const& iter):
			ptrToNode_(iter.ptrToNode_) {};
		template	<typename _Tp>
		list_iterator(list_iterator<_Tp> const& iter):
			ptrToNode_(((iterator*)(&iter))->ptrToNode_)
		{
			typename disable_if<is_const_of<Tp, _Tp>::value>::type* dummy;
			(void)dummy;
		};
		virtual ~list_iterator() {};
		iterator&	operator=(iterator const& iter)
		{
			this->ptrToNode_ = iter.ptrToNode_;
			return (*this);
		}
		template	<typename _Tp>
		iterator&	operator=(list_iterator<_Tp> const& iter)
		{
			typename enable_if<is_const_same<_Tp, Tp>::value>::type*	dummy;
			(void)dummy;
			this->ptrToNode_ = ((iterator*)(&iter))->ptrToNode_;
			return (*this);
		};
		reference	operator*(void)
		{
			value_type*	value = this->ptrToNode_->getContent();
			if (value)
				return (*value);
			return (default_value_);
		};
		template	<typename _Tp>
		bool		operator==(list_iterator<_Tp> const& iter) const
		{
			typename enable_if<is_const_same<_Tp, Tp>::value>::type*	dummy;
			(void)dummy;
			return (this->ptrToNode_ == ((iterator*)(&iter))->ptrToNode_);
		};
		template	<typename _Tp>
		bool		operator!=(list_iterator<_Tp> const& iter) const
		{
			typename enable_if<is_const_same<_Tp, Tp>::value>::type*	dummy;
			(void)dummy;
			return (this->ptrToNode_ != ((iterator*)(&iter))->ptrToNode_);
		};
		iterator&	operator++(void)
		{
			// if (ptrToNode->getContent() != NULL)
				ptrToNode_ = ptrToNode_->getNext();
			return (*this);
		};
		iterator	operator++(int)
		{
			iterator	temp = *this;
			// if (ptrToNode->getContent() != NULL)
				ptrToNode_ = ptrToNode_->getNext();
			return (temp);
		};
		iterator&	operator--(void)
		{
			// if (ptrToNode->getContent() != NULL)
				ptrToNode_ = ptrToNode_->getPrev();
			return (*this);
		};
		iterator	operator--(int)
		{
			iterator	temp = *this;
			// if (ptrToNode->getContent() != NULL)
				ptrToNode_ = ptrToNode_->getPrev();
			return (temp);
		};
		pointer		operator->(void) const
			{ return (this->ptrToNode_->getContent()); };
	};

	template	<typename Tp>
	Tp	list_iterator<Tp>::default_value_ = Tp();
}

#endif