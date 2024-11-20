package ac

func postorderTraversal(root *TreeNode) []int {
	var res []int
	var dfs func(root *TreeNode)
	dfs = func(root *TreeNode) {
		if root == nil {
			return
		}
		dfs(root.Left)
		dfs(root.Right)
		res = append(res, root.Val)
	}
	dfs(root)
	return res
}
