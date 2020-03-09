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
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
       ListNode *n1 = l1;
       ListNode *n2 = l2;
        ListNode ans(0);
       ListNode *node = &ans;
        while (n1 != NULL && n2 !=NULL){
            if (n1 ->val <= n2->val){
                node->next = new ListNode(n1->val);
                node = node->next;
                cout << node->val;
                n1 = n1->next;
            }
            else{
                node->next = new ListNode(n2->val);
                node = node->next;
                cout << node->val;
                n2 = n2->next;
            }
        }
        
        while (n1 ==NULL &&n2 !=NULL){
                node ->next = new ListNode(n2->val);
                node = node->next;
                n2 = n2->next;
        }
        while(n1 !=NULL &&n2 ==NULL){
                node ->next = new ListNode(n1->val);
                node = node->next;
                n1 = n1->next;
        }
    return ans.next;
    }
};