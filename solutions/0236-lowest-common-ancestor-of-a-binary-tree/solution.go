/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
    // Base Case 1: If we hit a leaf boundary, return nil
    // Base Case 2: If we match either p or q, we found one of our targets! 
    // Return this node back up to the caller to flag its existence.
    if root == nil || root == p || root == q {
        return root
    }

    // Divide: Recurse down both subtrees simultaneously
    leftResult := lowestCommonAncestor(root.Left, p, q)
    rightResult := lowestCommonAncestor(root.Right, p, q)

    // Conquer: Analyze what bubbled up from our children
    
    // Condition A: One target was found on the left, and the other on the right.
    // This confirms the current root is the Lowest Common Ancestor.
    if leftResult != nil && rightResult != nil {
        return root
    }

    // Condition B: Both targets are down the left path, or the left path has the answer.
    if leftResult != nil {
        return leftResult
    }

    // Condition C: Both targets are down the right path, or the right path has the answer.
    return rightResult
}
