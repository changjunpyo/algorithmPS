/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:    
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr && t2 == nullptr) return nullptr;
        
        if (t1 == nullptr){
            return t2;    
        } else if (t2 == nullptr){
            return t1;
        } else {
            TreeNode *root = new TreeNode(t1->val+ t2->val);
            
            if (t1 ->left !=nullptr || t2 ->left != nullptr){
                root->left = mergeTrees(t1->left, t2->left);
            } 
            if (t1 ->right !=nullptr || t2 ->right != nullptr){
                root->right = mergeTrees(t1->right, t2->right);
            }
            return root;
        }
    }
};
