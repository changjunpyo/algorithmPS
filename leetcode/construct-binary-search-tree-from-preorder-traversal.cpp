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
    
    TreeNode* makebst(vector<int>& preorder, int start, int end){
        TreeNode * node = nullptr;
        if (start <= end){
            int i= start+1;
            for (i=start+1; i<= end; i++){
                if (preorder[start] < preorder[i])
                    break;
            }
            node = new TreeNode(preorder[start]);
            node-> left =makebst(preorder, start+1, i-1);
            node-> right= makebst(preorder,i,end);
        }
        return node;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        return makebst(preorder, 0, preorder.size()-1);
    }
};