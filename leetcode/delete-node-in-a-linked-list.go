/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func deleteNode(node *ListNode) {
    bf := node
    cur := node.Next
    bf.Val = cur.Val
    bf.Next = cur.Next
}