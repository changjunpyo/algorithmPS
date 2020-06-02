/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func invert(node *TreeNode) {
    left := node.Left
    right := node.Right
    
    if left != nil{
        invert(left)
    }
    if right != nil {
        invert(right)
    }
    
    node.Left = right
    node.Right = left
}

func invertTree(root *TreeNode) *TreeNode {
    if root != nil{
        invert(root)
    }
    
    return root
    
}