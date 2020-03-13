class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        if (nums.size() <3)
            return 0;
        int ans =0;
        sort(nums.begin(), nums.end());
        for (int i=0; i<nums.size()-2; i++){
            int sum = target- nums[i];
            int left = i+1;
            int right = nums.size()-1;
            while(left != right){
                if (sum > nums[left] + nums[right]){
                    ans += (right - left);
                    left++;
                }
                else{
                    right--;
                }
            }
        }
        return ans;
    }
};