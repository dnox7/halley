package ac

func rotateRight(head *ListNode, k int) *ListNode {
	if head == nil || k == 0 {
		return head
	}

	dummy := head
	n := 1
	for dummy.Next != nil {
		n++
		dummy = dummy.Next
	}

	k = k % n
	if k == 0 {
		return head
	}

	i := 1
	newLast := head
	for i < n-k {
		newLast = newLast.Next
		i++
	}

	newHead := newLast.Next
	newLast.Next = nil
	dummy.Next = head
	return newHead
}
