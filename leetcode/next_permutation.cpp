class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int idx = -1;
        for(int i=0; i<nums.size()-1; i++){
            if (nums[i] < nums[i+1]) idx = i;
        }
        if (idx == -1) {reverse(nums.begin(), nums.end());return;}
        
        for (int i=nums.size()-1; i> idx; i--){
            if (nums[i] > nums[idx]){
                int temp = nums[i];
                nums[i] = nums[idx];
                nums[idx] = temp;
                break;
            }
        }
        
        reverse(nums.begin()+idx+1, nums.end());
        
    }
};