/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Neighbors []*Node
 * }
 */

func cloneGraph(node *Node) *Node {
    if node == nil { return nil }
    // Serves as visited as well
    oldToNew := make(map[*Node]*Node)
    var dfsHelper func(*Node)*Node
    dfsHelper = func(node *Node) *Node {
        if node == nil { return nil }
        if n, exists := oldToNew[node]; exists {
            return n
        }
        cloneNode := &Node {
            Val: node.Val,
            Neighbors: nil,
        }
        oldToNew[node] = cloneNode
        for _, nei := range node.Neighbors {
            // NOTE: Recursive call is made here.
            // DFS & oldToNew as visited marker
            cloneNode.Neighbors = append(cloneNode.Neighbors, dfsHelper(nei))
        }
        return cloneNode
    }
    return dfsHelper(node)    
}
