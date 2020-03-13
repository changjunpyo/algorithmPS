class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        int loc =0;
        for (int i=0; i<nums.size(); i++){
            loc += nums[i];
            ans = max(loc, ans);
            loc = max(0, loc);
        }
        return ans;
    }
};