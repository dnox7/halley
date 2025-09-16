package ac

func sortedArrayToBST(nums []int) *TreeNode {
	var build func(start, end int) *TreeNode
	build = func(start, end int) *TreeNode {
		if start > end {
			return nil
		}
		mid := start + (end-start)/2
		root := &TreeNode{Val: nums[mid]}
		root.Left = build(start, mid)
		root.Right = build(mid+1, end)
		return root
	}
	return build(0, len(nums)-1)
}
