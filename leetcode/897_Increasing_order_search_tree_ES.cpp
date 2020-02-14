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
    TreeNode *cur;
    void inorder(TreeNode* node){
    if (node ->left != NULL)
      inorder(node->left);
    node ->left =NULL;
    cur->right = node;
    cur = cur->right;
    if (node ->right != NULL)
        inorder(node->right);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode ans(0);
        cur = &ans;
        inorder(root);
        return ans.right;
    }
};