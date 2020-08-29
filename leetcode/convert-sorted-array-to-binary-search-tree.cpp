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
    
    TreeNode* makeBST(int s, int e, vector<int> &nums){
        if (s==e) return new TreeNode(nums[s]);
        if (s > e) return NULL;
        int m = (s+e)/2;
        TreeNode *node = new TreeNode(nums[m]);
        node->left = makeBST(s, m-1, nums);
        node->right = makeBST(m+1, e, nums);
        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return makeBST(0, nums.size()-1, nums);
    }
};
