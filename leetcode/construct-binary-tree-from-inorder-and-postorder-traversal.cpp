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
    unordered_map<int,int> m;
    int pos;
    TreeNode* build(vector<int>& inorder,vector<int> &postorder, int s, int e){
        TreeNode *node = nullptr;
        if (s <= e){
            int i = m[postorder[pos]];
            node = new TreeNode(postorder[pos--]);
            node ->right = build(inorder, postorder, i+1, e);
            node ->left = build(inorder, postorder, s,i-1);
        }
        return node;
        
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i=0; i<inorder.size(); i++)
            m.insert({inorder[i], i});
        pos = postorder.size()-1;
        return build(inorder,postorder,0, inorder.size()-1);
    }
};