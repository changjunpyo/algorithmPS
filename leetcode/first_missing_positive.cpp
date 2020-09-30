class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        vector<int> x(nums.size(), -1);
        for(int i=0; i<nums.size(); i++){
            if (nums[i] > 0 && nums[i] <= x.size()){
                x[nums[i]-1] = 1;
            }
        }
        for (int i=0; i<x.size(); i++)
            if (x[i] == -1) return i+1;
        return x.size()+1;
    }
};