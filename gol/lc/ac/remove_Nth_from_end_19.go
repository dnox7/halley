package ac

func removeNthFromEnd(head *ListNode, n int) *ListNode {
	dummy := &ListNode{Next: head}
	res := dummy
	for i := 0; i < n; i++ {
		head = head.Next
	}
	for head != nil {
		head = head.Next
		dummy = dummy.Next
	}

	dummy.Next = dummy.Next.Next
	return res.Next
}
