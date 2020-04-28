class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i=0;
        vector<bool> dp(nums.size(), false);
        dp[nums.size()-1] =true; 
        for (int i=nums.size()-2; i>=0; i--){
            if (i+nums[i] >= nums.size()-1){
                dp[i]= true;
            }
            if (dp[i] || dp[i+nums[i]] ){
                dp[i] = true;
                for (int j=i+1; j<nums.size(); j++){
                    if (dp[j]) break;
                    else
                        dp[j] = true;
                }
            }
        }
        return dp[0];
    }
};