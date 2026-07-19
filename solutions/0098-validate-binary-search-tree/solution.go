/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func checkValidBST(root, low, high *TreeNode) bool {
    if root == nil {
        return true
    }
    // fmt.Print(root.Val)
    // fmt.Print("  ")
    if low != nil {
        // fmt.Print(", low: ")
        // fmt.Print(low.Val)
    }
    if high != nil {
        // fmt.Print(", high: ")
        // fmt.Print(high.Val)
    }
    if (low != nil && root.Val <= low.Val) ||
        (high != nil && root.Val >= high.Val) {
        return false
    }
    // fmt.Println()

    return checkValidBST(root.Left, low, root) &&
            checkValidBST(root.Right, root, high)
}

func isValidBST(root *TreeNode) bool {
    if root == nil ||
        (root.Left == nil && root.Right == nil) {
        return true
    }
    return checkValidBST(root, nil, nil)
}
