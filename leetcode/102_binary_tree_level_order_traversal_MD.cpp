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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if (root ==NULL) return ans;
        q.push(root);
        
        while(!q.empty()){
            int sz= q.size();
            vector<int> p(sz);
            for (int i=0; i<sz; i++){
                TreeNode *x = q.front();
                q.pop();
                p[i] = x->val;
                if (x->left !=NULL) q.push(x->left);
                if (x->right !=NULL) q.push(x->right);
            }
            ans.push_back(p);
        }
        return ans;
    }
};