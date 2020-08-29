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
    
    vector<vector<int>> zigzag_bfs(TreeNode *node){
        vector<vector<int>> ret;
        deque<TreeNode*> dq;
        dq.push_back(node);
        bool left_to_right=true;
        while(!dq.empty()){
            vector<int> pans;
            vector<TreeNode*> v;
            while(!dq.empty()){
                if (left_to_right){
                    v.push_back(dq.front());
                    pans.push_back(dq.front()->val);
                    dq.pop_front();
                }  
                else{
                    v.push_back(dq.front());
                    pans.push_back(dq.front()->val);
                    dq.pop_front();
                }
            }
            ret.push_back(pans);
            for (int i=v.size()-1; i>=0; i--){
                if (left_to_right){
                    if (v[i] -> right !=NULL)
                        dq.push_back(v[i]->right);
                    if (v[i] ->left !=NULL)
                        dq.push_back(v[i]->left);
                }
                else{
                    if (v[i] ->left !=NULL)
                        dq.push_back(v[i]->left);
                    if (v[i] -> right !=NULL)
                        dq.push_back(v[i]->right);
                }
            }
            left_to_right = !left_to_right;
        }
        return ret;   
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root != NULL)
            return zigzag_bfs(root);
        else
            return ans;
    }
};
