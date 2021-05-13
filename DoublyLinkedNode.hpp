#ifndef DOUBLYLINKEDNODE_HPP
# define DOUBLYLINKEDNODE_HPP

#include <memory>

namespace ft
{
	template	<typename Tp, template <typename T> class Alloc = std::allocator>
	struct	DoublyLinkedNode;

	template	<typename Tp, template <typename T> class Alloc>
	struct	DoublyLinkedNode
	{
		Tp*						content;
		DoublyLinkedNode<Tp>*	next;
		DoublyLinkedNode<Tp>*	prev;

		DoublyLinkedNode(void):
			content(nullptr), next(this), prev(this)
		{};
		DoublyLinkedNode(DoublyLinkedNode const& node):
			content(new *node->content), next(node->next), prev(node->prev)
		{};
		DoublyLinkedNode(Tp value, DoublyLinkedNode* next_node, DoublyLinkedNode* prev_node):
			content(new Tp(value)), next(next_node), prev(prev_node)
		{};
		DoublyLinkedNode&	operator=(DoublyLinkedNode const& node)
		{
			*this->content = *node.content;
			this->next = next;
			this->prev = prev;
		}
		~DoublyLinkedNode(void)
			{ delete content; }

		void	AddNext(DoublyLinkedNode next_node)
		{
			DoublyLinkedNode	next_next = this->next;
			this->next = next_node;
			next_node->next = next_next;
			next_node->prev = this;
			next_next->prev = next_node;
		}
		void	AddPrev(DoublyLinkedNode prev_node)
		{
			DoublyLinkedNode	prev_prev = this->prev;
			this->prev = prev_node;
			prev_node->prev = prev_prev;
			prev_node->next = this;
			prev_prev->next = prev_node;
		}
	};
}

#endif
