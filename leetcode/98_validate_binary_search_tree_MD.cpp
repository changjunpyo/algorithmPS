/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> stack;
    long long  inorder = LLONG_MIN;
    
    
    bool isValidBST(TreeNode* root) {
        while (!stack.empty() || root !=NULL){
            while(root != NULL){
                stack.push_back(root);
                root = root-> left;
            }
            root = stack.back();
            stack.pop_back();
            if (root->val <= inorder) return false;
            inorder = root->val;
            root = root ->right;
        }
        return true;
    }
};
