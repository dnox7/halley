package ac

import (
	"slices"
)

func levelOrderBottom(root *TreeNode) [][]int {
	var res [][]int
	if root == nil {
		return res
	}
	q := []*TreeNode{root}
	for len(q) > 0 {
		levelSize := len(q)
		var subarr []int
		for i := 0; i < levelSize; i++ {
			curr := q[0]
			q = q[1:]
			subarr = append(subarr, curr.Val)
			if curr.Left != nil {
				q = append(q, curr.Left)
			}
			if curr.Right != nil {
				q = append(q, curr.Right)
			}
		}
		res = append(res, subarr)
	}
	slices.Reverse(res)
	return res
}
