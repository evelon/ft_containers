#ifndef REDBLACKTREE_HPP
# define REDBLACKTREE_HPP

# include <memory>
# include "template_utils.hpp"
# include "iterator.hpp"
# include "reverse_iterator.hpp"

# define PAST_THE_END -2
# define ROOT -1
# define LEFT 0
# define RIGHT 1
# define RED true
# define BLACK false

# define IDENTIFY(X, Y) (X->parent->child[Y] == X)
# define IS_ROOT(X) (IDENTIFY(X, RIGHT) && IDENTIFY(X, LEFT))


#include <iostream>

namespace	ft
{
	template	<typename Tp>
	struct	RedBlackTreeNode;

	template	<typename Tp, class Compare = less<Tp>, class Alloc = std::allocator<Tp> >
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

		RedBlackTreeNode(node const& nod):
			content(nod.content),
			color(nod.color)
		{};
		~RedBlackTreeNode(void) {};
		node&	operator=(node const& nod)
		{
			this->content = nod.content;
			this->color = nod.color;
		}
		node*	sibling(void)
		{
			if (IS_ROOT(this))
				return (NULL);
			if (IDENTIFY(this, LEFT))
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
			node*	new_left = this;
			node*	new_parent = this->child[RIGHT];

			if (IDENTIFY(this, LEFT))
				this->parent->child[LEFT] = new_parent;
			if (IDENTIFY(this, RIGHT))
				this->parent->child[RIGHT] = new_parent;
			new_parent->parent = this->parent;
			new_left->child[RIGHT] = this->child[RIGHT]->child[LEFT];
			if (new_left->child[RIGHT])
				new_left->child[RIGHT]->parent = new_left;
			new_parent->child[LEFT] = new_left;
			new_left->parent = new_parent;
			new_parent->color = BLACK;
			new_left->color = RED;
		}
		void	rightRotate(void)
		{
			node*	new_right = this;
			node*	new_parent = this->child[LEFT];

			if (IDENTIFY(this, LEFT))
				this->parent->child[LEFT] = new_parent;
			if (IDENTIFY(this, RIGHT))
				this->parent->child[RIGHT] = new_parent;
			new_parent->parent = this->parent;
			new_right->child[LEFT] = this->child[LEFT]->child[RIGHT];
			if (new_right->child[LEFT])
				new_right->child[LEFT]->parent = new_right;
			new_parent->child[RIGHT] = new_right;
			new_right->parent = new_parent;
			new_parent->color = BLACK;
			new_right->color = RED;
		}
		void	leftRightRotate(void)
		{
			node*	new_parent = this->child[LEFT]->child[RIGHT];
			node*	new_left = this->child[LEFT];
			node*	new_right = this;

			if (IDENTIFY(this, LEFT))
				this->parent->child[LEFT] = new_parent;
			if (IDENTIFY(this, RIGHT))
				this->parent->child[RIGHT] = new_parent;
			new_parent->parent = this->parent;
			new_right->child[LEFT] = new_parent->child[RIGHT];
			if (new_right->child[LEFT])
				new_right->child[LEFT]->parent = new_right;
			new_left->child[RIGHT] = new_parent->child[LEFT];
			if (new_left->child[RIGHT])
				new_left->child[RIGHT]->parent = new_left;
			new_parent->child[LEFT] = new_left;
			new_left->parent = new_parent;
			new_parent->child[RIGHT] = new_right;
			new_right->parent = new_parent;
		}
		void	rightLeftRotate(void)
		{
			node*	new_parent = this->child[RIGHT]->child[LEFT];
			node*	new_right = this->child[RIGHT];
			node*	new_left = this;

			if (IDENTIFY(this, LEFT))
				this->parent->child[LEFT] = new_parent;
			if (IDENTIFY(this, RIGHT))
				this->parent->child[RIGHT] = new_parent;
			new_parent->parent = this->parent;
			new_left->child[RIGHT] = new_parent->child[LEFT];
			if (new_left->child[RIGHT])
				new_left->child[RIGHT]->parent = new_left;
			new_right->child[LEFT] = new_parent->child[RIGHT];
			if (new_right->child[LEFT])
				new_right->child[LEFT]->parent = new_right;
			new_parent->child[LEFT] = new_left;
			new_left->parent = new_parent;
			new_parent->child[RIGHT] = new_right;
			new_right->parent = new_parent;
		}
		void	restruct(void)
		{
			node*	p = this->parent;
			node*	g = this->grand();

			if (IDENTIFY(this, LEFT))
			{
				if (IDENTIFY(p, LEFT))
					g->rightRotate();
				else
					g->rightLeftRotate();
			}
			else
			{
				if (IDENTIFY(p, LEFT))
					g->leftRightRotate();
				else
					g->leftRotate();
			}
		}
		void	recolor(void)
		{
			node*	p = this->parent;
			node*	g = this->grand();
			node*	u = this->uncle();

			if (u)
				u->color = BLACK;
			if (IS_ROOT(p))
				return ;
			p->color = BLACK;
			if (IS_ROOT(g))
				return ;
			g->color = RED;
			if (!IS_ROOT(g->parent) && g->parent->color == RED)
				g->rebalance();
		}
		void	rebalance(void)
		{
			if (!this->uncle() || this->uncle()->color == BLACK)
				this->restruct();
			else
				this->recolor();
		}
	private:
		RedBlackTreeNode(void);
	};

	template	<typename Tp, class Compare, class Alloc>
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
		Compare					comp;
		allocator_type			alloc_;
		node_allocator_type_	nodeAlloc_;
		node_*					superRoot_;

		node_*&	getRoot(void)
		{ return (superRoot_->child[LEFT]); };
		void	setRoot(node_* node)
		{
			superRoot_->child[LEFT] = node;
			superRoot_->child[RIGHT] = node;
		}
		// Recursively copy tree.
		void	copyTree(node_*& this_node, node_* const& that_node)
		{
			alloc_.construct(this_node->content, that_node->content);
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
		iterator	addNode(value_type const& val, bool unique)
		{
			node_*	node;

			if (!getRoot())
			{
				node = nodeAlloc_.allocate(1);
				alloc_.contruct(&node->content, val);
				node->color = BLACK;
				node->parent = superRoot_;
				setRoot(node);
				return ;
			}
			node_*	node_next = getRoot();
			int		pos = ROOT;
			while (node_next)
			{
				node->parent = node_next;
				if (comp(node_next->content, val))
				{
					node_next = node_next->child[RIGHT];
					pos = RIGHT;
				}
				else
				{
					if (unique && val == node_next->content)
						return (iterator(node_next));
					node_next = node_next->child[LEFT];
					pos = LEFT;
				}
			}
			node = nodeAlloc_.allocate(1);
			alloc_.contruct(&node->content, val);
			node->child[LEFT] = NULL;
			node->child[RIGHT] = NULL;
			node->color = RED;
			if (pos == RIGHT)
				node->parent->child[RIGHT] = node;
			else
				node->parent->child[LEFT] = node;
			if (node->parent->color == RED)
				node->rebalance();
		};

	public:
		RedBlackTree(
			allocator_type const& alloc = allocator_type(),
			node_allocator_type_ const& node_alloc = node_allocator_type_()):
			comp(Compare()),
			alloc_(alloc),
			nodeAlloc_(node_alloc)
		{
			superRoot_ = nodeAlloc_.allocate(1);
			superRoot_->parent = NULL;
			setRoot(NULL);
			superRoot_->color = RED;
		};
		RedBlackTree(tree_ const& tree):
			comp(Compare()),
			alloc_(tree.alloc_),
			nodeAlloc_(tree.nodeAlloc_)
		{
			superRoot_ = nodeAlloc_.allocate(1);
			superRoot_->parent = NULL;
			superRoot_->color = RED;
			if (tree.root() != NULL)
			{
				node_*	root = nodeAlloc_.allocate(1);
				root->parent = this->superRoot_;
				setRoot(root);
				copyTree(root, tree.getRoot());
			}
		};
		~RedBlackTree(void)
		{
			deleteTree(this->getRoot());
			nodeAlloc_.deallocate(superRoot_, 1);
		};
		tree_&	operator=(tree_ const& tree)
		{
			if (tree.getRoot() != NULL)
			{
				if (this->getRoot() != NULL)
					this->getRoot() = nodeAlloc_.allocate(1);
				assignTree(this->getRoot(), tree.getRoot());
			}
		};
		iterator	insert(value_type const& val, bool unique)
		{
			return (addNode(val, unique));
		};
		iterator	insert(iterator position, value_type const& val, bool unique)
		{
			node_*	node;
			if (unique)
			{
				if (*position < val)
				node = position->ptrToNode_
			}

			return (addNode(val, unique));
		};

		iterator	begin(void)
		{ return (iterator(superRoot_).toLeftMost()); };
		const_iterator	begin(void) const
		{ return (const_iterator(superRoot_).toLeftMost()); };
		iterator	end(void)
		{ return (iterator(superRoot_)); };
		const_iterator	end(void) const
		{ return (const_iterator(superRoot_)); };
		reverse_iterator	rbegin(void)
		{ return (reverse_iterator(iterator(superRoot_))); };
		const_reverse_iterator	rbegin(void) const
		{ return (const_reverse_iterator(const_iterator(superRoot_))); };
		reverse_iterator	rend(void)
		{ return (reverse_iterator(iterator(superRoot_).toLeftMost())); };
		const_reverse_iterator	rend(void) const
		{ return (const_reverse_iterator(const_iterator(superRoot_).toLeftMost())); };

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