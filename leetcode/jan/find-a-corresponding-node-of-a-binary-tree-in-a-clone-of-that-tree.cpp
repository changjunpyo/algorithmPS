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
    TreeNode* allSearch(TreeNode* node, TreeNode* target){
        if (node->val == target->val){
            return node;
        }
        if (node->left != NULL){
            TreeNode* left = allSearch(node->left, target);
            if (left != NULL) return left;
        } 
        if (node->right != NULL){
            TreeNode* right = allSearch(node->right, target);
            if (right != NULL) return right;
        }
        return NULL;
        
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        return allSearch(cloned, target);
    }
};