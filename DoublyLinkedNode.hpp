#ifndef DOUBLYLINKEDNODE_HPP
# define DOUBLYLINKEDNODE_HPP

# include <memory>

namespace	ft
{
	template	<typename Tp, class Alloc = std::allocator<Tp> >
	class	DoublyLinkedNode;

	template	<typename Tp, class Alloc>
	class	DoublyLinkedNode
	{
	private:
		typedef DoublyLinkedNode<Tp, Alloc>	node;

	public:
		typedef Tp										value_type;
		typedef Alloc									allocator_type;
		typedef typename Alloc::reference				reference;
		typedef typename Alloc::const_reference			const_reference;
		typedef typename Alloc::pointer					pointer;
		typedef typename Alloc::const_pointer			const_pointer;

	private:
		static allocator_type	allocator_;
		value_type*				content_;
		node*					next_;
		node*					prev_;

	public:
		explicit DoublyLinkedNode(const allocator_type& alloc = allocator_type()):
			content_(nullptr),
			next_(this),
			prev_(this)
		{
			allocator_ = alloc;
		};
		DoublyLinkedNode(
			const value_type& val,
			const allocator_type& alloc = allocator_type()):
			content_(allocator_.allocate(1)),
			next_(this),
			prev_(this)
		{
			allocator_ = alloc;
			allocator_.construct(content_, val);
		};
		DoublyLinkedNode(
			node const& ori_node,
			const allocator_type& alloc = allocator_type()):
			content_(),
			next_(ori_node.next_),
			prev_(ori_node.prev_)
		{
			allocator_ = alloc;
			if (&ori_node == this)
			{
				this->content_ = nullptr;
				this->next_ = this;
				this->prev_ = this;
				return ;
			}
			if (ori_node.content_)
			{
				this->content_ = allocator_.allocate(1);
				allocator_.construct(this->content_, *ori_node.content_);
			}
			else
				this->content_ = nullptr;
		};
		DoublyLinkedNode(
			value_type value,
			node* next_node,
			node* prev_node,
			const allocator_type& alloc = allocator_type()):
			content_(allocator_.allocate(1)),
			next_(next_node),
			prev_(prev_node)
		{
			allocator_ = alloc;
			allocator_.construct(this->content_, value);
		};
		node&	operator=(node const& ori_node)
		{
			if (ori_node.content_)
				*this->content_ = *ori_node.content_;
			this->next_ = next_;
			this->prev_ = prev_;
			return (*this);
		};
		~DoublyLinkedNode(void)
		{
			if (prev_ != this)
			{
				prev_->next_ = next_;
				next_->prev_ = prev_;
			}
			if (!content_)
				return ;
			allocator_.destroy(content_);
			allocator_.deallocate(content_, 1);
		};
		value_type*&	getContent(void)
		{ return (content_); };
		node*&	getNext(void)
			{ return (next_); };
		node*&	getPrev(void)
			{ return (prev_); };
		void	setContent(value_type const& val)
		{
			if (content_ != nullptr)
				allocator_.destroy(content_);
			else
				content_ = allocator_.allocate(1);
			allocator_.construct(content_, val);
		};
		void	AddNext(DoublyLinkedNode* next_node)
		{
			this->next_->prev_ = next_node;
			next_node->next_ = this->next_;
			next_node->prev_ = this;
			this->next_ = next_node;
		};
		void	AddPrev(DoublyLinkedNode* prev_node)
		{
			this->prev_->next_ = prev_node;
			prev_node->prev_ = this->prev_;
			prev_node->next_ = this;
			this->prev_ = prev_node;
		};
		node*	PopGetNode(void)
		{
			this->next_->prev_ = this->prev_;
			this->prev_->next_ = this->next_;
			this->next_ = this;
			this->prev_ = this;
			return (this);
		}
		void	ContentExchange(node*& nod)
		{
			value_type*	temp;
			temp = nod->content_;
			nod->content_ = this->content_;
			this->content_ = temp;
		}
	};

	template	<typename Tp, class Alloc>
	Alloc	DoublyLinkedNode<Tp, Alloc>::allocator_ = Alloc();
}

#endif
