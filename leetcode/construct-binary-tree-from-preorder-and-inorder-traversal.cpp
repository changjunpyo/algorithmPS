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
    unordered_map<int, int> m;
    int helper(vector<int> &preorder, int idx, TreeNode *node, int left, int right){
        if (idx >= preorder.size()) return idx;
        if ( left <= m[preorder[idx]] && m[preorder[idx]] < m[node->val]){
            node -> left = new TreeNode(preorder[idx++]);
            idx = helper(preorder, idx, node->left, left,m[node->val]);
        }
        if (idx < preorder.size() && right >= m[preorder[idx]] &&m[preorder[idx]] > m[node->val]){
           node -> right = new TreeNode(preorder[idx++]);
           idx = helper(preorder, idx, node->right, m[node->val]+1 ,right); 
        }
        
        return idx;
    }
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        for (int i=0; i<inorder.size(); i++){
            m.insert({inorder[i],i});
        }
        if (preorder.size() == 0) return NULL;
         TreeNode *root = new TreeNode(preorder[0]);
         helper(preorder, 1, root, 0, preorder.size()-1);
        return root;
    }   
};