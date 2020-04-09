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
    int dfs(TreeNode *node, int current){
        int right_dep = current;
        int left_dep = current;
        if (node ->left != NULL){
            left_dep = dfs(node->left,current+1);
        }
        if (node ->right != NULL){
            right_dep = dfs(node->right,current+1);
        }
        return max(left_dep, right_dep);
    }
    
    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        return dfs(root,1);
    }
};