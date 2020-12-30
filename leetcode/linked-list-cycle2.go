/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func detectCycle(head *ListNode) *ListNode {
    if (head == nil){
        return nil
    }
    fastRunner := head
    slowRunner := head
    
    isCycle := false
    for ;fastRunner != nil;{
        if (fastRunner == nil || fastRunner.Next == nil){
            isCycle = false
            break
        }
        slowRunner = slowRunner.Next
        fastRunner = fastRunner.Next.Next
        if (slowRunner == fastRunner){
            isCycle = true
            break;
        }
    }
    if(!isCycle){
        return nil
    }
    
    reRunner := head
    
    for ; reRunner != slowRunner;{
        reRunner = reRunner.Next
        slowRunner = slowRunner.Next
    }
    return reRunner
    
}