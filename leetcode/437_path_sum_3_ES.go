/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
var ans int 
var SUM int
func dfs(node *TreeNode, cur int){
    if cur+ (node.Val) == SUM {
        ans++
    }
    
    if node.Left != nil{
        dfs(node.Left, cur+node.Val)
    }
    
    if node.Right != nil{
        dfs(node.Right, cur+node.Val)
    }   
}
func walk(node *TreeNode){
    if node.Left !=nil{
        walk(node.Left)
    }
    dfs(node, 0)
    if node.Right !=nil{
        walk(node.Right)
    }
}
func pathSum(root *TreeNode, sum int) int {
    ans = 0
    SUM = sum
    if root ==nil{
        return 0
    }
    walk(root)
    return ans
}