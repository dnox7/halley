package ac

func middleNode(head *ListNode) *ListNode {
	tail := head
	middle := head
	for tail != nil && tail.Next != nil {
		tail = tail.Next.Next
		middle = middle.Next
	}
	return middle
}
