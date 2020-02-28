/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int size_a=0;
        int size_b=0;
        ListNode *node=headA;
        ListNode *node2=headB;
        
        while(node != NULL){
            size_a++;
            node = node ->next;
        }
         while(node2 != NULL){
            size_b++;
            node2 = node2 ->next;
        }
        
        int diff = abs(size_a-size_b);
        node = size_a > size_b ? headA : headB;
        node2= size_a > size_b ? headB : headA;

        for (int i=0; i<diff; i++)
            node = node ->next;
        
        while(node !=NULL && node2 !=NULL){
            if (node == node2)
                return node;
            node = node ->next;
            node2 = node2 ->next;
        }
        return NULL;
        
    }
};