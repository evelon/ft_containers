#ifndef REDBLACKTREE_HPP
# define REDBLACKTREE_HPP

# include <memory>
# include "template_utils.hpp"
# include "iterator.hpp"
# include "reverse_iterator.hpp"

# define LEFT 0
# define RIGHT 1
# define RED true
# define BLACK false


#include <iostream>

namespace	ft
{
	template	<typename Tp>
	struct	RedBlackTreeNode;

	template	<typename Tp, class Alloc = std::allocator<Tp> >
	class	RedBlackTree;

	template	<typename Tp>
	class	TreeIterator;

	template	<typename Tp, typename _Tp>
	bool	operator==(TreeIterator<Tp> const& lhs, TreeIterator<_Tp> const& rhs);

	template	<typename Tp>
	struct	RedBlackTreeNode
	{
		typedef Tp										value_type;
		typedef RedBlackTreeNode						node;
		typedef int										position;
		typedef bool									color_type;

		value_type				content;
		node*					parent;
		node*					child[2];
		color_type				color;

		node*	sibling(void)
		{
			if (this->parent->child[LEFT] == this)
				return (this->parent->child[RIGHT]);
			return (this->parent->child[LEFT]);
		}
		node*	uncle(void)
		{
			return (this->parent->sibling());
		}
		node*	grand(void)
		{
			return (this->parent->parent);
		}
		void	leftRotate(void)
		{
			if (this->parent)
			{
				if (this->parent->child[LEFT] == this)
					this->parent->child[LEFT] = this->child[RIGHT];
				else
					this->parent->child[RIGHT] = this->child[RIGHT];
			}

			node*	new_left = this;
			node*	new_parent = this->child[RIGHT];

			new_parent->parent = new_left->parent;
			new_left->parent = new_parent;
			new_left->child[RIGHT] = new_parent->child[LEFT];
			new_parent->child[LEFT] = new_left;
		}
		void	rightRotate(void)
		{
			if (this->parent)
			{
				if (this->parent->child[LEFT] == this)
					this->parent->child[LEFT] = this->child[LEFT];
				else
					this->parent->child[RIGHT] = this->child[LEFT];
			}

			node*	new_right = this;
			node*	new_parent = this->child[LEFT];

			new_parent->parent = new_right->parent;
			new_right->parent = new_parent;
			new_right->child[LEFT] = new_parent->child[RIGHT];
			new_parent->child[RIGHT] = new_right;
		}
		void	leftRightRotate(void)
		{
			// if (!this->child[LEFT] || this->child[LEFT]->child[RIGHT]) -> crash!
			node*	new_parent = this->child[LEFT]->child[RIGHT];
			node*	new_left = this->child[LEFT];
			node*	new_right = this;

			new_parent->parent = this->parent;
			new_left->parent = new_parent;
			new_right->parent = new_parent;
			new_left->child[RIGHT] = new_parent->child[LEFT];
			new_right->child[LEFT] = new_parent->child[RIGHT];
			new_parent->child[LEFT] = new_left;
			new_parent->child[RIGHT] = new_right;
		}
		void	rightLeftRotate(void)
		{
			// if (!this->child[RIGHT] || this->child[RIGHT]->child[LEFT]) -> crash!
			node*	new_parent = this->child[RIGHT]->child[LEFT];
			node*	new_right = this->child[RIGHT];
			node*	new_left = this;

			new_parent->parent = this->parent;
			new_left->parent = new_parent;
			new_right->parent = new_parent;
			new_left->child[RIGHT] = new_parent->child[LEFT];
			new_right->child[LEFT] = new_parent->child[RIGHT];
			new_parent->child[LEFT] = new_left;
			new_parent->child[RIGHT] = new_right;
		}
		void	reconstruct(position pos)
		{
			node*	p = this->parent;
			node*	g = p->parent;

			if (p->child[LEFT] == this)
			{
				if (g->child[LEFT] == p)
					g->rightRotate()
				else
					g->rightLeftRotate();
			}
			else
			{
				if (g->child[RIGHT] = p)
					g->leftRightRotate();
				else
					g->leftRotate();
			}
		}
		void	rebalance(void)
		{
			if (this->sibling()->color == BLACK)
				this->reconstruct();
		}
		// void	recolor(void)
	private:
		RedBlackTreeNode(void);
	};

	template	<typename Tp, class Alloc>
	class	RedBlackTree
	{
	private:
		typedef RedBlackTree									tree_;
		typedef RedBlackTreeNode<Tp>							node_;
		typedef typename Alloc::template rebind<node_>::other	node_allocator_type_;

	public:
		typedef Tp												value_type;
		typedef Alloc											allocator_type;
		typedef typename Alloc::reference						reference;
		typedef typename Alloc::const_reference					const_reference;
		typedef typename Alloc::pointer							pointer;
		typedef typename Alloc::const_pointer					const_pointer;
		typedef TreeIterator<const Tp>							const_iterator;
		typedef TreeIterator<Tp>								iterator;
		typedef reverse_iterator<const_iterator>				const_reverse_iterator;
		typedef reverse_iterator<iterator>						reverse_iterator;


	private:
		allocator_type			alloc_;
		node_allocator_type_	nodeAlloc_;
		node_*					root_;
		node_*					pastTheEnd_;

		// Recursively copy tree.
		void	copyTree(node_*& this_node, node_* const& that_node)
		{
			alloc_.construct(this_node->content, that_node->content);
			this_node->color = that_node->color;
			for (int pos = LEFT; pos <= RIGHT; pos++)
			{
				if (that_node->child[pos] == NULL)
					this_node->child[pos] == NULL;
				else
				{
					this_node->child[pos] = nodeAlloc_.allocate(1);
					this_node->child[pos]->parent = this_node;
					copyTree(this_node->child[pos], that_node->child[pos]);
				}
			}
		};
		// Recursively delete tree.
		void	deleteTree(node_*& node)
		{
			if (node != NULL)
			{
				deleteTree(node->child[LEFT]);
				deleteTree(node->child[RIGHT]);
				alloc_.destroy(&node->content);
				nodeAlloc_.deallocate(node, 1);
			}
		};
		// Recursively copy tree from another tree. minimizing allocation.
		void	assignTree(node_*& this_node, node_* const& that_node)
		{
			alloc_.construct(this_node->content, that_node->content);
			this_node->color = that_node->color;
			for (int pos = LEFT; pos <= RIGHT; pos++)
			{
				if (that_node->child[pos] == NULL)
				{
					deleteTree(this_node->child[pos]);
					this_node->child[pos] = NULL;
				}
				else
				{
					if (this_node->child[pos] == NULL)
						this_node->child[pos] = nodeAlloc_.allocate(1);
					this_node->child[pos]->parent = this_node;
					assignTree(this_node->child[pos], that_node->child[pos]);
				}
			}
		};

	public:
		RedBlackTree(
			allocator_type const& alloc = allocator_type(),
			node_allocator_type_ const& node_alloc = node_allocator_type_()):
			alloc_(alloc),
			nodeAlloc_(node_alloc),
			root_(NULL)
		{
			pastTheEnd_ = nodeAlloc_.allocate(1);
			pastTheEnd_->parent = NULL;
			pastTheEnd_->child[LEFT] = root_;
			pastTheEnd_->child[RIGHT] = root_;
			pastTheEnd_->color = RED;
		};
		RedBlackTree(tree_ const& tree):
			alloc_(tree.alloc_),
			nodeAlloc_(tree.nodeAlloc_)
		{
			pastTheEnd_ = nodeAlloc_.allocate(1);
			pastTheEnd_->parent = NULL;
			pastTheEnd_->child[LEFT] = root_;
			pastTheEnd_->child[RIGHT] = root_;
			pastTheEnd_->color = RED;
			if (tree.root_ != NULL)
			{
				this->root_ = nodeAlloc_.allocate(1);
				this->root_->parent = pastTheEnd_;
				copyTree(this->root_, tree.root_);
			}
		};
		~RedBlackTree(void)
		{
			deleteTree(this->root_);
			nodeAlloc_.deallocate(pastTheEnd_, 1);
		};
		tree_&	operator=(tree_ const& tree)
		{
			if (tree.root_ != NULL)
			{
				if (this->root_ != NULL)
					this->root_ = nodeAlloc_.allocate(1);
				assignTree(this->root_, tree.root_);
			}
		};
		void	addValue(value_type const& val)
		{
			node_*	new_node = nodeAlloc_.allocate(1);
			alloc_.construct(&new_node->content, val);
			new_node->child[LEFT] = NULL;
			new_node->child[RIGHT] = NULL;
			new_node->color = RED;
			addNode(new_node);
		};
		void	addNode(node_* node)
		{
			if (!root_)
			{
				root_ = node;
				node->parent = pastTheEnd_;
				pastTheEnd_->child[LEFT] = root_;
				pastTheEnd_->child[RIGHT] = root_;
				return ;
			}
			node_*	node_next = root_;
			bool	is_right = RIGHT;
			while (node_next)
			{
				node->parent = node_next;
				if (node_next->content < node->content)
				{
					node_next = node_next->child[RIGHT];
					is_right = RIGHT;
				}
				else
				{
					node_next = node_next->child[LEFT];
					is_right = LEFT;
				}
			}
			if (is_right)
				node->parent->child[RIGHT] = node;
			else
				node->parent->child[LEFT] = node;
			if (node->parent->color == RED)
				node.rebalance();
		};

		iterator	begin(void)
		{ return (iterator(pastTheEnd_).toLeftMost()); };
		const_iterator	begin(void) const
		{ return (const_iterator(pastTheEnd_).toLeftMost()); };
		iterator	end(void)
		{ return (iterator(pastTheEnd_)); };
		const_iterator	end(void) const
		{ return (const_iterator(pastTheEnd_)); };
		reverse_iterator	rbegin(void)
		{ return (reverse_iterator(iterator(pastTheEnd_))); };
		const_reverse_iterator	rbegin(void) const
		{ return (const_reverse_iterator(const_iterator(pastTheEnd_))); };
		reverse_iterator	rend(void)
		{ return (reverse_iterator(iterator(pastTheEnd_).toLeftMost())); };
		const_reverse_iterator	rend(void) const
		{ return (const_reverse_iterator(const_iterator(pastTheEnd_).toLeftMost())); };

	};

	template	<typename Tp>
	class	TreeIterator
	{
	private:
		typedef TreeIterator<Tp>		iterator_;

	protected:
		typedef RedBlackTreeNode<Tp>	node;

		template	<typename _Tp>
		void	is_compatible(TreeIterator<_Tp> const&,
		typename enable_if<is_const_same<_Tp, Tp>::value>::type* = 0) const
		{};

	public:
		typedef bidirectional_iterator_tag	iterator_category;
		typedef Tp							value_type;
		typedef Tp&							reference;
		typedef Tp*							pointer;
		typedef std::ptrdiff_t				difference_type;

	private:
		node*				ptrToNode_;

		TreeIterator(reverse_iterator<iterator_>) {};

	protected:
		node*&		getNode_(void)
			{ return (ptrToNode_); };
		reference	reverse_reference(void)
		{
			iterator_ rev = --(*this);
			if (rev != NULL)
				return (rev.ptrToNode_->content);
			while (rev.ptrToNode_->parent)
				rev.ptrToNode_ = rev.ptrToNode_->parent;
			return (rev.ptrToNode_->content);
		};

	public:
		TreeIterator(void):
			ptrToNode_(NULL) {};
		TreeIterator(iterator_ const& iter):
			ptrToNode_(iter.ptrToNode_) {};
		TreeIterator(node* const& node):
			ptrToNode_(node) {};
				template	<typename _Tp>
		TreeIterator(TreeIterator<_Tp> const& iter):
			ptrToNode_(((iterator_*)(&iter))->ptrToNode_)
		{
			typename disable_if<is_const_of<Tp, _Tp>::value>::type* dummy;
			(void)dummy;
		};
		virtual ~TreeIterator(void) {};

		iterator_&	toLeftMost(void)
		{
			if (ptrToNode_->child[LEFT])
			{
				ptrToNode_ = ptrToNode_->child[LEFT];
				toLeftMost();
			}
			return (*this);
		}
		iterator_&	toRightMost(void)
		{
			if (ptrToNode_->child[RIGHT])
			{
				ptrToNode_ = ptrToNode_->child[RIGHT];
				toRightMost();
			}
			return (*this);
		}

		iterator_&	operator=(iterator_ const& iter)
		{
			this->ptrToNode_ = iter.ptrToNode_;
			return (*this);
		}
		template	<typename _Tp>
		iterator_&	operator=(TreeIterator<_Tp> const& iter)
		{
			typename enable_if<is_const_same<_Tp, Tp>::value>::type*	dummy;
			(void)dummy;
			this->ptrToNode_ = ((iterator_*)(&iter))->ptrToNode_;
			return (*this);
		};
		reference	operator*(void)
		{ return (this->ptrToNode_->content); };

		template	<typename _Tp>
		friend bool	operator==(iterator_ const& lhs, TreeIterator<_Tp> const& rhs)
		{
			typename enable_if<is_const_same<_Tp, Tp>::value>::type*	dummy;
			(void)dummy;
			return (lhs.ptrToNode_ == ((iterator_*)(&rhs))->ptrToNode_);
		};
		iterator_&	operator++(void)
		{
			if (ptrToNode_->child[RIGHT])
			{
				ptrToNode_ = ptrToNode_->child[RIGHT];
				toLeftMost();
				return (*this);
			}
			while (ptrToNode_->parent && ptrToNode_->parent->child[LEFT] != ptrToNode_)
				ptrToNode_ = ptrToNode_->parent;
			if (ptrToNode_->parent)
				ptrToNode_ = ptrToNode_->parent;
			return (*this);
		};
		iterator_	operator++(int)
		{
			iterator_	temp = *this;
			++*this;
			return (temp);
		};
		iterator_&	operator--(void)
		{
			if (ptrToNode_->child[LEFT])
			{
				ptrToNode_ = ptrToNode_->child[LEFT];
				toRightMost();
				return (*this);
			}
			while (ptrToNode_->parent && ptrToNode_->parent->child[RIGHT] != ptrToNode_)
				ptrToNode_ = ptrToNode_->parent;
			if (ptrToNode_->parent)
				ptrToNode_ = ptrToNode_->parent;
			else
				ptrToNode_ = NULL;
			return (*this);
		};
		iterator_	operator--(int)
		{
			iterator_	temp = *this;
			--*this;
			return (temp);
		};
		pointer		operator->(void) const
			{ return (&this->ptrToNode_->content); };
	};
}

#endif