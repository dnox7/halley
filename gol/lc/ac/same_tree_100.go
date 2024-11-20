package ac

func isSameTree(p *TreeNode, q *TreeNode) bool {
	if p == nil && q == nil {
		return true
	}
	if p != nil && q != nil {
		return p.Val == q.Val && isSameTree(p.Right, q.Right) && isSameTree(p.Left, q.Left)
	}
	return false
}
