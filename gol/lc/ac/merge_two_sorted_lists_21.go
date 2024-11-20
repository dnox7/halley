package ac

func mergeTwoLists(list1 *ListNode, list2 *ListNode) *ListNode {
	var dummy = new(ListNode)
	res := dummy
	for list1 != nil || list2 != nil {
		val := 1000
		var minNode *ListNode
		if list1 != nil {
			val = list1.Val
			minNode = list1
		}
		if list2 != nil {
			if val > list2.Val {
				minNode = list2
			}
		}
		if list1 != nil && minNode == list1 {
			list1 = list1.Next
		}
		if list2 != nil && minNode == list2 {
			list2 = list2.Next
		}
		dummy.Next = minNode
		dummy = dummy.Next
	}
	return res.Next
}
