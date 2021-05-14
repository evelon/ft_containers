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
		node*			next;
		node*			prev;

	public:
		explicit DoublyLinkedNode(const allocator_type& alloc = allocator_type()):
			allocator(alloc), content(nullptr), next(this), prev(this)
		{};
		DoublyLinkedNode(
			const content_type& val,
			const allocator_type& alloc = allocator_type()):
			allocator(alloc), content(allocator.allocate(1)), next(this), prev(this)
		{ allocator.construct(content, val); };
		DoublyLinkedNode(
			DoublyLinkedNode const& node,
			const allocator_type& alloc = allocator_type()):
			allocator(alloc), content(allocator.allocate(1)), next(node.next), prev(node.prev)
		{ allocator.construct(this->content, *(node.content)); };
		DoublyLinkedNode(Tp value, DoublyLinkedNode* next_node, DoublyLinkedNode* prev_node):
			content(allocator.allocate(1)), next(next_node), prev(prev_node)
		{ allocator.construct(this->content, value); };
		DoublyLinkedNode&	operator=(DoublyLinkedNode const& node)
		{
			allocator.destroy(this->content);
			allocator.construct(this->content, *(node.content));
			this->next = next;
			this->prev = prev;
		};
		~DoublyLinkedNode(void)
		{
			prev->next = next;
			next->prev = prev;
			allocator.destroy(this->content);
		};

		content_type const&	getContent(void)
		{ return (*content); }
		node*&	getNext(void)
		{ return (next); }
		node*&	getPrev(void)
		{ return (prev); }

		void	AddNext(DoublyLinkedNode next_node)
		{
			DoublyLinkedNode	next_next = this->next;
			this->next = next_node;
			next_node->next = next_next;
			next_node->prev = this;
			next_next->prev = next_node;
		};
		void	AddPrev(DoublyLinkedNode prev_node)
		{
			DoublyLinkedNode	prev_prev = this->prev;
			this->prev = prev_node;
			prev_node->prev = prev_prev;
			prev_node->next = this;
			prev_prev->next = prev_node;
		};
	};
}

#endif
