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
    void inorder(TreeNode* node, vector<int> &v){
        if (node->left != nullptr)
            inorder(node->left,v);
        v.push_back(node->val);
        if (node ->right!=nullptr)
            inorder(node->right,v);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> a;
        vector<int> b;
        if (root1 != nullptr) inorder(root1, a);
        if (root2 != nullptr) inorder(root2, b);
        int r1_size = a.size();
        int r2_size = b.size();
        vector<int> c;
        int x =0, y=0;
        while (x < r1_size && y <r2_size){
            if (a[x]< b[y]) c.push_back(a[x++]);
            else c.push_back(b[y++]);
        }
        while (x < r1_size){
            c.push_back(a[x++]);
        }
        while (y < r2_size){
            c.push_back(b[y++]);
        }
        
        return c;
    }
};