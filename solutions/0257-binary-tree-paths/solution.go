/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

import lls "github.com/emirpasic/gods/stacks/linkedliststack"

func binaryTreePaths(root *TreeNode) []string {
    var res []string
    if root == nil { return res }
    if root.Left == nil && root.Right == nil { return []string{strconv.Itoa(root.Val)} }
    var postOrderHelper func(*TreeNode)
    postOrderHelper = func(root *TreeNode) {
        // var ssb []strings.Builder
        var sb strings.Builder
        sb.WriteString(strconv.Itoa(root.Val))
        s := lls.New()
        ps := lls.New()
        s.Push(root)
        ps.Push(&sb)
        for !s.Empty() {
            curEle, _ := s.Pop()
            cur := curEle.(*TreeNode)
            psEle, _ := ps.Pop()
            var psb strings.Builder
            psb.WriteString(psEle.(*strings.Builder).String())
            if cur.Left != nil {
                s.Push(cur.Left)
                var psb strings.Builder
                psb.WriteString(psEle.(*strings.Builder).String())
                psb.WriteString("->")
                psb.WriteString(strconv.Itoa(cur.Left.Val))
                ps.Push(&psb)
            }
            if cur.Right != nil {
                s.Push(cur.Right)
                var psb strings.Builder
                psb.WriteString(psEle.(*strings.Builder).String())
                psb.WriteString("->")
                psb.WriteString(strconv.Itoa(cur.Right.Val))
                ps.Push(&psb)
            }

            if cur.Left == nil && cur.Right == nil {
                res = append(res, psb.String())
                // fmt.Println(len(res))
                // fmt.Println(res)
                // fmt.Println("*******")
            }
        }
    }
    postOrderHelper(root)
    return res
}
