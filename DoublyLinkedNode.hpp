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
		static allocator_type	allocator;
		value_type*				content;
		node*					next;
		node*					prev;

	public:
		explicit DoublyLinkedNode(const allocator_type& alloc = allocator_type()):
			content(nullptr),
			next(this),
			prev(this)
		{
			allocator = alloc;
		};
		DoublyLinkedNode(
			const value_type& val,
			const allocator_type& alloc = allocator_type()):
			content(allocator.allocate(1)),
			next(this),
			prev(this)
		{
			allocator = alloc;
			allocator.construct(content, val);
		};
		DoublyLinkedNode(
			node const& ori_node,
			const allocator_type& alloc = allocator_type()):
			content(),
			next(ori_node.next),
			prev(ori_node.prev)
		{
			allocator = alloc;
			if (&ori_node == this)
			{
				this->content = nullptr;
				this->next = this;
				this->prev = this;
				return ;
			}
			if (ori_node.content)
			{
				this->content = allocator.allocate(1);
				allocator.construct(this->content, *ori_node.content);
			}
			else
				this->content = nullptr;
		};
		DoublyLinkedNode(
			value_type value,
			node* next_node,
			node* prev_node,
			const allocator_type& alloc = allocator_type()):
			content(allocator.allocate(1)),
			next(next_node),
			prev(prev_node)
		{
			allocator = alloc;
			allocator.construct(this->content, value);
		};
		node&	operator=(node const& ori_node)
		{
			if (ori_node.content)
				*this->content = *ori_node.content;
			this->next = next;
			this->prev = prev;
			return (*this);
		};
		~DoublyLinkedNode(void)
		{
			if (prev != this)
			{
				prev->next = next;
				next->prev = prev;
			}
			if (!content)
				return ;
			allocator.destroy(content);
			allocator.deallocate(content, 1);
		};
		value_type*&	getContent(void)
		{ return (content); };
		node*&	getNext(void)
			{ return (next); };
		node*&	getPrev(void)
			{ return (prev); };
		void	setContent(value_type const& val)
		{
			if (content != nullptr)
				allocator.destroy(content);
			else
				content = allocator.allocate(1);
			allocator.construct(content, val);
		};
		void	AddNext(DoublyLinkedNode* next_node)
		{
			this->next->prev = next_node;
			next_node->next = this->next;
			next_node->prev = this;
			this->next = next_node;
		};
		void	AddPrev(DoublyLinkedNode* prev_node)
		{
			this->prev->next = prev_node;
			prev_node->prev = this->prev;
			prev_node->next = this;
			this->prev = prev_node;
		};
		node*	PopGetNode(void)
		{
			this->next->prev = this->prev;
			this->prev->next = this->next;
			this->next = this;
			this->prev = this;
			return (this);
		}
		void	ContentExchange(node*& nod)
		{
			value_type*	temp;
			temp = nod->content;
			nod->content = this->content;
			this->content = temp;
		}
	};

	template	<typename Tp, class Alloc>
	Alloc	DoublyLinkedNode<Tp, Alloc>::allocator = Alloc();
}

#endif
