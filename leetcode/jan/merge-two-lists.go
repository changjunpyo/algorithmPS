/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
    if (l1 == nil){
        return l2
    } else if (l2 == nil){
        return l1
    }
    l3 := &ListNode{-1, nil}
    node := l3
    for l1 != nil && l2 != nil{
        if (l1.Val <= l2.Val){
            node.Next = l1
            l1 = l1.Next
        } else{
           node.Next = l2
            l2 = l2.Next
        }
        node = node.Next
    }
    if (l1 == nil){
        node.Next = l2
    } else{
        node.Next = l1
    }
    
    return l3.Next
}