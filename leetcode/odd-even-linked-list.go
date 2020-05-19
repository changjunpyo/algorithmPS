/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func oddEvenList(head *ListNode) *ListNode {
    if head == nil {return head}
    odd, even := head, head.Next
    evenHead := even
    for ;odd != nil&& even !=nil;{
        odd.Next = even.Next
        if (odd.Next == nil){break}
        odd = odd.Next
        even.Next = odd.Next
        even = even.Next
    }
    odd.Next = evenHead
    
    return head
    
}