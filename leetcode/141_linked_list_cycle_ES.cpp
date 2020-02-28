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
    bool hasCycle(ListNode *head) {
        ListNode *node = head;
        ListNode *node2= head;
        
        while(node != NULL && node2 != NULL && node2->next != NULL){
            node = node->next;
            node2 = node2->next -> next;
            
            if (node == node2)
                return true;
        }
        return false;
    }
};