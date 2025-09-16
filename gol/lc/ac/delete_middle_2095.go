package ac

func deleteMiddle(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}

	tail := head
	middle := head
	prevMiddle := &ListNode{Next: middle}

	for tail != nil && tail.Next != nil {
		tail = tail.Next.Next
		middle = middle.Next
		prevMiddle = prevMiddle.Next
	}

	prevMiddle.Next = middle.Next
	return head
}
