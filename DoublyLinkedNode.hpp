namespace ft
{
	template	<typename Tp>
	struct	DoublyLinkedNode
	{
		Tp*						content;
		DoublyLinkedNode<Tp>*	next;
		DoublyLinkedNode<Tp>*	prev;
	};
}