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
    ListNode* middleNode(ListNode* head) {
        ListNode* node_slow = head;
        ListNode* node_fast;
        if (head != NULL)
            node_fast = head->next;
        while (node_fast != NULL){
            node_slow = node_slow->next;
            node_fast = node_fast->next;
            if (node_slow ==NULL || node_fast == NULL)
                break;
            node_fast = node_fast->next;
        }
        return node_slow;
    }
};