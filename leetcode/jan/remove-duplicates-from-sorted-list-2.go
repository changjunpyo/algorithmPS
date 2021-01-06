/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func deleteDuplicates(head *ListNode) *ListNode {
    if ( head == nil || head.Next == nil){
        return head
    }
    node := &ListNode{-1, head}
    bf := node
    cur := node.Next
    for cur != nil && cur.Next != nil {
        for cur.Val == cur.Next.Val{
            cur = cur.Next
            if (cur.Next == nil || cur.Val != cur.Next.Val){
                cur = cur.Next
                break;
            }
        }
        if (cur != nil && cur.Next != nil && cur.Val == cur.Next.Val){
            continue
        }
        bf.Next = cur
        bf = bf.Next
        if (bf == nil){
            break
        }
        cur = cur.Next
    }
    return node.Next
    
}