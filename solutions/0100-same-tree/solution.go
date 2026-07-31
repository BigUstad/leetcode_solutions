/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
import aq "github.com/emirpasic/gods/queues/arrayqueue"

func bfsHelper(root *TreeNode) string {
    var bfsOutput string
    queue := aq.New()
    queue.Enqueue(root)
    for !queue.Empty() {
        curEle, _ := queue.Dequeue()
        cur := curEle.(*TreeNode)
        if cur.Val == 10001 {
            bfsOutput = strings.Join([]string{bfsOutput, "nullptr"}, ",")
            curEle = nil // for gc
            continue
        }
        bfsOutput = strings.Join([]string{bfsOutput, strconv.Itoa(cur.Val)}, ",")
        if cur.Left != nil {
            queue.Enqueue(cur.Left)
        } else {
            queue.Enqueue(&TreeNode{
                Val: 10001, Left: nil, Right: nil,
            })
        }
        if cur.Right != nil {
            queue.Enqueue(cur.Right)
        } else {
            queue.Enqueue(&TreeNode{
                Val: 10001, Left: nil, Right: nil,
            })
        }
    }
    return bfsOutput
}

func isSameTree(p *TreeNode, q *TreeNode) bool {
    if p == nil && q == nil {
        return true
    }
    if p == nil || q == nil {
        return false
    }
    pOutput := bfsHelper(p)
    qOutput := bfsHelper(q)
    return pOutput == qOutput
}

