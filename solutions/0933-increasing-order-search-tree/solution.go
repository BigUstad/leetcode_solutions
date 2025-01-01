/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
import lls "github.com/emirpasic/gods/stacks/linkedliststack"

func inOrderHelper(root *TreeNode) ([]*TreeNode) {
    var sNodesRet []*TreeNode
    if root == nil {
        return nil
    }
    if root.Left == nil && root.Right == nil {
        sNodesRet = append(sNodesRet, root)
        return sNodesRet
    }
    stack := lls.New()
    cur := root
    stack.Push(*cur)
    cur = root.Left
    for cur != nil || !stack.Empty() {
        for cur != nil {
            stack.Push(*cur)
            cur = cur.Left
        }
        // Process
        node, _ := stack.Pop()
        tnode := node.(TreeNode)
        sNodesRet = append(sNodesRet, &tnode)
        cur = node.(TreeNode).Right
    }
    return sNodesRet
}

func increasingBST(root *TreeNode) *TreeNode {
    inOrderNodes := inOrderHelper(root)
    var prev *TreeNode;
    if len(inOrderNodes) <= 0 {
        return nil
    }
    if len(inOrderNodes) == 1 {
        return inOrderNodes[0]
    }
    newRoot := inOrderNodes[0]
    for _, n := range inOrderNodes {
        n.Left = nil
        n.Right = nil
        if prev != nil {
            prev.Right = n
        }
        prev = n
    }

    return newRoot
}
