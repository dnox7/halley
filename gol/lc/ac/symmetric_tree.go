package ac

func isSymmetric(root *TreeNode) bool {
	var check func(*TreeNode, *TreeNode) bool
	check = func(left *TreeNode, right *TreeNode) bool {
		if left == nil && right == nil {
			return true
		}
		if left == nil || right == nil {
			return false
		}
		return left.Val == right.Val && check(left.Left, right.Right) && check(left.Right, right.Left)
	}
	return check(root.Left, root.Right)
}
