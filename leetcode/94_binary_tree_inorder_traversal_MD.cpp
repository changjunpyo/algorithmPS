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
    // recursive
    void inorder(vector<int> &traversal, TreeNode* node){
        if (node ->left !=NULL)
            inorder(traversal,node ->left);
        traversal.push_back(node->val);
        if (node ->right !=NULL)
            inorder(traversal,node ->right);
        return;        
    }
    
    

    vector<int> inorderTraversal(TreeNode* root) {
            vector<int> v;
            vector <TreeNode*> stack;
    //iterative
            unordered_set<TreeNode*> ht;
            if (root != NULL)
                stack.push_back(root);
            while(!stack.empty()){
                TreeNode* node = stack.back();
                stack.pop_back();
                if (ht.find(node) != ht.end()){
                    v.push_back(node->val);
                    continue;
                }
                if (node ->right !=NULL)
                     stack.push_back(node->right);
                stack.push_back(node);
                if (node ->left !=NULL)
                     stack.push_back(node->left);
                ht.insert(node);
            }
        return v;
    }
};