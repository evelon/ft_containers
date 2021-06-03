#ifndef BINARYTREE_HPP
# define BINARYTREE_HPP

# include <memory>

namespace	ft
{
	template	<typename Tp>
	struct	BinaryTreeNode;

	template	<typename Tp, class Alloc = std::allocator<Tp> >
	class	BinaryTree;

	template	<typename Tp>
	struct	BinaryTreeNode
	{
		typedef Tp										value_type;
		typedef BinaryTreeNode							node;

		value_type*				content;
		node*					parent;
		node*					child[2];
	};

	template	<typename Tp, class Alloc = std::allocator<Tp> >
	class	BinaryTree
	{
	private:
		typedef BinaryTreeNode<Tp>								node_;
		typedef typename Alloc::template rebind<node_>::other	node_allocator_type_;
		typedef enum e_position { left, right }					position_;

	public:
		typedef Tp												value_type;
		typedef Alloc											allocator_type;
		typedef typename Alloc::reference						reference;
		typedef typename Alloc::const_reference					const_reference;
		typedef typename Alloc::pointer							pointer;
		typedef typename Alloc::const_pointer					const_pointer;

	private:
		allocator_type			alloc_;
		node_allocator_type_	nodeAlloc_;
		node_*					root_;
		static const node_*		leaf = NULL;

	public:
		BinaryTree(
			allocator_type const& alloc = allocator_type(),
			node_allotor_type const& node_alloc = node_allocator_type()):
			alloc_(alloc),
			nodeAlloc_(node_alloc)
		{
			root_ = alloc_.allocate(1);
			root_.content = NULL;
			root_.parent = NULL;
			root_.child[left] = leaf;
			root_.child[right] = leaf;
		}
		BinaryTree(value_type const& val,
			allocator_type const& alloc = allocator_type(),
			node_allotor_type const& node_alloc = node_allocator_type()):
			alloc_(alloc),
			nodeAlloc_(node_alloc)
		{

		}
	};
}

#endif