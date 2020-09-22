/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        Node *cur;
        Node *before;
        Node *n =  new Node(insertVal);
        if (head == nullptr){
            n->next = n;
            head = n;
            return head;
        } 
        if (head->next == head){
            head ->next = n;
            n-> next = head;
            return head;
        }
        
        cur = head->next;
        before = head;
        while (cur != head){
            if (cur->val < before->val){
                if (cur->val >= insertVal || before->val <= insertVal){
                    n->next = cur;
                    before->next = n;
                    return head;
                }
            }
            if (cur->val >= insertVal && before->val <= insertVal){
                n->next = cur;
                before->next = n;
                return head;
            }
            before =  cur;
            cur = cur->next;
            
        }
        before->next = n;
        n->next = head;
        return head;
    }
};