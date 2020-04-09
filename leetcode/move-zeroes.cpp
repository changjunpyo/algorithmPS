class Solution {
public:
    void swap(vector<int>& nums , int i,int j){
            int c = nums[i];
            nums[i] = nums[j];
            nums[j] = c;
    }
    void moveZeroes(vector<int>& nums) {
        int idx = 0;
        for (int i=0; i<nums.size(); i++){
            if (nums[i] !=0){
                swap(nums,idx++, i);
            }
        }
        
    }
};