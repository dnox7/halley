package ac

import "slices"

func buildTree(preorder []int, inorder []int) *TreeNode {
	var build func([]int, []int) *TreeNode
	build = func(preorder []int, inorder []int) *TreeNode {
		if len(preorder) == 0 {
			return nil
		}
		root := &TreeNode{Val: preorder[0]}
		rootIdx := slices.Index(inorder, root.Val)
		root.Left = build(preorder[1:rootIdx+1], inorder[:rootIdx])
		root.Right = build(preorder[rootIdx+1:], inorder[rootIdx+1:])
		return root
	}
	return build(preorder, inorder)
}
