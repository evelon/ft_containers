#ifndef REDBLACKTREE_HPP
# define REDBLACKTREE_HPP

# include <memory>
# include "template_utils.hpp"
# include "pair.hpp"
# include "iterator.hpp"
# include "reverse_iterator.hpp"
# include "relational_operator_impl.hpp"

# define ROOT -1
# define LEFT 0
# define RIGHT 1
# define RED true
# define BLACK false

# define IDENTIFY(X, Y) (X->parent->child[Y] == X)
# define POSITION(X) (X->parent->child[RIGHT] == X)
# define IS_ROOT(X) (IDENTIFY(X, RIGHT) && IDENTIFY(X, LEFT))
# define COLOR(X) (X ? X->color : BLACK)


#include <iostream>

namespace	ft
{
	template	<typename Tp, class Alloc = std::allocator<Tp> >
	struct	RedBlackTreeNode;

	template	<typename Tp, class Compare = less<Tp>, class Alloc = std::allocator<Tp> >
	class	RedBlackTree;

	template	<typename Tp, class Compare, class Alloc>
	bool	operator==(RedBlackTree<Tp, Compare, Alloc> const& lhs, RedBlackTree<Tp, Compare, Alloc> const& rhs);

	template	<typename Tp, class Compare, class Alloc>
	bool	operator<(RedBlackTree<Tp, Compare, Alloc> const& lhs, RedBlackTree<Tp, Compare, Alloc> const& rhs);

	template	<typename Tp>
	class	TreeIterator;

	template	<typename Tp, typename _Tp>
	bool	operator==(TreeIterator<Tp> const& lhs, TreeIterator<_Tp> const& rhs);

	template	<typename Tp, class Alloc>
	struct	RedBlackTreeNode
	{
		typedef Tp										value_type;
		typedef Alloc									allocator_type;
		typedef RedBlackTreeNode						node;
		typedef int										position;
		typedef bool									color_type;

		static allocator_type		alloc;
		value_type					content;
		node*						parent;
		node*						child[2];
		color_type					color;

		RedBlackTreeNode(node const& nod):
			content(nod.content),
			parent(nod.parent),
			color(nod.color)
		{
			this->child[LEFT] = nod.child[LEFT];
			this->child[RIGHT] = nod.child[RIGHT];
		};
		~RedBlackTreeNode(void) {};
		node&	operator=(node const& nod)
		{
			this->content = nod.content;
			this->parent = nod.parent;
			this->child = nod.child;
			this->color = nod.color;
			return (*this);
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
			if (new_parent)
				new_parent->parent = this->parent;
			new_left->child[RIGHT] = new_parent ? new_parent->child[LEFT] : NULL;
			if (new_left->child[RIGHT])
				new_left->child[RIGHT]->parent = new_left;
			if (new_parent)
				new_parent->child[LEFT] = new_left;
			new_left->parent = new_parent;
			if (new_parent)
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
			if (new_parent)
				new_parent->parent = this->parent;
			new_right->child[LEFT] = new_parent ? new_parent->child[RIGHT] : NULL;
			if (new_right->child[LEFT])
				new_right->child[LEFT]->parent = new_right;
			if (new_parent)
				new_parent->child[RIGHT] = new_right;
			new_right->parent = new_parent;
			if (new_parent)
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
				g->insertRebalance();
		}
		void	insertRebalance(void)
		{
			if (!this->uncle() || this->uncle()->color == BLACK)
				this->restruct();
			else
				this->recolor();
		}
	private:
		RedBlackTreeNode(void);
	};

	template	<typename Tp, class Alloc>
	typename RedBlackTreeNode<Tp, Alloc>::allocator_type	RedBlackTreeNode<Tp, Alloc>::alloc = allocator_type();

	template	<typename Tp, class Compare, class Alloc>
	class	RedBlackTree
	{
	private:
		typedef RedBlackTree									tree_;
		typedef RedBlackTreeNode<Tp>							node_;
		typedef typename Alloc::template rebind<node_>::other	node_allocator_type_;

	public:
		typedef Tp												value_type;
		typedef Compare											value_compare;
		typedef Alloc											allocator_type;
		typedef typename Alloc::reference						reference;
		typedef typename Alloc::const_reference					const_reference;
		typedef typename Alloc::pointer							pointer;
		typedef typename Alloc::const_pointer					const_pointer;
		typedef TreeIterator<const Tp>							const_iterator;
		typedef TreeIterator<Tp>								iterator;
		typedef reverse_iterator<const_iterator>				const_reverse_iterator;
		typedef reverse_iterator<iterator>						reverse_iterator;
		typedef ptrdiff_t										difference_type;
		typedef size_t											size_type;

	private:
		Compare					comp_;
		allocator_type			alloc_;
		node_allocator_type_	nodeAlloc_;
		node_*					superRoot_;
		size_type				size_;

		bool	equal(value_type const& x, value_type const& y)
		{ return (!comp_(x, y) && !comp_(y, x)); };

		node_*&	getRoot(void) const
		{ return (superRoot_->child[LEFT]); };
		void	setRoot(node_* node)
		{
			superRoot_->child[LEFT] = node;
			superRoot_->child[RIGHT] = node;
			if (node)
				node->parent = superRoot_;
		}
		// Recursively copy tree.
		void	copyTree(node_*& this_node, node_* const& that_node)
		{
			alloc_.construct(&this_node->content, that_node->content);
			for (int pos = LEFT; pos <= RIGHT; pos++)
			{
				if (that_node->child[pos] == NULL)
					this_node->child[pos] = NULL;
				else
				{
					this_node->child[pos] = nodeAlloc_.allocate(1);
					this_node->child[pos]->parent = this_node;
					copyTree(this_node->child[pos], that_node->child[pos]);
				}
			}
		};
		// Recursively delete tree.
		void	deleteTree(node_* node)
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
			alloc_.construct(&this_node->content, that_node->content);
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
					{
						this_node->child[pos] = nodeAlloc_.allocate(1);
						this_node->child[pos]->parent = this_node;
						this_node->child[pos]->child[LEFT] = NULL;
						this_node->child[pos]->child[RIGHT] = NULL;
					}
					else
						alloc_.destroy(&this_node->child[pos]->content);
					assignTree(this_node->child[pos], that_node->child[pos]);
				}
			}
		};
		node_*	newNode(value_type const& val)
		{
			node_*	node = nodeAlloc_.allocate(1);
			alloc_.construct(&node->content, val);
			node->child[LEFT] = NULL;
			node->child[RIGHT] = NULL;
			node->color = RED;
			++size_;
			return (node);
		};
		pair<iterator, bool>	addNode(value_type const& val, bool unique)
		{
			node_*	node;

			if (!getRoot())
			{
				node = nodeAlloc_.allocate(1);
				alloc_.construct(&node->content, val);
				node->color = BLACK;
				node->parent = superRoot_;
				node->child[LEFT] = NULL;
				node->child[RIGHT] = NULL;
				setRoot(node);
				++size_;
				return (pair<iterator, bool>(iterator(node), true));
			}
			node_*	node_next = getRoot();
			node_*	parent_node;
			int		pos = ROOT;
			while (node_next)
			{
				parent_node = node_next;
				if (comp_(node_next->content, val))
				{
					node_next = node_next->child[RIGHT];
					pos = RIGHT;
				}
				else
				{
					if (unique && equal(node_next->content, val))
						return (pair<iterator, bool>(iterator(node_next), false));
					node_next = node_next->child[LEFT];
					pos = LEFT;
				}
			}
			node = newNode(val);
			node->parent = parent_node;
			if (pos == RIGHT)
				node->parent->child[RIGHT] = node;
			else
				node->parent->child[LEFT] = node;
			if (node->parent->color == RED)
				node->insertRebalance();
			return (pair<iterator, bool>(iterator(node), true));
		};
		void	reduceBlack(node_* parent, bool position)
		{
			node_*	p = parent;
			node_*	s = parent->child[!position];
			node_*	l = s ? s->child[LEFT] : NULL;
			node_*	r = s ? s->child[RIGHT] : NULL;

			// case 1-1
			if (COLOR(p) == RED && COLOR(l) == BLACK && COLOR(r) == BLACK)
			{
				p->color = BLACK;
				if (s)
					s->color = RED;
				return ;
			}
			// case *-2
			if (COLOR(s) == BLACK && COLOR(r) == RED)
			{
				if (position == LEFT)
					p->leftRotate();
				else
					p->rightRotate();
				bool	temp = p->color;
				p->color = s->color;
				s->color = temp;
				r->color = BLACK;
				return ;
			}
			// case *-3
			if (COLOR(s) == BLACK && COLOR(r) == BLACK && COLOR(l) == RED)
			{
				s->rightRotate();
				l->color = BLACK;
				s->color = RED;
				r = s;
				s = l;
				if (position == LEFT)
					p->leftRotate();
				else
					p->rightRotate();
				bool	temp = p->color;
				p->color = s->color;
				s->color = temp;
				r->color = BLACK;
				return ;
			}
			// case 2-1
			if (COLOR(p) == BLACK && COLOR(s) == BLACK && COLOR(l) == BLACK && COLOR(r) == BLACK)
			{
				if (s)
					s->color = RED;
				if (IS_ROOT(p))
					return ;
				reduceBlack(p->parent, POSITION(p));
				return ;
			}
			// case 2-4
			if (COLOR(p) == BLACK && COLOR(s) == RED)
			{
				if (position == LEFT)
					p->leftRotate();
				else
					p->rightRotate();
				bool	temp = p->color;
				p->color = s->color;
				s->color = temp;
				reduceBlack(p, position);
			}
		};
		void	deleteNode(node_* node)
		{
			if (node->child[LEFT] && node->child[RIGHT])
			{
				node_*	next_node = iterator(node->child[RIGHT]).toLeftMost().getNode();
				node_	temp = *next_node;
				if (next_node->parent == node)
				{
					if (IS_ROOT(node))
						setRoot(next_node);
					else
					{
						node->parent->child[POSITION(node)] = next_node;
						next_node->parent = node->parent;
					}
					next_node->child[LEFT] = node->child[LEFT];
					next_node->child[LEFT]->parent = next_node;
					next_node->child[RIGHT] = node;
					next_node->color = node->color;
					node->parent = next_node;
					node->child[LEFT] = temp.child[LEFT];
					if (node->child[LEFT])
						node->child[LEFT]->parent = node;
					node->child[RIGHT] = temp.child[RIGHT];
					if (node->child[RIGHT])
						node->child[RIGHT]->parent = node;
					node->color = temp.color;
				}
				else
				{
					if (IS_ROOT(node))
						setRoot(next_node);
					else
					{
						node->parent->child[POSITION(node)] = next_node;
						next_node->parent = node->parent;
					}
					next_node->child[LEFT] = node->child[LEFT];
					next_node->child[LEFT]->parent = next_node;
					next_node->child[RIGHT] = node->child[RIGHT];
					next_node->child[RIGHT]->parent = next_node;
					next_node->color = node->color;
					node->parent = temp.parent;
					if (node->parent->child[LEFT] == next_node)
						node->parent->child[LEFT] = node;
					else
						node->parent->child[RIGHT] = node;
					node->child[LEFT] = temp.child[LEFT];
					if (node->child[LEFT])
						node->child[LEFT]->parent = node;
					node->child[RIGHT] = temp.child[RIGHT];
					if (node->child[RIGHT])
						node->child[RIGHT]->parent = node;
					node->color = temp.color;
				}
				deleteNode(node);
				return ;
			}
			node_*	only_child = node->child[LEFT] ? node->child[LEFT] : node->child[RIGHT];
			node_*	parent = node->parent;
			bool	position;
			if (only_child)
				only_child->parent = parent;
			if (IS_ROOT(node))
			{
				setRoot(only_child);
				if (COLOR(only_child) == RED)
					only_child->color = BLACK;
				alloc_.destroy(&node->content);
				nodeAlloc_.deallocate(node, 1);
				--size_;
				return ;
			}
			else if (IDENTIFY(node, RIGHT))
			{
				position = RIGHT;
				parent->child[RIGHT] = only_child;
			}
			else
			{
				position = LEFT;
				parent->child[LEFT] = only_child;
			}
			bool	node_color = node->color;
			alloc_.destroy(&node->content);
			nodeAlloc_.deallocate(node, 1);
			--size_;
			if (node_color ^ COLOR(only_child))
			{
				if (COLOR(only_child) == RED)
					only_child->color = BLACK;
				return ;
			}
			reduceBlack(parent, position);
		};

	public:
		RedBlackTree(
			value_compare const& comp = value_compare(),
			allocator_type const& alloc = allocator_type(),
			node_allocator_type_ const& node_alloc = node_allocator_type_()):
			comp_(comp),
			alloc_(alloc),
			nodeAlloc_(node_alloc),
			size_(0)
		{
			superRoot_ = nodeAlloc_.allocate(1);
			superRoot_->parent = NULL;
			setRoot(NULL);
			superRoot_->color = RED;
		};
		RedBlackTree(tree_ const& tree):
			comp_(tree.comp_),
			alloc_(tree.alloc_),
			nodeAlloc_(tree.nodeAlloc_),
			size_(tree.size_)
		{
			superRoot_ = nodeAlloc_.allocate(1);
			superRoot_->parent = NULL;
			superRoot_->color = RED;
			if (tree.getRoot() != NULL)
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
				if (this->getRoot() == NULL)
				{
					node_*	node = nodeAlloc_.allocate(1);
					node->child[LEFT] = NULL;
					node->child[RIGHT] = NULL;
					node->color = RED;
					this->setRoot(node);
				}
				else
					alloc_.destroy(&this->getRoot()->content);
				assignTree(this->getRoot(), tree.getRoot());
			}
			else
			{
				deleteTree(this->getRoot());
				this->setRoot(NULL);
			}
			this->size_ = tree.size_;
			return (*this);
		};

		iterator	begin(void)
			{ return (iterator(superRoot_).toLeftMost()); };
		const_iterator	begin(void) const
			{ return (const_iterator(iterator(superRoot_)).toLeftMost()); };
		iterator	end(void)
			{ return (iterator(superRoot_)); };
		const_iterator	end(void) const
			{ return (const_iterator(iterator(superRoot_))); };
		reverse_iterator	rbegin(void)
			{ return (reverse_iterator(iterator(superRoot_))); };
		const_reverse_iterator	rbegin(void) const
			{ return (const_reverse_iterator(iterator(superRoot_))); };
		reverse_iterator	rend(void)
			{ return (reverse_iterator(iterator(superRoot_).toLeftMost())); };
		const_reverse_iterator	rend(void) const
			{ return (const_reverse_iterator(iterator(superRoot_).toLeftMost())); };

		bool	empty(void) const
			{ return (!size_); };
		size_type	size(void) const
			{ return (size_); };
		size_type	max_size(void) const
		{
			if (nodeAlloc_.max_size() < std::numeric_limits<size_type>::max())
				return (nodeAlloc_.max_size());
			return (std::numeric_limits<size_type>::max());
		};

		pair<iterator, bool>	insert(value_type const& val, bool unique)
			{ return (addNode(val, unique)); };
		iterator	insert(iterator position, value_type const& val, bool unique)
		{
			node_*	prev_node = position.getNode();
			node_*	next_node = (++position).getNode();

			if ((unique && prev_node->content < val && next_node->content > val)
				|| (!unique && prev_node->content <= val && next_node->content >= val))
			{
				node_*	new_node;
				new_node = newNode(val);
				if (!prev_node->child[RIGHT])
				{
					prev_node->child[RIGHT] = new_node;
					new_node->parent = prev_node;
				}
				else
				{
					next_node->child[LEFT] = new_node;
					new_node->parent = next_node;
				}
			}
			return (addNode(val, unique).first);
		};
		template <class InputIterator>
		void	insert(InputIterator first, InputIterator last, bool unique)
		{
			iterator	hint = begin();
			for (InputIterator it = first; it != last; ++it)
				hint = insert(hint, *it, unique);
		};

		void	erase(iterator position)
		{
			deleteNode(position.getNode());
		}
		size_type	erase(value_type const&	val)
		{
			pair<iterator, iterator> 	range = equal_range(val);
			size_type	count = 0;
			for (iterator it = range.first; it != range.second;)
			{
				erase(it++);
				++count;
			}
			return (count);
		};
		void	erase(iterator first, iterator last)
		{
			for (iterator it = first; it != last;)
				erase(it++);
		};
		void	clear(void)
		{
			deleteTree(getRoot());
			setRoot(NULL);
			size_ = 0;
		}
		value_compare	value_comp() const
			{ return (comp_); };
		iterator	find(value_type const& val)
		{
			node_*	node = getRoot();
			while (node)
			{
				if (equal(node->content, val))
					break ;
				if (comp_(node->content, val))
					node = node->child[RIGHT];
				else
					node = node->child[LEFT];
			}
			if (!node)
				return (end());
			return (iterator(node));
		};
		const_iterator	find(value_type const& val) const
		{
			iterator	it = find(val);
			return (const_iterator(it));
		};
		size_type	count(value_type const& val) const
		{
			node_*	node = getRoot();
			while (node)
			{
				if (equal(node->content, val))
					break ;
				if (comp_(node->content, val))
					node = node->child[RIGHT];
				else
					node = node->child[LEFT];
			}
			if (!node)
				return (0);
			iterator	it(node);
			size_type	count = 0;
			while (equal(*it, val))
			{
				++count;
				++it;
			}
			it = --iterator(node);
			while (equal(*it, val))
			{
				++count;
				--it;
			}
			return (count);
		};

		iterator	lower_bound(value_type const& val)
		{
			iterator	it = begin();
			while (comp_(*it, val) && it != end())
				++it;
			return (it);
		};
		const_iterator	lower_bound(value_type const& val) const
		{
			const_iterator	it = begin();
			while (comp_(*it, val) && it != end())
				++it;
			return (it);
		};
		iterator	upper_bound(value_type const& val)
		{
			iterator	it = begin();
			while (!comp_(val, *it) && it != end())
				++it;
			return (it);
		};
		const_iterator	upper_bound(value_type const& val) const
		{
			const_iterator	it = begin();
			while (!comp_(val, *it) && it != end())
				++it;
			return (it);
		};
		pair<iterator, iterator>	equal_range(value_type const& val)
			{ return (pair<iterator, iterator>(lower_bound(val), upper_bound(val))); };
		pair<const_iterator, const_iterator>	equal_range(value_type const& val) const
			{ return (pair<const_iterator, const_iterator>(lower_bound(val), upper_bound(val))); };
	};

	template	<typename Tp, class Compare, class Alloc>
	bool	operator==(RedBlackTree<Tp, Compare, Alloc> const& lhs, RedBlackTree<Tp, Compare, Alloc> const& rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		typename RedBlackTree<Tp, Compare, Alloc>::const_iterator	lit = lhs.begin();
		typename RedBlackTree<Tp, Compare, Alloc>::const_iterator	rit = lhs.begin();
		while (lit != lhs.end())
		{
			if (!(*lit == *rit))
				return (false);
			++lit;
			++rit;
		}
		return (true);
	};

	template	<typename Tp, class Compare, class Alloc>
	bool	operator<(RedBlackTree<Tp, Compare, Alloc> const& lhs, RedBlackTree<Tp, Compare, Alloc> const& rhs)
	{
		typename RedBlackTree<Tp, Compare, Alloc>::const_iterator	lit = lhs.begin();
		typename RedBlackTree<Tp, Compare, Alloc>::const_iterator	rit = lhs.begin();
		while (lit != lhs.end())
		{
			if (*lit < *rit)
				return (true);
			if (*lit > *rit)
				return (false);
			++lit;
			++rit;
		}
		if (rit == rhs.end())
			return (false);
		return (true);
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
		template	<typename value_type, typename, typename>
		friend class RedBlackTree;

	protected:
		TreeIterator(node* const& node):
			ptrToNode_(node) {};

		reference	reverse_reference(void)
		{
			iterator_ rev = --(*this);
			if (rev != NULL)
				return (rev.ptrToNode_->content);
			while (rev.ptrToNode_->parent)
				rev.ptrToNode_ = rev.ptrToNode_->parent;
			return (rev.ptrToNode_->content);
		};
				node*&		getNode(void)
			{ return (ptrToNode_); };

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

	public:
		TreeIterator(void):
			ptrToNode_(NULL) {};
		TreeIterator(iterator_ const& iter):
			ptrToNode_(iter.ptrToNode_) {};
		template	<typename _Tp>
		TreeIterator(TreeIterator<_Tp> const& iter):
			ptrToNode_(((iterator_*)(&iter))->ptrToNode_)
		{
			typename disable_if<is_const_of<Tp, _Tp>::value>::type* dummy;
			(void)dummy;
		};
		virtual ~TreeIterator(void) {};

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
			while (ptrToNode_->parent && POSITION(ptrToNode_) != LEFT)
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
			while (ptrToNode_->parent && POSITION(ptrToNode_) != RIGHT)
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
