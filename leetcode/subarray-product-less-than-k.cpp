class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n= nums.size();
        int left =-1;
        int right = 0;
        int ans = 0;
        int total = nums[0];
        if (k <=1) return 0;
        while(left <= right){
            if (total < k){
                ans += right-left;
                right++;
                if (right >= n) break;
                total *= nums[right];
            } else{
                left++;
                total /= nums[left];
            }
            
        }
        return ans;
        
    }
};