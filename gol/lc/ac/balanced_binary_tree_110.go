package ac

func isBalanced(root *TreeNode) bool {
	var findDepth func(root *TreeNode) int
	findDepth = func(root *TreeNode) int {
		if root == nil {
			return 0
		}
		left := findDepth(root.Left)
		right := findDepth(root.Right)
		if left == -1 || right == -1 || left-right < -1 || left-right > 1 {
			return -1
		}
		return max(left, right) + 1
	}
	if findDepth(root) == -1 {
		return false
	}
	return true
}
