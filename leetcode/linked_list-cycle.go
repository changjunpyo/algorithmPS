/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func hasCycle(head *ListNode) bool {
    if (head == nil){
        return false
    }
    fastRunner := head.Next
    slowRunner := head
    
    for ;fastRunner != slowRunner;{
        if (fastRunner == nil || fastRunner.Next == nil){
            return false
        }
        fastRunner = fastRunner.Next.Next
        slowRunner = slowRunner.Next
        
    }
    return true;
}