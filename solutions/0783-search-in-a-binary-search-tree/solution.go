/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func searchBST(root *TreeNode, val int) *TreeNode {
    for root.Val != val {
        if root.Val < val {
            root = root.Right
        } else if root.Val > val {
            root = root.Left
        }
        if root == nil {
            return root
        }
    }
    return root
}
