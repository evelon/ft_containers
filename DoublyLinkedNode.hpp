#ifndef DOUBLYLINKEDNODE_HPP
# define DOUBLYLINKEDNODE_HPP

#include <memory>

namespace ft
{
	template	<typename Tp, class Alloc = std::allocator<Tp> >
	class	DoublyLinkedNode;

	template	<typename Tp, class Alloc>
	class	DoublyLinkedNode
	{
	private:
		typedef DoublyLinkedNode<Tp, Alloc>	node;

	public:
		typedef Tp										content_type;
		typedef Alloc									allocator_type;
		typedef typename Alloc::reference				reference;
		typedef typename Alloc::const_reference			const_reference;
		typedef typename Alloc::pointer					pointer;
		typedef typename Alloc::const_pointer			const_pointer;

	private:
		allocator_type	allocator;
		content_type*	content;
		content_type	null_content;
		content_type*	null_content_ptr;
		node*			next;
		node*			prev;

	public:
		explicit DoublyLinkedNode(const allocator_type& alloc = allocator_type()):
			allocator(alloc),
			content(nullptr),
			null_content(),
			null_content_ptr(&null_content),
			next(this),
			prev(this)
		{};
		DoublyLinkedNode(
			const content_type& val,
			const allocator_type& alloc = allocator_type()):
			allocator(alloc),
			content(allocator.allocate(1)),
			null_content(),
			null_content_ptr(&null_content),
			next(this),
			prev(this)
			{ allocator.construct(content, val); };
		DoublyLinkedNode(
			node const& ori_node,
			const allocator_type& alloc = allocator_type()):
			allocator(alloc),
			content(allocator.allocate(1)),
			null_content(),
			null_content_ptr(&null_content),
			next(ori_node.next),
			prev(ori_node.prev)
			{
				allocator.construct(this->content, *ori_node.content);
				if (&ori_node == this)
				{
					this->content = nullptr;
					this->next = this;
					this->prev = this;
				}
			};
		DoublyLinkedNode(
			Tp value,
			node* next_node,
			node* prev_node,
			const allocator_type& alloc = allocator_type()):
			allocator(alloc),
			content(allocator.allocate(1)),
			null_content(),
			null_content_ptr(&null_content),
			next(next_node),
			prev(prev_node)
			{ allocator.construct(this->content, value); };
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
			allocator.destroy(this->content);
			allocator.deallocate(this->content, 1);
		};

		content_type*&	getContent(void)
		{
			if (!content)
				return (null_content_ptr);
			return (content);
		};
		node*&	getNext(void)
			{ return (next); };
		node*&	getPrev(void)
			{ return (prev); };
		void	setContent(content_type const& val)
		{
			if (content != nullptr)
				allocator.destroy(content);
			else
				content = allocator.allocate(1);
			allocator.construct(content, val);
		};

		void	AddNext(DoublyLinkedNode* next_node)
		{
			DoublyLinkedNode*	next_next = this->next;
			this->next = next_node;
			next_node->next = next_next;
			next_node->prev = this;
			next_next->prev = next_node;
		};
		void	AddPrev(DoublyLinkedNode* prev_node)
		{
			DoublyLinkedNode*	prev_prev = this->prev;
			this->prev = prev_node;
			prev_node->prev = prev_prev;
			prev_node->next = this;
			prev_prev->next = prev_node;
		};
	};
}

#endif
