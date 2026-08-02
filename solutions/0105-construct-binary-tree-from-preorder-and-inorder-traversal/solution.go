/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 
func buildInOrderMap(inordermap map[int]int, inorder []int) {
	for i, n := range inorder {
		inordermap[n] = i
	}
}

func buildTree(preorder []int, inorder []int) *TreeNode {
    var inordermap map[int]int
	var root *TreeNode
	var buildTreeHelper func(l, r int) *TreeNode
	if len(preorder) == 0 || len(inorder) == 0 {
		return root
	}
	inordermap = make(map[int]int)
	buildInOrderMap(inordermap, inorder)
	// fmt.Println(len(inordermap))
	preorderIdx := 0
	buildTreeHelper = func(l, r int) *TreeNode {
        // End case for recursion
		if l > r || preorderIdx == len(preorder) { return nil }
        // Get the root element pre-order (root -> left -> right)
        // Find the root from inorder indices map
        // Every node after index 0 encountered in preorder is a root of a subtree. 
        //      Either it is a root node of a subtree
        //      Or it is a leaf node with no children
		p := preorder[preorderIdx]
		preorderIdx++
		cur := &TreeNode{Val: p, Left: nil, Right: nil}
		if root == nil {
			// fmt.Print("Root is: ")
			// fmt.Println(p)
			root = cur
		}
        // For this root, recursively build its left subtree by taking the indices from inorder
		cur.Left = buildTreeHelper(l, inordermap[p] - 1)
        // For this root, recursively build its right subtree by taking the indices from inorder
		cur.Right = buildTreeHelper(inordermap[p] + 1, r)
		return cur
	}
	buildTreeHelper(0, len(preorder)-1)
    inordermap = nil
	return root
}

