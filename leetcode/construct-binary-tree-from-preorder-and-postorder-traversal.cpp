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
    TreeNode* build(vector<int>& pre, vector<int>& post, int pre_s, int pre_e, int post_s, int post_e){
        TreeNode *node = nullptr;
        if (pre_s > pre_e) return nullptr;
        node = new TreeNode(pre[pre_s]);
        if (pre_s < pre_e){
            
            int split_size_a = post_e - m[pre[pre_s+1]];
            int split_size_b = m[pre[pre_s+1]]- post_s +2;
            node ->left = build(pre, post, pre_s+1, pre_s+split_size_b-1, post_s, post_e-split_size_a);
            node ->right = build(pre, post,pre_s+split_size_b,pre_e,post_e-split_size_a+1, post_e-1);
        }
        
        return node;

        
    }
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        for (int i=0; i<post.size(); i++)
            m.insert({post[i],i});
        return build(pre,post, 0,post.size()-1, 0, pre.size()-1); 
    }
};